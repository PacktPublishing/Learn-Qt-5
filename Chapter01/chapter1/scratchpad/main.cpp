// main.cpp — Punto de entrada del "Scratchpad" migrado a Qt 6 (CMake).
//
// Cambios frente a la versión original de Qt 5 (capítulo 1 de "Learn Qt 5"):
//   1. Se fija la identidad de la aplicación (nombre/organización/dominio),
//      práctica recomendada en Qt 6 para QSettings y servicios del SO.
//   2. El QML ya no se carga desde "qrc:/main.qml" (qml.qrc + qmake), sino
//      desde el módulo QML declarado con qt_add_qml_module en CMakeLists.txt,
//      usando QQmlApplicationEngine::loadFromModule().
//   3. Se conecta objectCreationFailed para abortar de forma limpia si el
//      QML no puede cargarse (patrón de las plantillas oficiales de Qt 6).

#include <QGuiApplication>            // Base de toda app Qt sin widgets
#include <QQmlApplicationEngine>      // Motor que instancia el árbol QML

int main(int argc, char *argv[])
{
    // Como en Qt 5, QGuiApplication debe crearse antes que cualquier objeto GUI.
    QGuiApplication app(argc, argv);

    // Identidad de la aplicación (recomendado en Qt 6):
    app.setApplicationName(QStringLiteral("Scratchpad"));
    app.setOrganizationName(QStringLiteral("LearnQt"));
    app.setOrganizationDomain(QStringLiteral("learnqt.example.com"));

    QQmlApplicationEngine engine;

    // Si la creación del objeto raíz falla, salimos con código de error en vez
    // de dejar una aplicación "zombie" sin ventana.
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // Equivalente moderno de: engine.load(QUrl("qrc:/main.qml"));
    // "Scratchpad" es la URI del módulo y "Main" el fichero main.qml registrado
    // en CMakeLists.txt mediante qt_add_qml_module().
    engine.loadFromModule("Scratchpad", "Main");

    return app.exec();
}
