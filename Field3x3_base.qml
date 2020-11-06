import QtQuick 2.14
//import QtQuick.Shape
import QtQuick.Shapes 1.14




Item {
    width: 220*5
    height: 306*5
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 220*5
        height: 306*5
        //        color: "#ffffff"
        gradient: Gradient {
            GradientStop {
                position:0.0; color: "#c66427"
            }
            GradientStop {
                position:0.3; color: "#ce782a"//rgb(206, 120, 42)//"#c66427"
            }
            GradientStop {
                position:0.7; color: "#ce782a"//rgb(206, 120, 42)//"#c66427"
            }
            GradientStop {
                position:1.0; color: "#c66427"
            }
        }
        

        Rectangle {
            id: rectangle1
            border.width: 1
            gradient: Gradient {
                GradientStop {
                    position:0.0; color: "#e0a759"
                }
                GradientStop {
                    position:0.3; color: "#e4b559"//rgb(206, 120, 42)//"#c66427"
                }
                GradientStop {
                    position:0.7; color: "#e4b559"//rgb(206, 120, 42)//"#c66427"
                }
                GradientStop {
                    position:1.0; color: "#e0a759"
                }
            }
            anchors.rightMargin: 18*5
            anchors.leftMargin: 18*5
            anchors.bottomMargin: 91*5
            anchors.topMargin: 91*5
            anchors.fill: parent

            Shape {
                y: 0
                width: 62*5
                anchors.left: parent.left
                anchors.leftMargin: 1
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.horizontalCenterOffset: 0
                ShapePath {
                    //                    strokeWidth: 4
                    strokeColor: "black"
                    fillGradient: LinearGradient {
                        x1: 0; y1: 0
                        x2: 124*5; y2: 0
                        //rgb(229, 182, 127)
                        GradientStop { position: 0; color: "#e5b67f" }
                        ////rgb(235, 195, 131)
                        GradientStop { position: 0.5; color: "#ebc383" }
                    }
                    //                    strokeStyle: ShapePath.DashLine
                    //                    dashPattern: [ 1, 4 ]
                    startX: 0; startY: 0
                    PathLine { x: 62*5; y: 62*5 }
                    PathLine { x: 0; y: 124*5}
                    //                    PathLine { x: 0; y: 62*5 }
                    //                    PathLine { x: 2; y: 2 }
                }
            }

            Shape {
                y: 0
                width: 62*5
                rotation: 180
                anchors.right: parent.right
                anchors.rightMargin: 1
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.horizontalCenterOffset: 0
                ShapePath {
                    //                    strokeWidth: 4
                    strokeColor: "black"
                    fillGradient: LinearGradient {
                        x1: 0; y1: 0
                        x2: 124*5; y2: 0
                        //rgb(229, 182, 127)
                        GradientStop { position: 0; color: "#e5b67f" }
                        ////rgb(235, 195, 131)
                        GradientStop { position: 0.5; color: "#ebc383" }
                    }
                    //strokeStyle: ShapePath.DashLine
                    //dashPattern: [ 1, 4 ]
                    startX: 0; startY: 0
                    PathLine { x: 62*5; y: 62*5 }
                    PathLine { x: 0; y: 124*5}
                    //                    PathLine { x: 0; y: 62*5 }
                    //                    PathLine { x: 2; y: 2 }
                }
            }

        }
/*
        Rectangle {
            id: bench2back
            x: 422
            y: 1227
            width: 480
            height: 35*5
            color: "#d19843"
            radius: 35*2.5
            border.width: 2*5
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 7*5

            Rectangle {
                id: bench2
                x: 422
                y: 1227
                width: 96*5//480
                height: 35*5
                color: "#d19843"
                radius: 35*2.5
                border.width: 2*5
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 7*5

//                Column {
//                    id: column
//                    anchors.verticalCenter: parent.verticalCenter
//                    anchors.left: parent.left
//                    width: 32*5
//                    height: 35*5

//                    Shape {
//                        width: 28*5
//                        height: 28*5
//                        anchors.verticalCenter: parent.verticalCenter
//                        anchors.left: parent.left
//                        anchors.leftMargin: 35/2

//                        //multisample, decide based on your scene settings
//                        //                    layer.enabled: true
//                        //                    layer.samples: 4

//                        ShapePath {
//                            fillColor: "#00000000"
//                            //fillColor: "blue"
//                            strokeColor: "#e9a841"//"#d77934"
//                            strokeWidth: 3.5*5
//                            //capStyle: ShapePath.FlatCap

//                            PathAngleArc {

//                                centerX: 28*2.5; centerY: 28*2.5
//                                radiusX: 45; radiusY: 45
//                                startAngle: 0
//                                sweepAngle: 360
//                            }
//                        }
//                        ShapePath {
//                            fillColor: "#00000000"
//                            //fillColor: "blue"
//                            strokeColor: "#d77934"
//                            strokeWidth: 3*5
//                            capStyle: ShapePath.FlatCap

//                            PathAngleArc {

//                                centerX: 28*2.5; centerY: 28*2.5
//                                radiusX: 45; radiusY: 45
//                                startAngle: 0
//                                sweepAngle: 180
//                            }
//                        }
//                        ShapePath {
//                            fillColor: "#00000000"
//                            //fillColor: "blue"
//                            strokeColor: "#d77934"
//                            strokeWidth: 3*5
//                            capStyle: ShapePath.FlatCap

//                            PathAngleArc {

//                                centerX: 28*2.5; centerY: 28*2.5
//                                radiusX: 45; radiusY: 45
//                                startAngle: 0
//                                sweepAngle: -180
//                            }
//                        }
//                    }
//                }

//                Column {
//                    id: column1
//                    anchors.verticalCenter: parent.verticalCenter
//                    anchors.left: column.right
//                    width: 32*5
//                    height: 35*5
//                    Shape {
//                        width: 28*5
//                        height: 28*5
//                        anchors.horizontalCenter: parent.horizontalCenter
//                        ShapePath {
//                            strokeWidth: 3.5*5
//                            fillColor: "#00000000"
//                            strokeColor: "#e9a841"
//                            PathAngleArc {
//                                centerX: 28*2.5
//                                startAngle: 0
//                                radiusX: 45
//                                sweepAngle: 360
//                                centerY: 28*2.5
//                                radiusY: 45
//                            }
//                        }
//                        anchors.verticalCenter: parent.verticalCenter
//                    }
//                }

//                Column {
//                    id: column2
//                    anchors.verticalCenter: parent.verticalCenter
//                    anchors.right: parent.right
//                    width: 32*5
//                    height: 35*5

//                    Shape {
//                        width: 28*5
//                        height: 28*5
//                        anchors.verticalCenter: parent.verticalCenter
//                        anchors.right: parent.right
//                        anchors.rightMargin: 35/2
//                        ShapePath {
//                            strokeWidth: 3.5*5
//                            fillColor: "#00000000"
//                            strokeColor: "#e9a841"
//                            PathAngleArc {
//                                centerX: 28*2.5
//                                startAngle: 0
//                                sweepAngle: 360
//                                radiusX: 45
//                                centerY: 28*2.5
//                                radiusY: 45
//                            }
//                        }
//                    }

//                }

            }
        }
*/
    }

}


