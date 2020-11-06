import QtQuick 2.14
import QtQuick.Shapes 1.14


Item {
    id: root

    property alias outsideCircleColor: circle.color //#bad788
    property alias borderAndInnerCircleColor: smallInnerCircle.color //#bfd962

    implicitWidth: circle.width
    implicitHeight: circle.height

    Rectangle {
         id: circle
         width: 32*5
         height: 32*5
         anchors.fill: parent
//         anchors.horizontalCenter: parent.horizontalCenter
//         anchors.top: parent.top
         color: "#bad788" //"#e9a841"
         border.color: smallInnerCircle.color
         border.width: 2*5
         radius: width*0.5
        
         Rectangle {
              id: smallInnerCircle
              width: 4*5
              height: 4*5
//              anchors.fill: parent
              anchors.horizontalCenter: parent.horizontalCenter
              anchors.verticalCenter: parent.verticalCenter
     //         anchors.top: parent.top
              color: "#000000" //"#ffffff"
     //         border.color: "#000000"
     //         border.width: 1
              radius: width*0.5
        }

    }
}
