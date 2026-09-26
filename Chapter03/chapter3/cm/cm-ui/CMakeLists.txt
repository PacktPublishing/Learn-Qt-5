# cm-ui — Aplicación QML (equivalente al antiguo cm-ui.pro).
#
# Cambios frente a qmake:
#   * QT += qml quick       -> find_package(... Qml Quick) + Qt6::Qml/Qt6::Quick.
#   * RESOURCES += views.qrc -> sustituido por qt_add_qml_module(): empaqueta las
#     seis vistas y genera el registro de tipos del módulo "CM.Views". Las rutas
#     "qrc:/views/XxxView.qml" del StackView pasan a ser nombres de tipo ("XxxView").
#   * LIBS += -lcm-lib      -> target_link_libraries(... cm-lib), que además
#     arrastra los include dirs y definiciones de la librería.

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(cm-ui
    source/main.cpp
)

# Módulo QML con las vistas. En main.cpp la raíz se carga con
# loadFromModule("CM.Views", "MasterView") en lugar de engine.load("qrc:/...").
qt_add_qml_module(cm-ui
    URI CM.Views
    VERSION 1.0
    QML_FILES
        views/MasterView.qml
        views/SplashView.qml
        views/DashboardView.qml
        views/CreateClientView.qml
        views/EditClientView.qml
        views/FindClientView.qml
)

target_link_libraries(cm-ui PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    cm-lib
)

# Sin consola en Windows y empaquetado .app en macOS (plantillas oficiales Qt 6).
set_target_properties(cm-ui PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
