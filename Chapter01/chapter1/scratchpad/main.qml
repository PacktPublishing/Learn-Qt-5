// main.qml — Interfaz del Scratchpad, migrada a Qt 6.
//
// Cambios frente a la versión de Qt 5:
//   * Antes se importaba con números de versión ("import QtQuick 2.9",
//     "import QtQuick.Window 2.3"). En Qt 6 se usan imports sin número de
//     versión ("dotless": QtQuick, QtQuick.Window) que resuelven
//     automáticamente contra la versión mayor de Qt con la que se compiló
//     la aplicación (6.x).
//   * El fichero ya no se referencia desde qml.qrc; ahora forma parte del
//     módulo QML "Scratchpad" definido en CMakeLists.txt.

import QtQuick
import QtQuick.Window

Window {
    id: root
    visible: true
    width: 1024
    height: 768
    title: qsTr("Scratchpad")
    color: "#ffffff"

    // Text sigue siendo el tipo básico de texto de QtQuick también en Qt 6.
    Text {
        id: message
        anchors.centerIn: parent
        font.pixelSize: 44
        text: qsTr("Hello Qt Scratchpad!")
        color: "#008000"
    }
}
