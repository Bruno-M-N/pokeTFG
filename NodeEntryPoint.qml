import QtQuick 2.14
import QtQuick.Shapes 1.14


Item {
    id: root

    property alias circleColor: circle.color
    property alias innerCircleAndTextColor: entryPointText.color
    property alias radius: circle.radius

    //readonly property int __intialRadius: 14*5*0.5
    
    implicitWidth: circle.width
    implicitHeight: circle.height

    //scale: circle.radius / __intialRadius
    //transformOrigin: Item.TopLeft
    
    Rectangle {
        id: circle
        width: radius*2
        height: width
        color: "#000000" //"#bad788"
        radius: 14*5*0.5
        border.color: "#000000"
        border.width: 2*5-2
        
        Rectangle {
            id: smallInnerCircle
            width: circle.width - 2*5
            height: circle.width - 2*5
            color: "#00000000"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            border.color: entryPointText.color
            border.width: 2
            radius: width*0.5

        }
        Text {
            id: entryPointText
            width: 160
            height: 160
            color: "#ffffff" //"#000000" //"#ffffff"
            text: qsTr("ENTRY \n POINT ")
            font.family: "Tahoma"
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: circle.horizontalCenter
            anchors.verticalCenter: circle.verticalCenter
            font.pixelSize:13
        }
        //        Shape {
        //            id: insideCircle
        //            width: circle.width-1*5
        //            height: circle.width-1*5
        //            anchors.horizontalCenter: parent.horizontalCenter
        //            anchors.verticalCenter: parent.verticalCenter
        //            ShapePath {
        //                id: innerTopSector
        //                strokeWidth: 1
        //                fillColor: "#00000000"
        //                strokeColor: "#d2782f" // rgb(210, 120, 47)
        //                capStyle: ShapePath.FlatCap
        ////                startX: insideCircle.width-1*5
        ////                startY: insideCircle.height/2-1*5
        //                PathAngleArc {
        //                    centerX: insideCircle.width/2
        //                    centerY: insideCircle.height/2
        //                    startAngle: 0
        //                    sweepAngle: 360
        //                    radiusX: 45
        //                    radiusY: 45
        //                }
        //            }
        //        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
