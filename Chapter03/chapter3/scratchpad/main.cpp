// main.cpp — Scratchpad del Capítulo 3 migrado a Qt 6.
//
// Cambios frente a la versión original de Qt 5:
//   1. Se fija la identidad de la aplicación (recomendación oficial en Qt 6).
//   2. QQmlApplicationEngine::objectCreationFailed sustituye a la comprobación
//      manual de rootObjects() (patrón de las plantillas nuevas de Qt 6).
//   3. engine.load("qrc:/SizingDemo.qml") se reemplaza por
//      engine.loadFromModule("Scratchpad", "SizingDemo"): los ficheros QML ya
//      no viven en un .qrc, sino en el módulo registrado por qt_add_qml_module().
//   4. Para probar otra demo basta con cambiar el segundo argumento:
//      "Main", "SizingDemo" o "AnchorsDemo".

#include <QGuiApplication>            // Base de toda app Qt Quick sin widgets
#include <QQmlApplicationEngine>      // Motor que instancia el árbol QML

int main(int argc, char *argv[])
{
        QGuiApplication app(argc, argv);

        // Identidad de la aplicación (recomendado en Qt 6):
        app.setApplicationName(QStringLiteral("Scratchpad"));
        app.setOrganizationName(QStringLiteral("LearnQt"));

        QQmlApplicationEngine engine;

        // Si el objeto raíz no puede crearse, salimos limpiamente con error.
        QObject::connect(
            &engine, &QQmlApplicationEngine::objectCreationFailed,
            &app, []() { QCoreApplication::exit(-1); },
            Qt::QueuedConnection);

        // Equivalente a: engine.load(QUrl("qrc:/SizingDemo.qml"));
        engine.loadFromModule("Scratchpad", "SizingDemo");

        return app.exec();
}
