// En Qt 6 se recomienda omitir la versión en los imports (el motor resuelve
// la versión compatible más reciente del módulo automáticamente).
import QtQuick
import QtQuick.Window

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Client Management")

    Text {
        text: masterController.ui_welcomeMessage
    }
}
