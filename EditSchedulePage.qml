import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    parent: mainFrame
    Component.onCompleted: {
        editButton.visible = false
    }
    Label {
        text: "test"
    }
}
