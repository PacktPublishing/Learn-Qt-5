# Capítulo 2 — Proyecto `cm` (Client Management), migrado a Qt 6

Ejemplo de *Learn Qt 5* (Richard Warburton) actualizado a Qt 6 con CMake.
Introduce la arquitectura MVC multi-módulo:

- **cm-lib**: librería compartida con modelos (`Client`) y controladores
  (`MasterController`, que expone `ui_welcomeMessage` al QML).
- **cm-ui**: aplicación Qt Quick que muestra `MasterView.qml` y recibe el
  controlador como *context property*.
- **cm-tests**: prueba unitaria mínima con Qt Test, integrada en CTest.

Consulta `TUTORIAL.md` para una explicación paso a paso de la migración
qmake → CMake y Qt 5 → Qt 6.

## Compilar

```bash
cmake -B build && cmake --build build
ctest --test-dir build
```

Requiere Qt 6.5+ (recomendado 6.8 LTS o superior) y CMake ≥ 3.21.
