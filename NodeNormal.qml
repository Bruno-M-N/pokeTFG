import QtQuick 2.14
//import QtQuick.Shapes 1.14

Item {
    id: root

    property alias circleColor: circle.color
    property alias borderColor: circle.border.color
    property alias radius: circle.radius

    readonly property int __intialRadius: 10*5*0.5

    implicitWidth: circle.width
    implicitHeight: circle.height

    scale: circle.radius / __intialRadius
    transformOrigin: Item.TopLeft

    Rectangle {
         id: circle
         width: radius*2
         height: width
         //anchors.fill: parent
//         anchors.horizontalCenter: parent.horizontalCenter
//         anchors.top: parent.top
         color: "#000000" //"#e9a841"
         border.width: 1*5
         radius: 10*5*0.5
         border.color: "#1b1b1b"
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
