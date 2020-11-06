//First, import the Qt Quick module. This gives us access to graphical
//primitives such as Item, Rectangle, Text, and so on. For the full list of
//types, see the Qt Quick QML Types documentation.
import QtQuick 2.12

//Next, import the Qt Quick Controls module. Amongst other things, this provides
//access to ApplicationWindow, which will replace the existing root type Window
import QtQuick.Controls 2.12

//Item {
    Page {
        id: homePage
        anchors.fill: parent

        implicitWidth: initialMenuImage.width
        implicitHeight: initialMenuImage.height

        header: ToolBar {
            Label {
                text: qsTr("TFG")
                font.pixelSize: 20
                anchors.centerIn: parent
            }
        }

        Rectangle {
            id: backgroundRectangle
            color: "#faf8ef"
            anchors.fill: parent

            Image {
                id: initialMenuImage
                fillMode: Image.PreserveAspectFit
                source: "img/initialMenuImage.png"
                anchors.fill: parent
                anchors.margins: 2.5
                //source: "../images/initialMenuImage.png"
                Component.onCompleted: console.log("initialMenuImage" + sourceSize)

                Column {
                    id: column
                    width: 200
                    anchors.top: parent.top
                    anchors.topMargin: 50
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 50
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: 10

                    Button {
                        id: buttonSettings
                        text: qsTr("Settings")
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Button {
                        id: buttonBattle
                        text: qsTr("Battle")
                        anchors.horizontalCenter: parent.horizontalCenter

                        MouseArea {
                            id: mouseAreaButtonBattle
                            anchors.fill: buttonBattle
                            acceptedButtons: Qt.LeftButton | Qt.RightButton
                            onClicked: {
                                if (mouse.button == Qt.RightButton |
                                        mouse.button == Qt.LeftButton )
                                {
                                    stackView.push("Field3x3.qml");
                                    cppPageManagement.showGamePage("Game Page");
//                                    cppPageManagement.setApplicationWindowWidth(window.width);
//                                    cppPageManagement.setApplicationWindowHeight(window.height);
                                }
                            }
                        }

                    }
                }
            }
        }
    }
//}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5;anchors_height:337}
}
##^##*/
