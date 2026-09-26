# cm-lib — Librería compartida (equivalente al antiguo cm-lib.pro).
#
# Cambios frente a qmake:
#   * QT -= gui            -> solo se enlaza Qt6::Core.
#   * DEFINES += CMLIB_LIBRARY -> target_compile_definitions(... PRIVATE ...)
#   * DESTDIR/OBJECTS_DIR/...  -> gestionados por el árbol de build de CMake.

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_library(cm-lib SHARED
    source/cm-lib_global.h
    source/models/client.h
    source/models/client.cpp
    source/controllers/master-controller.h
    source/controllers/master-controller.cpp
)

# Los fuentes incluyen cabeceras relativas a "source/" (p. ej. <cm-lib_global.h>
# y <controllers/master-controller.h> desde cm-ui y cm-tests).
target_include_directories(cm-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

# CMLIB_LIBRARY activa Q_DECL_EXPORT al compilar la librería; los consumidores
# (cm-ui, cm-tests) reciben automáticamente Q_DECL_IMPORT al usar la interfaz
# pública del objetivo (exportado mediante generator expressions por defecto
# en qt_add_library con WINDOWS_EXPORT_ALL_SYMBOLS desactivado).
target_compile_definitions(cm-lib PRIVATE CMLIB_LIBRARY)

target_link_libraries(cm-lib PUBLIC Qt6::Core)
