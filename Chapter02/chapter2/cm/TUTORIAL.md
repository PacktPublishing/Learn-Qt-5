# Tutorial: migración del Capítulo 2 (proyecto `cm`) de Qt 5 a Qt 6

Este capítulo presenta por primera vez una **arquitectura MVC multi-módulo**:
una librería compartida (`cm-lib`) con modelos y controladores, una interfaz
QML (`cm-ui`) y pruebas unitarias (`cm-tests`). La migración a Qt 6 afecta
sobre todo al **sistema de construcción** (qmake → CMake); el código C++ y QML
casi no cambia.

## Estructura final

```
cm/
├── CMakeLists.txt          ← nuevo (reemplaza a cm.pro + los .pri)
├── TUTORIAL.md             ← este documento
├── cm-lib/
│   ├── CMakeLists.txt      ← nuevo (reemplaza a cm-lib.pro)
│   └── source/...          ← sin cambios
├── cm-ui/
│   ├── CMakeLists.txt      ← nuevo (reemplaza a cm-ui.pro + views.qrc)
│   └── source/main.cpp     ← adaptado
│       views/MasterView.qml← imports sin versión
└── cm-tests/
    ├── CMakeLists.txt      ← nuevo (reemplaza a cm-tests.pro)
    └── source/...          ← sin cambios
```

Eliminado además: `binaries/` y las carpetas `build/` con artefactos `.o/.exe/.dll`
(binarios compilados contra Qt 5 que no deben versionarse), `cm.pro.user*`
configuración local de Qt Creator ligada a Qt 5, y los `.pri` auxiliares de
plataforma/rutas, innecesarios en CMake.

## 1. Del proyecto `subdirs` de qmake a CMake

Antes, `cm.pro` solo declaraba `TEMPLATE = subdirs` y dos `.pri` calculaban
rutas de salida por plataforma (`DESTDIR`, `MOC_DIR`, ...). En CMake eso es
redondante: cada objetivo escribe sus artefactos dentro del árbol de build
que el propio CMake gestiona, y las dependencias entre módulos se declaran
enlazando objetivos entre sí. El `CMakeLists.txt` raíz queda reducido a:

```cmake
qt_standard_project_setup()
add_subdirectory(cm-lib)
add_subdirectory(cm-ui)
add_subdirectory(cm-tests)
```

## 2. `cm-lib`: la librería compartida

| qmake | CMake / Qt 6 |
|---|---|
| `TEMPLATE = lib` | `qt_add_library(cm-lib SHARED ...)` |
| `QT -= gui` | enlazar solo `Qt6::Core` |
| `DEFINES += CMLIB_LIBRARY` | `target_compile_definitions(cm-lib PRIVATE CMLIB_LIBRARY)` |
| `INCLUDEPATH += source` | `target_include_directories(cm-lib PUBLIC .../source)` |
| `LIBS += -L... -lcm-lib` (en consumidores) | `target_link_libraries(consumidor PRIVATE cm-lib)` |

Detalle clave: el modificador **`PUBLIC`** en los includes y en
`Qt6::Core` hace que `cm-ui` y `cm-tests` hereden automáticamente los
directorios de cabeceras al enlazar `cm-lib` — sustituye a los `INCLUDEPATH`
y `LIBS` repetidos en cada `.pro`. El macro `CMLIBSHARED_EXPORT`
(`Q_DECL_EXPORT/Q_DECL_IMPORT`) sigue funcionando igual en Qt 6; como solo
exporta clases `QObject`, no hay nada que cambiar.

## 3. `cm-ui`: la aplicación QML

- **`views.qrc` desaparece.** `qt_add_qml_module()` empaqueta `MasterView.qml`
  en los recursos del ejecutable y genera el registro del módulo `CM.Views`.
- **Carga del QML:** `engine.load("qrc:/views/MasterView.qml")` se sustituye
  por `engine.loadFromModule("CM.Views", "MasterView")` (disponible desde
  Qt 6.4), el patrón de las plantillas oficiales.
- **Alta DPI:** `Qt::AA_EnableHighDpiScaling` **ya no existe en Qt 6** (el
  escalado por DPI es siempre activo); se elimina el bloque `#if defined(Q_OS_WIN)`.
- **Errores de carga:** la comprobación manual
  `if (engine.rootObjects().isEmpty()) return -1;` se reemplaza conectando
  la señal `QQmlApplicationEngine::objectCreationFailed`.
- `qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, ...)` y la
  `setContextProperty("masterController", ...)` se conservan tal cual: ambas
  APIs siguen vigentes en Qt 6 y son parte de la lección del capítulo.
- En `MasterView.qml`, los imports con versión fija (`QtQuick 2.9`,
  `QtQuick.Window 2.2`) pasan a ser **imports sin versión**, estilo recomendado
  en Qt 6.

## 4. `cm-tests`: pruebas con Qt Test

`QT += testlib` → `find_package(Qt6 COMPONENTS Test)` + enlace a `Qt6::Test`.
El fuente `client-tests.cpp` no cambia: `QTEST_APPLESS_MAIN` y el
`#include "client-tests.moc"` siguen siendo válidos, y AUTOMOC (activado por
`qt_standard_project_setup()`) genera ese fichero `.moc` automáticamente.
Además registramos la prueba con **CTest** (`add_test(...)`), equivalente
moderno de `make check`.

## Cómo compilar y ejecutar

```bash
cd Chapter02/chapter2/cm
cmake -B build -DCMAKE_PREFIX_PATH=/ruta/a/Qt/6.11/gcc_64
cmake --build build
./build/bin/cm-ui            # o build/cm-ui/cm-ui según generador
ctest --test-dir build       # ejecuta client-tests
```

En Qt Creator basta con abrir `CMakeLists.txt` y seleccionar un kit con Qt ≥ 6.5
(idealmente la serie 6.8 LTS o 6.11).

## Errores típicos al migrar este capítulo

| Síntoma | Causa / solución |
|---|---|
| `No such file or directory: cm-lib_global.h` | Falta `target_include_directories(cm-lib PUBLIC .../source)` |
| Símbolos sin exportar al enlazar en Windows | Compilar `cm-lib` con `CMLIB_LIBRARY` en modo `PRIVATE` y enlazar el objetivo, no `-lcm-lib` a mano |
| `module "CM.Views" is not installed` | La URI de `loadFromModule()` debe coincidir exactamente con `URI` de `qt_add_qml_module()` |
| `AA_EnableHighDpiScaling` no compila | Eliminado en Qt 6; el escalado High-DPI es automático |
| Ventana no aparece pero no hay errores | Conectar `objectCreationFailed`; el `engine.load` silencioso era un fallo clásico de Qt 5 |
