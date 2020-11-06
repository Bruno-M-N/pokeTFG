// Dynamic QML Object Creation from JavaScript
// https://doc.qt.io/qt-5/qtqml-javascript-dynamicobjectcreation.html

// QML Advanced Tutorial 2 - Populating the Game Canvas
// https://doc.qt.io/qt-5/qtquick-tutorials-samegame-samegame2-example.html

//import QENUMNodeType 1.0

var arrayNodes = []; //create a new empty array
var arrayAdjacencyList = []; //create a new empty array
var component;

//function func() {
//    cppPageManagement.loadArenaNodes("original3x3.tfgarena");
//}

function loadFieldNodesAndAdjacencyList() {
    cppPageManagement.loadArenaNodesAndAdjacencyList("original3x3.tfgarena");
}

function displayNodesAndEdges() {
    console.log("displayNodesAndEdges");

    loadFieldNodesAndAdjacencyList();
    //cppPageManagement.loadArenaNodes("original3x3.tfgarena");
    console.log(" ");

    //Delete blocks from previous game
    var maxIndex = arrayNodes.length;
    for (var i = 0; i < maxIndex; ++i) {
        if (arrayNodes[i] !== null)
            arrayNodes[i].destroy();
    }

    var maxIndexAdjacencyList = arrayAdjacencyList.length;
    for (i = 0; i < maxIndex; ++i) {
        if (arrayAdjacencyList[i] !== null)
            arrayAdjacencyList[i].destroy();
    }

    //Initialize arrayNodes
    arrayNodes = cppPageManagement.getVectorNodes();
    maxIndex = arrayNodes.length;

    //Initialize arrayAdjacencyList
    arrayAdjacencyList = cppPageManagement.getAdjacencyList();
    maxIndexAdjacencyList = arrayAdjacencyList.length;

//    //console.log("maxIndex" + maxIndexAdjacencyList);
    for (i = 0; i < maxIndexAdjacencyList; ++i) {
//        //console.log( "arrayAdjacencyList[" + i + "]: " + arrayAdjacencyList[i]);
        createDynamicEdges(arrayNodes, i, arrayAdjacencyList[i]);
//        //console.log("createDynamicEdges_____________");

    }
    


//    console.log("arrayNodes-------------");
//    console.log(arrayNodes);
//    console.log("arrayNodes_____________");
    console.log("_____________");
    for (i = 0; i < maxIndex; ++i) {
//        //arrayNodes[i] = null;
        var memberNodeType = arrayNodes[i].getNodeType();
        console.log( i + ": " + arrayNodes[i] +
                    " NodeType: " + memberNodeType);

        createDynamicQMLNode(arrayNodes[i], memberNodeType);
//        console.log("createDynamicQMLNodes_____________");
    }
}

function createDynamicQMLNode(node, nodeType) {
    //var nodeType = 0
    //nodeType = node.getNodeType()
    console.log("NodeType.Player1Goal___________" + NodeType.Player1Goal);
    console.log("NodeType.Player2Goal___________" + NodeType.Player2Goal);
    console.log("NodeType.Player1EntryPoint_____" + NodeType.Player1EntryPoint);
    console.log("NodeType.Player1EntryPoint_____" + NodeType.Player2EntryPoint);
    console.log("NodeType.Normal________________" + NodeType.Normal);
    console.log(" nodeType    ________________" + nodeType);

    if (nodeType === NodeType.Player1Goal)
    {   //if (component == null)
            component = Qt.createComponent("NodeGoal.qml");
//        node->setProperty("circleColor", "#ffffff");
//        node->setProperty("insideCircleAndTextColor", "#000000");
//        node->setProperty("rotation", 180);
    }else if (nodeType === NodeType.Player2Goal)
    {   //if (component == null)
            component = Qt.createComponent("NodeGoal.qml");
    }else if (nodeType === NodeType.Player1EntryPoint)
    {   //if (component == null)
            component = Qt.createComponent("NodeEntryPoint.qml");
//        node->setProperty("circleColor", "#ffffff");
//        node->setProperty("insideCircleAndTextColor", "#000000");
//        node->setProperty("rotation", 180);
    }else if (nodeType === NodeType.Player2EntryPoint)
    {   //if (component == null)
            component = Qt.createComponent("NodeEntryPoint.qml");
//        //node->setProperty("color", "#000000");
    }else //if (nodeType === NodeType.Normal)
    {   //if (component == null)
            component = Qt.createComponent("NodeNormal.qml");
//        node->setProperty("circleColor", "#000000");
//        node->setProperty("borderColor", "#2d2d2d");
    }

    // Note that if NodeX.qml was not a local file, component.status would be
    // Loading and we should wait for the component's statusChanged() signal to
    // know when the file is downloaded and ready before calling createObject().
    if (component.status === Component.Ready) {
        var dynamicObject = component.createObject(field3x3);
        if (dynamicObject === null) {
            console.log("Error creating node");
            console.log(component.errorString());
            return false;
        }
        dynamicObject.x = node.getX() - dynamicObject.radius;
        dynamicObject.y = node.getY() - dynamicObject.radius;
//        dynamicObject.width = blockSize;
//        dynamicObject.height = blockSize;

        if (nodeType == NodeType.Player1Goal)
        {   dynamicObject.circleColor = "#ffffff";
            dynamicObject.insideCircleAndTextColor = "#000000";
            dynamicObject.rotation = 180;
        }else if (nodeType == NodeType.Player2Goal)
        {   //
        }else if (nodeType == NodeType.Player1EntryPoint)
        {   dynamicObject.circleColor = "#ffffff";
            dynamicObject.innerCircleAndTextColor = "#000000";
            dynamicObject.rotation = 180;
        }else if (nodeType == NodeType.Player2EntryPoint)
        {    dynamicObject.circleColor = "#000000";
        }else if (nodeType == NodeType.Normal)
        {    dynamicObject.circleColor = "#000000";
             dynamicObject.borderColor = "#2d2d2d";
        }else //if (nodeType === NodeType.Normal)
        {    dynamicObject.circleColor = "#040400";
             dynamicObject.borderColor = "#2dffff";
        }

        node = dynamicObject;
        return true;
    } else {
        console.log("Error loading node component");
        console.log(component.errorString());
        return false;
    }
}

function createDynamicEdges(nodes, index, localAdjacencyList) {
    //var startX = nodes(index).x;
    //var startY = nodes(index).y;

    var maxIndex = localAdjacencyList.length;
    var indexNodeExtreme = 0;
    for (var i = 0; i < maxIndex; ++i)
    {   indexNodeExtreme = localAdjacencyList[i];
        console.log( "localAdjacencyList[" + i + "]: " + localAdjacencyList[i]);
        createDynamicQMLEdge(localAdjacencyList[i],
                             nodes[index], nodes[indexNodeExtreme]);
    }
}




function createDynamicQMLEdge(edge, node1, node2) {
    component = Qt.createComponent("NodeConection.qml");

    // Note that if NodeX.qml was not a local file, component.status would be
    // Loading and we should wait for the component's statusChanged() signal to
    // know when the file is downloaded and ready before calling createObject().
    if (component.status === Component.Ready) {
        var dynamicObject = component.createObject(field3x3);
        if (dynamicObject === null) {
            console.log("Error creating node");
            console.log(component.errorString());
            return false;
        }
        dynamicObject.x1 = node1.getX();
        dynamicObject.y1 = node1.getY();
        dynamicObject.x2 = node2.getX();
        dynamicObject.y2 = node2.getY();
        dynamicObject.color = "#000000";

        edge = dynamicObject;
        return true;
    } else {
        console.log("Error loading node component");
        console.log(component.errorString());
        return false;
    }
}
