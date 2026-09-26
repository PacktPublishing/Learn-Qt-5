# cm-ui — Aplicación QML (equivalente al antiguo cm-ui.pro).
#
# Cambios frente a qmake:
#   * QT += qml quick     -> find_package(... Qml Quick) + Qt6::Qml/Qt6::Quick.
#   * RESOURCES += views.qrc -> sustituido por qt_add_qml_module(), que empaqueta
#     MasterView.qml y genera el registro de tipos del módulo "CM.Views".
#   * LIBS += -lcm-lib    -> target_link_libraries(... cm-lib), que además
#     arrastra automáticamente los include dirs y definiciones de la librería.

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(cm-ui
    source/main.cpp
)

# Módulo QML con las vistas. URI "CM.Views": en main.qml ya no se carga con
# engine.load("qrc:/views/MasterView.qml") sino con loadFromModule("CM.Views", "MasterView").
qt_add_qml_module(cm-ui
    URI CM.Views
    VERSION 1.0
    QML_FILES views/MasterView.qml
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
