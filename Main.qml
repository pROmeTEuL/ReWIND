import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            RoundButton {
                text: "Open Menu"
                onClicked: drawer.open()
            }
            Item {
                Layout.fillWidth: true
            }
            RoundButton {
                id: editButton
                text: "Edit"
                onClicked: {
                    this.visible = false
                    stackView.push("EditItemPage.qml")
                    drawer.close()
                }
                visible: false
            }
        }
        Frame {
            id: mainFrame
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    Drawer {
        id: drawer
        width: parent.width * 0.4
        height: parent.height
        edge: Qt.LeftEdge

        ColumnLayout {
            anchors.fill: parent
            ListView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                delegate: RowLayout {
                    width: parent.width
                    Label {
                        text: name
                    }
                    Item {
                        Layout.fillWidth: true
                    }
                    RoundButton {
                        text: "View"
                        onClicked: {
                            editButton.visible = true
                            while(stackView.depth > 1) {
                                stackView.pop()
                            }
                            stackView.push("PreviewItemPage.qml")
                            drawer.close()
                        }
                    }
                }

                model: ListModel {
                    ListElement { name: "Item 1" }
                }
            }
            Item {
                Layout.fillHeight: true
            }
            RowLayout {
                Item {
                    Layout.fillWidth: true
                }
                RoundButton {
                    text: "+"
                    onClicked: {
                        stackView.push("EditItemPage.qml")
                        drawer.close()
                    }
                }
                Item {
                    Layout.fillWidth: true
                }
            }
        }
    }

    StackView {
        id: stackView
        anchors.fill: parent
    }
}
