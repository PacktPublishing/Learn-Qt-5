# cm-lib — Librería compartida (equivalente al antiguo cm-lib.pro).
#
# Cambios frente a qmake:
#   * QT -= gui              -> solo se enlaza Qt6::Core.
#   * DEFINES += CMLIB_LIBRARY -> target_compile_definitions(... PRIVATE ...)
#   * DESTDIR/OBJECTS_DIR/MOC_DIR -> gestionados por el árbol de build de CMake.
#   * navigation-controller.h estaba declarado en HEADERS pero NO se compilaba:
#     al no pasar por moc, sus señales nunca existían en tiempo de ejecución y
#     el Connections del QML fallaba. Aquí se añade a la lista de fuentes para
#     que AUTOMOC genere su código de señales (corrección del bug original).

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_library(cm-lib SHARED
    source/cm-lib_global.h
    source/models/client.h
    source/models/client.cpp
    source/controllers/master-controller.h
    source/controllers/master-controller.cpp
    source/controllers/navigation-controller.h
)

# Los fuentes incluyen cabeceras relativas a "source/" (p. ej. <cm-lib_global.h>
# y <controllers/master-controller.h> desde cm-ui y cm-tests).
target_include_directories(cm-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)

# CMLIB_LIBRARY activa Q_DECL_EXPORT al compilar la librería; los consumidores
# (cm-ui, cm-tests) reciben Q_DECL_IMPORT al enlazar el objetivo.
target_compile_definitions(cm-lib PRIVATE CMLIB_LIBRARY)

target_link_libraries(cm-lib PUBLIC Qt6::Core)
