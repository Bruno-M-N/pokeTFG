import QtQuick 2.14
import QtQuick.Shapes 1.14


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
         height: 28*5
         anchors.fill: parent
//         anchors.horizontalCenter: parent.horizontalCenter
//         anchors.top: parent.top
         color: "#e9a841"
//         border.color: "#000000"
//         border.width: 1
         radius: width*0.5
         
         Rectangle {
              id: innerCercle
              width: 8*5
              height: 8*5
//              anchors.fill: parent
              anchors.horizontalCenter: parent.horizontalCenter
              anchors.verticalCenter: parent.verticalCenter
     //         anchors.top: parent.top
              color: innerTopSector.strokeColor//"#d2782f"
     //         border.color: "#000000"
     //         border.width: 1
              radius: width*0.5
        }
        
         Rectangle {
              id: smallInnerCircle
              width: 4*5
              height: 4*5
//              anchors.fill: parent
              anchors.horizontalCenter: parent.horizontalCenter
              anchors.verticalCenter: parent.verticalCenter
     //         anchors.top: parent.top
              color: "#f0b64a"
     //         border.color: "#000000"
     //         border.width: 1
              radius: width*0.5
        }

        Shape {
            id: innerSectors
            width: circle.width - 4*5
            height: circle.height - 4*5
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            //color: "#d2782f"
//            anchors.right: parent.right
//            anchors.rightMargin: 35/2
            ShapePath {
                id: innerTopSector
                strokeWidth: 6*5
                fillColor: "#00000000"
                strokeColor: "#d2782f" // rgb(210, 120, 47)
                capStyle: ShapePath.FlatCap
                startX: innerSectors.width-15.5
                startY: innerSectors.height/2-4
                PathLine { 
                    x: innerSectors.width-15.5
                    y: innerSectors.height/2-12
                }
                PathAngleArc {
                    centerX: innerSectors.width/2
                    centerY: innerSectors.height/2
                    startAngle: -10
                    sweepAngle: -161
                    radiusX: 45
                    radiusY: 45
                }
                PathLine { x: 15.5; y: (innerSectors.height)/2-4 }
            }
            ShapePath {
                id: innerBottomSector 
                strokeWidth: 6*5
                fillColor: "#00000000"
                strokeColor: "#d2782f" //innerTopSector.strokeColor
                capStyle: ShapePath.FlatCap
                startX: innerSectors.width-15.5
                startY: innerSectors.height/2+4
                PathLine {
                    x: innerSectors.width-15.5
                    y: innerSectors.height/2+12
                }
                PathAngleArc {
                    centerX: innerSectors.width/2
                    centerY: innerSectors.height/2
                    startAngle: 10
                    sweepAngle: 161
                    radiusX: 45
                    radiusY: 45
                }
                PathLine { x: 15.5; y: innerSectors.height/2+4 }
            }

        }
    }
}
