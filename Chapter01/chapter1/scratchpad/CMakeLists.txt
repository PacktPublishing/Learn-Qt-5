cmake_minimum_required(VERSION 3.21)

project(Scratchpad VERSION 1.0 LANGUAGES CXX)

# Qt 6 exige C++17 como mínimo.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Busca los componentes de Qt 6 que necesitamos:
#   Core       -> tipos básicos (QString, QUrl...)
#   Gui        -> QGuiApplication
#   Qml        -> QQmlApplicationEngine
#   Quick      -> tipos QML como Window y Text
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

# Configuración recomendada por Qt para proyectos CMake (políticas, AUTOMOC, etc.).
qt_standard_project_setup()

qt_add_executable(Scratchpad
    main.cpp
)

# Definimos un módulo QML: agrupa el ejecutable y sus ficheros QML.
# En Qt 6 ya no se usa qml.qrc: qt_add_qml_module empaqueta main.qml dentro
# de la resource del módulo y genera el registro de tipos automáticamente.
qt_add_qml_module(Scratchpad
    URI Scratchpad          # nombre del módulo usado en "import Scratchpad"
    VERSION 1.0
    QML_FILES main.qml
)

target_link_libraries(Scratchpad PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

# Sin consola en Windows y empaquetado .app en macOS (comportamiento habitual
# en las plantillas oficiales de Qt for Qt Design / Creator).
set_target_properties(Scratchpad PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
