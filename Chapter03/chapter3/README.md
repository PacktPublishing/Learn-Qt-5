# Capítulo 3 — Learn Qt (migrado a Qt 6)

Dos proyectos, ambos construidos con **CMake** (Qt 6.11):

* **`cm/`** — Aplicación "Client Management" con arquitectura MVC completa:
  librería compartida (`cm-lib`), interfaz QML con barra de navegación y
  `StackView` de seis vistas (`cm-ui`) y pruebas unitarias (`cm-tests`).
* **`scratchpad/`** — Demos de aprendizaje de posicionamiento declarativo en
  QML: `AnchorsDemo.qml` (anclajes) y `SizingDemo.qml` (tamaños implícitos vs.
  explícitos, `wrapMode`).

Compilar:

```bash
cd cm && cmake -B build && cmake --build build        # luego ./build/cm-ui/cm-ui
cd ../scratchpad && cmake -B build && cmake --build build
```

Consulta el **TUTORIAL.md** de este directorio para la explicación paso a paso
de la migración desde Qt 5/qmake.
