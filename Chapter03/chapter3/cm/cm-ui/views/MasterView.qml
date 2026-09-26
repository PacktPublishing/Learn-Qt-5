// MasterView.qml — Vista maestra migrada a Qt 6 (Capítulo 3).
//
// Cambios frente a la versión de Qt 5:
//   * Imports sin número de versión (import QtQuick / QtQuick.Window /
//     QtQuick.Controls): en Qt 6 es la forma recomendada.
//   * Ya no existen las rutas "qrc:/views/XxxView.qml": al empaquetarse las
//     vistas con qt_add_qml_module(), se referencian por el NOMBRE DEL TIPO
//     ("DashboardView", "SplashView", ...), resueltas dentro del módulo CM.Views.
//   * Los handlers de Connections usan la sintaxis moderna de funciones
//     (function onGoXxx()), obligatoria desde Qt 6 para señales con argumentos.

import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Client Management")

    // Equivalente a contentFrame.replace("qrc:/views/DashboardView.qml"):
    // ahora se pasa el nombre del tipo QML registrado en el módulo.
    Component.onCompleted: contentFrame.replace("DashboardView");

    Connections {
        target: masterController.ui_navigationController
        function onGoCreateClientView() { contentFrame.replace("CreateClientView") }
        function onGoDashboardView()    { contentFrame.replace("DashboardView") }
        function onGoEditClientView(client) { contentFrame.replace("EditClientView", {selectedClient: client}) }
        function onGoFindClientView()   { contentFrame.replace("FindClientView") }
    }

    Rectangle {
        id: navigationBar
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        width: 100
        color: "#000000"

        Column {
            Button {
                text: "Dashboard"
                onClicked: masterController.ui_navigationController.goDashboardView()
            }
            Button {
                text: "New Client"
                onClicked: masterController.ui_navigationController.goCreateClientView()
            }
            Button {
                text: "Find Client"
                onClicked: masterController.ui_navigationController.goFindClientView()
            }
        }
    }

    StackView {
        id: contentFrame
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        initialItem: "SplashView"   // nombre de tipo del módulo CM.Views
        clip: true
    }
}
