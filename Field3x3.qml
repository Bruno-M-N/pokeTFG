//First, import the Qt Quick module. This gives us access to graphical
// primitives such as Item, Rectangle, Text, and so on. For the full list of
// types, see the Qt Quick QML Types documentation.
import QtQuick 2.14
//import QtQuick.Shape
//import QtQuick.Shapes 1.14

import Node 1.0

import QENUMNodeType 1.0
import "nodesDynamicQMLCreation.js" as NodesDynamicQMLCreation

import QPoke 1.0
import PokePawn 1.0
import "pokePawnDynamicQMLCreation.js" as PokePawnDynamicQMLCreation


Item {
    Rectangle {
        id: root
        color: "lightgrey"
        anchors.fill: parent
        implicitWidth: field3x3.implicitWidth
        implicitHeight: field3x3.implicitHeight
    //        width: 1110//220*5+10
    //        height: 1540//306*5+10

        Item {
            //id: screen
            property int _minSide: Math.min(window.width, window.height)
    //            anchors.verticalCenter: parent.verticalCenter
    //            anchors.horizontalCenter: parent.horizontalCenter
    //            x: (window.width - _minSide)/2
    //            y: 10 + (window.height - _minSide)/2
    //            anchors.fill: parent
    //            anchors.margins: 0


            implicitWidth: field3x3.implicitWidth// - 20
            implicitHeight: field3x3.implicitHeight//field3x3.sourceSize.implicitHeight / implicitHeight * _minSide - 20

    //            scale: window.width / field3x3.sourceSize.width
            scale: window.width / field3x3.sourceSize.width//,
//                            window.height / field3x3.sourceSize.height)
            transformOrigin: Item.TopLeft



            Image {
                id: field3x3
                fillMode: Image.PreserveAspectFit
                source: "img/Field3x3Background.png"
                anchors.fill: parent
                //anchors.margins: 2.5
                //source: "../images/Field3x3Background.png"
                Component.onCompleted:
                {   console.log("field3x3" + sourceSize)
                    //NodesDynamicQMLCreation.loadFieldNodesAndAdjacencyList();
                    NodesDynamicQMLCreation.displayNodesAndEdges();
                }

                FieldBench3x3 {
                    id: fieldBench3x3_black
                    benchColor: "#000000" // "#ffffff"
                    bottomAndSmallInternalBorderColor: "#d19843"//"#bad788"

                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 7*5//35
                }

                FieldPokemonCenterPlaceText {
                    id: fieldPokemonCenterPlaceText_black
                    circleColor: "#d19843" //#bad788
                    borderAndTextColor: "#000000"
                    anchors.verticalCenter: fieldBench3x3_black.verticalCenter
                    anchors.left: fieldBench3x3_black.right
                    anchors.leftMargin: 23*5
                }

                FieldBench3x3 {
                    id: fieldBench3x3_white
                    benchColor: "#ffffff"
                    bottomAndSmallInternalBorderColor: "#d19843"//"#bad788"

                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 7*5//35
                    rotation: 180
                }

                FieldPokemonCenterPlaceText {
                    id: fieldPokemonCenterPlaceText_white
                    circleColor: "#d19843" //#bad788
                    borderAndTextColor: "#ffffff"
                    anchors.verticalCenter: fieldBench3x3_white.verticalCenter
                    anchors.right: fieldBench3x3_white.left
                    anchors.rightMargin: 23*5
                    rotation: 180
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
