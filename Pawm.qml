import QtQuick 2.14
import QtQuick.Shapes 1.14

import QPoke 1.0
import PokePawn 1.0

Item {
    id: root

    property alias outsideCircleColor: circle.color //#bad788
    property alias sectorsColor: innerTopSector.strokeColor //#96c056
    property alias innerCircleColor: smallInnerCircle.color //#bfd962

    implicitWidth: circle.width
    implicitHeight: circle.height

    Rectangle {
         id: circle
         width: 28*5
         height: width
         anchors.fill: parent
//         anchors.horizontalCenter: parent.horizontalCenter
//         anchors.top: parent.top
         color: "#e6e6e6"
         border.color: "#000000"
         border.width: 2*5
         radius: width*0.5
         
         Rectangle {
              id: innerCercle
              width: 12*5
              height: width
              color: "#dcc823"
//              anchors.fill: parent
              anchors.horizontalCenter: parent.horizontalCenter
              anchors.verticalCenter: parent.verticalCenter
     //         anchors.top: parent.top
              //"#d2782f"
     //         border.color: "#000000"
     //         border.width: 1
              radius: width*0.5
        }
        
         Rectangle {
              id: smallInnerCircle
              width: 10*5
              height: width
//              anchors.fill: parent
              anchors.horizontalCenter: parent.horizontalCenter
              anchors.verticalCenter: parent.verticalCenter
     //         anchors.top: parent.top
              color: "#c3c3c3"
     //         border.color: "#000000"
     //         border.width: 1
              radius: width*0.5
        }

         PokePawn {
            anchors.centerIn: parent
            width: circle.width

            moveSector:[
            ]
         }
    }
}
