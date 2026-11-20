import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property int index: -1
    property string name
    parent: mainFrame
    Component.onCompleted: {
        editButton.visible = true
    }
    Label {
        text: name
    }

    ListView {

    }
}
