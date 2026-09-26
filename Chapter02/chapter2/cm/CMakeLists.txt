# cm — Proyecto raíz (equivalente al antiguo "cm.pro" con TEMPLATE = subdirs).
#
# En Qt 6 el sistema de construcción oficial es CMake; QMake quedó en modo
# mantenimiento. Este fichero reemplaza a cm.pro y a los .pri auxiliares
# (qmake-target-platform.pri / qmake-destination-path.pri), que ya no son
# necesarios: CMake gestiona de forma multiplataforma las rutas de salida,
# la plataforma y el compilador.

cmake_minimum_required(VERSION 3.21)

project(cm VERSION 1.0 LANGUAGES CXX)

# Qt 6 exige C++17 como mínimo (el original usaba CONFIG += c++14).
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configuración recomendada por Qt para proyectos CMake (AUTOMOC, políticas...).
qt_standard_project_setup()

# Orden sin importancia real: CMake resuelve las dependencias entre objetivos
# automáticamente gracias a target_link_libraries().
add_subdirectory(cm-lib)    # librería compartida (modelos + controladores)
add_subdirectory(cm-ui)     # aplicación QML que enlaza con cm-lib
add_subdirectory(cm-tests)  # pruebas unitarias (Qt Test) sobre cm-lib
