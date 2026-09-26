# Scratchpad — Capítulo 3 (equivalente al antiguo scratchpad.pro).
#
# Cambios frente a qmake (Qt 5):
#   * QT += qml quick          -> find_package(Qt6 COMPONENTS Qml Quick).
#   * CONFIG += c++14          -> C++17 (mínimo exigido por Qt 6).
#   * RESOURCES += qml.qrc     -> qt_add_qml_module(): empaqueta main.qml,
#     SizingDemo.qml y AnchorsDemo.qml y genera el registro de tipos.
#   * La carga ya no usa "qrc:/SizingDemo.qml" sino loadFromModule().

cmake_minimum_required(VERSION 3.21)

project(scratchpad VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

qt_standard_project_setup()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_add_executable(scratchpad
    main.cpp
)

qt_add_qml_module(scratchpad
    URI Scratchpad
    VERSION 1.0
    QML_FILES
        main.qml
        SizingDemo.qml
        AnchorsDemo.qml
)

target_link_libraries(scratchpad PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

set_target_properties(scratchpad PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
