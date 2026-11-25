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
                id: drawerButton
                text: "Open Menu"
                onClicked: drawer.open()
            }
            RoundButton {
                id: backButton
                text: "↩"
                visible: false
                onClicked: {
                    if (stackView.depth > 1)
                        stackView.pop();
                }
            }
            Item {
                Layout.fillWidth: true
            }
            // TODO: mend horizontal alignment
            Label {
                id: frameTitle
                text: "ReWIND"
                font.pixelSize: 30
                Layout.alignment: Qt.AlignHCenter
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
                    TapHandler {
                        onTapped: {
                            while (stackView.depth > 1) {
                                stackView.pop()
                            }
                            stackView.push("PreviewSchedulePage.qml", {"index": index, "name": _name})
                            drawer.close()
                        }
                    }
                }

                model: scheduleModel
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
        // anchors.fill: parent
        Layout.fillHeight: true
        Layout.fillWidth: true
        initialItem: this
        onDepthChanged: {
            switch (stackView.depth) {
            case 1:
                console.log("Case 1");
                break;
            case 2:
                console.log("Case 2");
                backButton.visible = false;
                drawerButton.visible = true;
                drawer.enabled = true;
                drawer.interactive = true;
                editButton.visible = true;
                break;
            case 3:
                console.log("Case 3");
                backButton.visible = true;
                drawerButton.visible = false;
                drawer.enabled = false;
                drawer.interactive = false;
                editButton.visible = false;
                break;
            default:
                console.warn("StackView depth is" + stackView.depth);
                console.warn("Returning to Main Page");
                while (stackView.depth > 1)
                    stackView.pop();
            }
        }
        Component.onCompleted: {
            console.log("Curent item:\n" + currentItem)
            console.log("Depth: " + depth)
        }
    }

    ScheduleModel {
        id: scheduleModel
    }
}
