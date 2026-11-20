import ReWIND

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: "ReWIND"
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
                    stackView.push("EditSchedulePage.qml")
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
                        text: model._name
                    }
                    Item {
                        Layout.fillWidth: true
                    }
                    RoundButton {
                        text: "View"
                        onClicked: {
                            while(stackView.depth > 1) {
                                stackView.pop()
                            }
                            stackView.push("PreviewSchedulePage.qml")
                            drawer.close()
                        }
                    }
                }

                model: ScheduleModel {}
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
                        stackView.push("EditSchedulePage.qml")
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
