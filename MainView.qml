import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    RoundButton {
        text: "Open Menu"
        onClicked: drawer.open()
    }
}
