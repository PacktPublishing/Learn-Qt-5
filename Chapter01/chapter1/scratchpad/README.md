# Scratchpad (Capítulo 1) — migrado a Qt 6

Versión moderna del primer ejemplo de *Learn Qt 5*: una ventana con un texto
centrado. El proyecto original usaba **QMake** (`scratchpad.pro`) y QML con
imports versionados (`import QtQuick 2.9`); esta versión usa **CMake** e
imports sin versión, siguiendo las plantillas oficiales de Qt 6 (compatible
con la serie 6.8 LTS en adelante, incluida Qt 6.11).

## Ficheros

- `CMakeLists.txt` — definición del proyecto (sustituye a `scratchpad.pro`).
- `main.cpp`       — punto de entrada; carga el QML por módulo (`loadFromModule`).
- `main.qml`       — interfaz (Window + Text), ahora dentro del módulo QML `Scratchpad`.
- `TUTORIAL.md`    — explicación paso a paso de la migración (antes → después).

## Compilar

```bash
cmake -B build -DCMAKE_PREFIX_PATH=/ruta/a/Qt/6.x/gcc_64
cmake --build build
./build/Scratchpad
```

O simplemente abre `CMakeLists.txt` en Qt Creator con un kit Qt 6.

Consulta **TUTORIAL.md** para entender cada cambio respecto a Qt 5.
