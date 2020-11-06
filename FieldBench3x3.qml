import QtQuick 2.0

Item {
    id: element

    property alias benchColor: bench.color
    property alias bottomAndSmallInternalBorderColor: benchBack.color

    implicitWidth: benchBack.width
    implicitHeight: benchBack.height + __bottonMargin

    readonly property int __bottonMargin: 35//7*5

    Rectangle {
        id: benchBack
        width: 480
        height: 35*5
        color: "#d19843"//"#bad788"
        radius: 30*2.5
        border.width: 2*5
        border.color:  bench.color
//        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: __bottonMargin
    }

    Rectangle {
        id: benchBorder
        width: 96*5//480
        height: 35*5
        color: "#ffffff"
        radius: 35*2.5
        border.width:2*5
        border.color:  bench.color
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.bottom: parent.bottom
//        anchors.bottomMargin: __bottonMargin



        Rectangle {
            id: bench
            width: 96*5 - 20//480-20
            height: 35*5 - 20
            color: "#000000" // "#ffffff"
            radius: 35*2.5
            border.width: 1//2*5
            border.color:  benchBack.color
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10

            Row {
                id: benchPlaces3x3Row
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
                spacing: 10

                FieldBenchPlace {
                    id: fieldBenchPlace1
                }

                FieldBenchPlace {
                    id: fieldBenchPlace2
                }

                FieldBenchPlace {
                    id: fieldBenchPlace3
                }

            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
