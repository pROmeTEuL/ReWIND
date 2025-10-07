import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    RoundButton {
        text: "Open Menu"
        onClicked: drawer.open()
    }

    Drawer {
        id: drawer
        width: parent.width * 0.4
        height: parent.height
        edge: Qt.LeftEdge

        ColumnLayout {
            anchors.fill: parent
            ListView {
                Layout.fillHeight: true
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
