// main.cpp — Punto de entrada de cm-ui migrado a Qt 6.
//
// Cambios frente a la versión original de Qt 5 (capítulo 2 de "Learn Qt 5"):
//   1. AA_EnableHighDpiScaling ya NO existe en Qt 6: el escalado por DPI es
//      automático, por lo que se elimina el bloque #if defined(Q_OS_WIN).
//   2. qmlRegisterType<MasterController>("CM", 1, 0, ...) sigue siendo válido
//      en Qt 6, pero como MasterController solo se expone como instancia
//      (context property), basta con mantenerlo; se conserva tal cual.
//   3. El QML ya no se carga desde "qrc:/views/MasterView.qml" (views.qrc +
//      qmake), sino desde el módulo QML declarado con qt_add_qml_module() en
//      CMakeLists.txt, usando QQmlApplicationEngine::loadFromModule().
//   4. Se conecta objectCreationFailed para salir limpiamente si falla la
//      creación del objeto raíz (patrón de las plantillas oficiales de Qt 6),
//      sustituyendo la comprobación manual rootObjects().isEmpty().

#include <QGuiApplication>            // Base de toda app Qt Quick sin widgets
#include <QQmlApplicationEngine>      // Motor que instancia el árbol QML
#include <QQmlContext>                // rootContext()->setContextProperty()

#include <controllers/master-controller.h>

int main(int argc, char *argv[])
{
        QGuiApplication app(argc, argv);

        // Identidad de la aplicación (recomendado en Qt 6):
        app.setApplicationName(QStringLiteral("cm"));
        app.setOrganizationName(QStringLiteral("LearnQt"));

        // Registro del tipo ante el motor QML (igual que en Qt 5; la API
        // qmlRegisterType<T>() sigue vigente en Qt 6).
        qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");

        // Instancia única del controlador expuesta al QML como propiedad de
        // contexto "masterController".
        cm::controllers::MasterController masterController;

        QQmlApplicationEngine engine;
        engine.rootContext()->setContextProperty("masterController", &masterController);

        // Equivalente moderno a la comprobación manual de rootObjects():
        // si el objeto raíz no puede crearse, terminamos con código de error.
        QObject::connect(
            &engine, &QQmlApplicationEngine::objectCreationFailed,
            &app, []() { QCoreApplication::exit(-1); },
            Qt::QueuedConnection);

        // Equivalente a: engine.load(QUrl("qrc:/views/MasterView.qml"));
        // "CM.Views" es la URI del módulo y "MasterView" el fichero registrado
        // en cm-ui/CMakeLists.txt mediante qt_add_qml_module().
        engine.loadFromModule("CM.Views", "MasterView");

        return app.exec();
}
