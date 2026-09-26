# cm-tests — Pruebas unitarias con Qt Test (equivalente al antiguo cm-tests.pro).
#
# Cambios frente a qmake:
#   * QT += testlib / QT -= gui -> find_package(Qt6 COMPONENTS Test Core).
#   * CONFIG += console, CONFIG -= app_bundle -> innecesario en CMake en
#     plataformas no-Windows; basta con un objetivo normal que enlaza Qt6::Test.
#   * El moc del fichero .moc incluido al final del fuente lo gestiona AUTOMOC
#     (activado por qt_standard_project_setup()).

find_package(Qt6 REQUIRED COMPONENTS Test Core)

qt_add_executable(client-tests
    source/models/client-tests.cpp
)

target_link_libraries(client-tests PRIVATE
    Qt6::Test
    Qt6::Core
    cm-lib
)

# Registrar la prueba con CTest: permite ejecutarla con "ctest" desde el
# árbol de build (equivalente moderno a "make check" con qmake).
add_test(NAME client-tests COMMAND client-tests)
