import QtQuick 2.14
import QtQuick.Shapes 1.14

Item {
    id: root

    property alias color: rectangleLine.strokeColor
    property alias x1: rectangleLine.startX
    property alias y1: rectangleLine.startY
    property alias x2: pathline.x
    property alias y2: pathline.y

    //readonly property int __intialRadius: 14*5*0.5
    
    implicitWidth: rectangle.width
    implicitHeight: rectangle.height
    
    Shape {
        id: rectangle

        ShapePath {
            id: rectangleLine
            strokeWidth: 3*5
            fillColor: "#00000000"
            strokeColor: "#000000"
            capStyle: ShapePath.FlatCap
            startX: 0
            startY: 0
            PathLine {
                id: pathline
                x: 15*5
                y: 15*5
            }
            //PathLine { x: 15.5; y: (innerSectors.height)/2-4 }
        }


    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
