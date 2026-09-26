// En Qt 6 se recomienda omitir la versión en los imports: el motor resuelve
// automáticamente la versión compatible más reciente del módulo.
import QtQuick

Item {
    Rectangle {
        anchors.fill: parent
        color: "#f4c842"
        Text {
            anchors.centerIn: parent
            text: "Find Client"
        }
    }
}
