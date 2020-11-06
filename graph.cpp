#include "graph.h"

#define FOLDINGSTART {
//Graph::Graph(QQmlApplicationEngine *engineSetup, QQuickItem *rootSetup,
//             QObject *parent) : QObject(parent)
//{
//    //radius = 5;
//    maxNumberOfEntryPointsPlayer1 = 2;
//    maxNumberOfEntryPointsPlayer2 = 2;

//    //initialFieldWidth = 1110;
//    //initialFieldHeight = 1540;

//    //m_applicationWindowWidth = 1110;
//    //m_applicationWindowHeight = 1540;

//    //engine = engineSetup;
//    //root = rootSetup;

//    //Create grid
//    // 0 - 1 - 2 - 3 - 4 - 5 - 6
//    // | \                   / |
//    // 7  8                 9 10
//    // |   \               /   |
//    // 11    12 - 13 - 14     15
//    // |   /               \   |
//    // 16 17               18 19
//    // | /                   \ |
//    // 20 - 21-22-23-24- 25 - 26

//    createNode(0, 18*5, 91*5, NodeType::Normal);
//    createNode(1, 48.5*5, 91*5, NodeType::Player1EntryPoint);
//    createNode(2, 79*5, 91*5, NodeType::Normal);
//    createNode(3, 109.5*5, 91*5, NodeType::Player1Goal);
//    createNode(4, 140*5, 91*5, NodeType::Normal);
//    createNode(5, 170.5*5, 91*5, NodeType::Normal);
//    createNode(6, 201*5, 91*5, NodeType::Player1EntryPoint);

//    createNode(7, 18*5, 122*5, NodeType::Normal);
//    createNode(8, 48.5*5, 122*5, NodeType::Normal);
//    createNode(9, 170.5*5, 122*5, NodeType::Normal);
//    createNode(10, 201*5, 122*5, NodeType::Normal);

//    createNode(11, 18*5, 152.5*5, NodeType::Normal);
//    createNode(12, 79*5, 152.5*5, NodeType::Normal);
//    createNode(13, 109.5*5, 152.5*5, NodeType::Normal);
//    createNode(14, 140*5, 152.5*5, NodeType::Normal);
//    createNode(15, 201*5, 152.5*5, NodeType::Normal);

//    createNode(16, 18*5, 183*5, NodeType::Normal);
//    createNode(17, 48.5*5, 183*5, NodeType::Normal);
//    createNode(18, 170.5*5, 183*5, NodeType::Normal);
//    createNode(19, 201*5, 183*5, NodeType::Normal);

//    createNode(20, 18*5, 214*5, NodeType::Player2EntryPoint);
//    createNode(21, 48.5*5, 214*5, NodeType::Normal);
//    createNode(22, 79*5, 214*5, NodeType::Normal);
//    createNode(23, 109.5*5, 214*5, NodeType::Player2Goal);
//    createNode(24, 140*5, 214*5, NodeType::Normal);
//    createNode(25, 170.5*5, 214*5, NodeType::Player2EntryPoint);
//    createNode(26, 201*5, 214*5, NodeType::Normal);

////    int dimension = vectorNodes.size();
////    adjacencyList (27,
////                   std::vector< unsigned char > (27, 0));

//    adjacencyList.reserve(vectorNodes.size());
//    std::vector< unsigned char > localAdjacencyList (0);
//    for (unsigned int i = 0; i < vectorNodes.size(); i++)
//    {   adjacencyList.push_back(localAdjacencyList);
//        //if(vectorNodes[i]->getIdentifier())
//        //{
//            //adjacencyList.push_back(std::vector< unsigned char >)
//            //                       (vectorNodes[i]->getIdentifier()));
//        //}
//    }

//    createEdge(0, 1);
//    createEdge(1, 2);
//    createEdge(2, 3);
//    createEdge(3, 4);
//    createEdge(4, 5);
//    createEdge(5, 6);

//    createEdge(0, 7);
//    createEdge(0, 8);
//    createEdge(6, 9);
//    createEdge(6, 10);

//    createEdge(7, 11);
//    createEdge(8, 12);
//    createEdge(12, 13);
//    createEdge(13, 14);
//    createEdge(9, 14);
//    createEdge(10, 15);

//    createEdge(11, 16);
//    createEdge(12, 17);
//    createEdge(14, 18);
//    createEdge(15, 19);

//    createEdge(16, 20);
//    createEdge(17, 20);
//    createEdge(18, 26);
//    createEdge(19, 26);

//    createEdge(20, 21);
//    createEdge(21, 22);
//    createEdge(22, 23);
//    createEdge(23, 24);
//    createEdge(24, 25);
//    createEdge(25, 26);

//    saveNodesToFile("original3x3.tfgarena", vectorNodes, adjacencyList);
//}
#define FOLDINGEND }

Graph::Graph(QQmlApplicationEngine *engineSetup, QQuickItem *rootSetup,
             std::string fileName,
             QObject *parent) : QObject(parent)
{
    //radius = 5;
    maxNumberOfEntryPointsPlayer1 = 2;
    maxNumberOfEntryPointsPlayer2 = 2;

//    initialFieldWidth = 1110;
//    initialFieldHeight = 1540;

//    m_applicationWindowWidth = 1110;
//    m_applicationWindowHeight = 1540;

//    engine = engineSetup;
//    root = rootSetup;

    //Load grid
    // 0 - 1 - 2 - 3 - 4 - 5 - 6
    // | \                   / |
    // 7  8                 9 10
    // |   \               /   |
    // 11    12 - 13 - 14     15
    // |   /               \   |
    // 16 17               18 19
    // | /                   \ |
    // 20 - 21-22-23-24- 25 - 26

    // "original3x3.tfgarena"
    loadNodesFromFile(fileName, vectorNodes, adjacencyList);
    int vectorNodesSize = vectorNodes.size();
    for (int i = 0; i < vectorNodesSize; i++)
    {   QQmlEngine::setObjectOwnership(vectorNodes[i], QQmlEngine::CppOwnership);
    }
}
//Graph::Graph(QQmlApplicationEngine *engine, QQuickItem *root,
//             std::vector<Node> & vectorNodes, adjacencyListType adjacecyList,
//             QObject *parent) : QObject(parent)
//{

//}

bool Graph::createNode(unsigned char nodeIdentifier,
                       int positionX, int positionY,
                       NodeType nodeTypeValue, NodeStatus nodeStatusValue)
{   //bool indetifierAlreadyUsed = false;
    //bool tooCloseFromAnotherNode = false;

    int radius = 5;

    unsigned char numberOfPlayer1EntryPoint = 0;
    unsigned char numberOfPlayer2EntryPoint = 0;

    int vectorNodesSize = vectorNodes.size();
    for (int i = 0; i < vectorNodesSize; i++)
    {   if (vectorNodes[i]->getIdentifier() == nodeIdentifier)
        {   //indetifierAlreadyUsed = true;
            return false;
        }
        else if (positionX <= vectorNodes[i]->getX() + 2*radius
                 and positionX >= vectorNodes[i]->getX() - 2*radius
                 and positionY <= vectorNodes[i]->getY() + 2*radius
                 and positionY >= vectorNodes[i]->getX() - 2*radius)
        {   //tooCloseFromAnotherNode = true;
            return false;
        }

        NodeType nodeType = vectorNodes[i]->getNodeType();
        if (nodeType == NodeType::Player1Goal
            and nodeTypeValue == NodeType::Player1Goal)
        {   nodeTypeValue = NodeType::Normal;
        }else if (nodeType == NodeType::Player2Goal
                  and nodeTypeValue == NodeType::Player2Goal)
        {   nodeTypeValue = NodeType::Normal;
        }else if (nodeType == NodeType::Player1EntryPoint)
        {   numberOfPlayer1EntryPoint++;
            if (numberOfPlayer1EntryPoint > maxNumberOfEntryPointsPlayer1)
            {   nodeTypeValue = NodeType::Normal;
            }
        }else if (nodeType == NodeType::Player2EntryPoint)
        {   numberOfPlayer2EntryPoint++;
            if (numberOfPlayer2EntryPoint > maxNumberOfEntryPointsPlayer2)
            {   nodeTypeValue = NodeType::Normal;
            }
        }
    }

    //if (indetifierAlreadyUsed == false and tooCloseFromAnotherNode == false)
    //Node node(nodeIdentifier, positionX, positionY,
    //          nodeTypeValue, nodeStatusValue);
    //Node *ptrNode = &node;
    Node *ptrNode = new Node (nodeIdentifier,
                              positionX, positionY,
                              nodeTypeValue, nodeStatusValue);

    vectorNodes.push_back(ptrNode);
    return true;
}

bool Graph::createEdge(unsigned char nodeIdentifier1,
                       unsigned char nodeIdentifier2)
{   if (nodeIdentifier1 == nodeIdentifier2)
    {   return false;
    }
    int vectorNodesSize = vectorNodes.size();
    for (int i = 0; i < vectorNodesSize; i++)
    {   if (vectorNodes[i]->getIdentifier() == nodeIdentifier1)
        {   if (!adjacencyList[nodeIdentifier1].empty())
            {   int localAdjacencyList = adjacencyList[nodeIdentifier1].size();
                for (int j = 0; j < localAdjacencyList; j++)
                {   if (adjacencyList[nodeIdentifier1][j] == nodeIdentifier2)
                    {   // the element is already in the list
                        return false;
                    }
                }
            }else
            {

            }
            adjacencyList[nodeIdentifier1].push_back(nodeIdentifier2);
            adjacencyList[nodeIdentifier2].push_back(nodeIdentifier1);
            return true;
        }else if (vectorNodes[i]->getIdentifier() == nodeIdentifier2)
        {   if (!adjacencyList[nodeIdentifier2].empty())
            {   int localAdjacencyList = adjacencyList[nodeIdentifier2].size();
                for (int j = 0; j < localAdjacencyList; j++)
                {   if (adjacencyList[nodeIdentifier2][j] == nodeIdentifier1)
                    {   // the element is already in the list
                        return false;
                    }
                }
            }
            adjacencyList[nodeIdentifier1].push_back(nodeIdentifier2);
            adjacencyList[nodeIdentifier2].push_back(nodeIdentifier1);
            return true;
        }
    }
    return false;
}

void Graph::loadGraphFromFile(std::string fileName)
{
    vectorNodes.clear();

    for (unsigned int i = 0; i < adjacencyList.size(); i++)
    {   adjacencyList[i].clear();
    }
    adjacencyList.clear();

    //Load grid
    // ex: "original3x3.tfgarena"
    // 0 - 1 - 2 - 3 - 4 - 5 - 6
    // | \                   / |
    // 7  8                 9 10
    // |   \               /   |
    // 11    12 - 13 - 14     15
    // |   /               \   |
    // 16 17               18 19
    // | /                   \ |
    // 20 - 21-22-23-24- 25 - 26


    loadNodesFromFile(fileName, vectorNodes, adjacencyList, this);
    int vectorNodesSize = vectorNodes.size();
    for (int i = 0; i < vectorNodesSize; i++)
    {   QQmlEngine::setObjectOwnership(vectorNodes[i],
                                       QQmlEngine::CppOwnership);
    }
}

std::vector<Node*> Graph::getVectorNodes()
{    return vectorNodes;
}

adjacencyListType Graph::getAdjacencyList()
{   return adjacencyList;    
}

#define FOLDINGSTART {
//void Graph::displayNodes()
//{


//    const QUrl urlNodeGoal(QStringLiteral("qrc:/NodeGoal.qml"));
//    const QUrl urlNodeEntryPoint(QStringLiteral("qrc:/NodeEntryPoint.qml"));
//    const QUrl urlNodeNormal(QStringLiteral("qrc:/NodeNormal.qml"));

//    int nodesVisualSize = nodesVisual.size();

//    if (nodesVisualSize == 0)
//    {   int vectorNodesSize = vectorNodes.size();
//        for (int i = 0; i < vectorNodesSize; i++)
//        {   QQuickItem *node = NULL;
//            NodeType nodeType = vectorNodes[i].getNodeType();
//            if (nodeType == NodeType::player1Goal)
//            {   node = integrationQMLToDisplayNode(urlNodeGoal);
//                node->setProperty("circleColor", "#ffffff");
//                node->setProperty("insideCircleAndTextColor", "#000000");
//                node->setProperty("rotation", 180);
//            }else if (nodeType == NodeType::player2Goal)
//            {   node = integrationQMLToDisplayNode(urlNodeGoal);
//            }else if (nodeType == NodeType::player1EntryPoint)
//            {   node =
//                    integrationQMLToDisplayNode(urlNodeEntryPoint);
//                node->setProperty("circleColor", "#ffffff");
//                node->setProperty("insideCircleAndTextColor", "#000000");
//                node->setProperty("rotation", 180);
//            }else if (nodeType == NodeType::player2EntryPoint)
//            {   node =
//                    integrationQMLToDisplayNode(urlNodeEntryPoint);
//                //node->setProperty("color", "#000000");
//            }else //if (nodeType == NodeType::normal)
//            {   node = integrationQMLToDisplayNode(urlNodeNormal);
//                node->setProperty("circleColor", "#000000");
//                node->setProperty("borderColor", "#2d2d2d");
//            }
//            int intialRadius = node->property("__intialRadius").toInt();

//            node->setProperty("radius", intialRadius *
//                              m_applicationWindowWidth/initialFieldWidth);
//            int nodeRadius = node->property("radius").toInt();

//            node->setProperty("x", (vectorNodes[i].getX() - nodeRadius)*
//                              m_applicationWindowWidth/initialFieldWidth);
//            node->setProperty("y", (vectorNodes[i].getY() - nodeRadius)*
//                              m_applicationWindowHeight/initialFieldHeight);
//            nodesVisual.push_back(node);

////            qDebug() << "X" << (vectorNodes[i].getX() - nodeRadius)*
////                        m_applicationWindowWidth/initialFieldWidth;
////            qDebug() << "m_applicationWindowWidth" << m_applicationWindowWidth;

////            qDebug() << "Y" << (vectorNodes[i].getY() - nodeRadius)*
////                        m_applicationWindowHeight/initialFieldHeight;
////            qDebug() << "(vectorNodes[i].getY() - nodeRadius)" << (vectorNodes[i].getY() - nodeRadius);
////            qDebug() << "m_applicationWindowHeight" << m_applicationWindowHeight;
////            qDebug() << "initialFieldHeight" << initialFieldHeight;

//        }
//    }
//    else
//    {   for (int i = 0; i < nodesVisualSize; i++)
//        {   int intialRadius = nodesVisual[i]->property("__intialRadius").toInt();
//            nodesVisual[i]->setProperty("radius", intialRadius *
//                              m_applicationWindowWidth/initialFieldWidth);
//            int nodeRadius = nodesVisual[i]->property("radius").toInt();

//            nodesVisual[i]->setProperty("x", (vectorNodes[i].getX() - nodeRadius)*
//                                            m_applicationWindowWidth/initialFieldWidth);
//            nodesVisual[i]->setProperty("y", (vectorNodes[i].getY() - nodeRadius)*
//                                            m_applicationWindowHeight/initialFieldHeight);
//        }

//    }

////    nodeObject->setProperty("x", xBoardGamePage + BOARD_TILE_SPACED_SIZE * y
////                            + BOARD_MARGIN);
////    nodeObject->setProperty("y", yBoardGamePage + BOARD_TILE_SPACED_SIZE * x
////                            + 2 * BOARD_MARGIN);

//}

//QQuickItem* Graph::integrationQMLToDisplayNode(const QUrl url)
//{   //Loading QML Objects from C++
//    //doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html
//    //Using QQmlComponent
//    //QQmlComponent component(&engine, QUrl::fromLocalFile("qrc:/Tile.qml"));

//    //QQmlComponent component(&engineSetup, url);
//    //before engineSetup was passed by reference (&engineSetup)
//    QQmlComponent component(engine, url);

//    QQuickItem *nodeObject = qobject_cast<QQuickItem*>(component.create());

//    //To avoid the Javascript garbage collector to kill it, tell QML that C++
//    //takes care of it:
//    QQmlEngine::setObjectOwnership(nodeObject, QQmlEngine::CppOwnership);

//    //Set the visual parent of the item.
//    nodeObject->setParentItem(root);
//    //Makes the object a child of parent.
//    //tileObject->setParent(&engineSetup);
//    nodeObject->setParent(engine);

//    return nodeObject;
//}

//Node Graph::searchNode(unsigned char nodeIdentifier)
//{    int vectorNodesSize = vectorNodes.size();
//     for (int i = 0; i < vectorNodesSize; i++)
//     {   if (vectorNodes[i].getIdentifier() == nodeIdentifier)
//         {   return vectorNodes[i];
//         }
//     }
//}


//void Graph::setApplicationWindowWidth(int width)
//{   if (width != m_applicationWindowWidth)
//    {   qDebug() << " Graph m_applicationWindowWidth" << m_applicationWindowWidth;
//        m_applicationWindowWidth = width;
//        //displayNodes();
//    }
//}

//void Graph::setApplicationWindowHeight(int height)
//{   if (height != m_applicationWindowHeight)
//    {   qDebug() << " Graphm_applicationWindowHeight" << m_applicationWindowHeight;
//        m_applicationWindowHeight = height;
//        //displayNodes();
//    }
//}
#define FOLDINGEND }
