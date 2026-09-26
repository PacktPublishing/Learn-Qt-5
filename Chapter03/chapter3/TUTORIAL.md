# Tutorial: migración del Capítulo 3 de Qt 5 a Qt 6.11

El Capítulo 3 de *Learn Qt 5* introduce dos piezas nuevas respecto al capítulo 2:

1. **`cm`**: la aplicación MVC crece con navegación real — un `StackView` con seis
   vistas (`MasterView`, `SplashView`, `DashboardView`, `CreateClientView`,
   `EditClientView`, `FindClientView`) y un `NavigationController` cuyas señales
   piden cambios de vista al QML.
2. **`scratchpad`**: demos para aprender el posicionamiento declarativo de QML
   (`AnchorsDemo.qml` y `SizingDemo.qml`: anclajes, implícitos vs. explícitos).

La migración a Qt 6 afecta sobre todo al **sistema de construcción** (qmake →
CMake) y a la **carga de los QML** (`qrc:/ruta.qml` → módulo QML + tipos). El
código C++ de modelos y controladores apenas cambia.

## Estructura final

```
chapter3/
├── TUTORIAL.md                 ← este documento
├── README.md                   ← resumen y cómo compilar
├── cm/
│   ├── CMakeLists.txt          ← nuevo (reemplaza a cm.pro + los .pri)
│   ├── cm-lib/
│   │   ├── CMakeLists.txt      ← nuevo (reemplaza a cm-lib.pro)
│   │   └── source/...          ← sin cambios
│   ├── cm-ui/
│   │   ├── CMakeLists.txt      ← nuevo (reemplaza a cm-ui.pro + views.qrc)
│   │   ├── source/main.cpp     ← adaptado
│   │   └── views/*.qml         ← imports sin versión + navegación por tipo
│   └── cm-tests/
│       ├── CMakeLists.txt      ← nuevo (reemplaza a cm-tests.pro)
│       └── source/...          ← sin cambios
└── scratchpad/
    ├── CMakeLists.txt          ← nuevo (reemplaza a scratchpad.pro + qml.qrc)
    ├── main.cpp                ← adaptado (loadFromModule)
    ├── main.qml / SizingDemo.qml / AnchorsDemo.qml  ← imports sin versión
```

Eliminado: todos los `.pro`/`.pro.user*`, `views.qrc`, `qml.qrc`, los `.pri`
auxiliares de qmake y las carpetas `binaries/` y `build/` con artefactos `.o`,
`.dll`, `.exe` y `.moc` compilados contra Qt 5 (los binarios no se versionan).

## 1. Navegación por nombre de tipo en lugar de rutas qrc

Este es el cambio conceptual más importante del capítulo. Con qmake, las vistas
vivían en un `views.qrc` y el `StackView` se manejaba con URLs:

```qml
// Qt 5 (qmake + views.qrc)
initialItem: "qrc:/views/SplashView.qml"
contentFrame.replace("qrc:/views/DashboardView.qml")
```

Con `qt_add_qml_module()` cada fichero QML pasa a ser un **tipo registrado**
dentro del módulo `CM.Views`, así que basta el nombre del fichero sin extensión:

```qml
// Qt 6 (CMake + qt_add_qml_module)
initialItem: "SplashView"
contentFrame.replace("DashboardView")
```

Y en C++, la raíz ya no se carga con una URL sino desde el módulo:

```cpp
engine.loadFromModule("CM.Views", "MasterView");   // era: engine.load("qrc:/views/MasterView.qml")
```

## 2. `Connections`: sintaxis de funciones (obligatoria en Qt 6)

El `MasterView.qml` original usaba handlers como propiedades:

```qml
// Qt 5
onGoEditClientView: contentFrame.replace("qrc:/views/EditClientView.qml", {selectedClient: client})
```

En Qt 6 ese estilo está obsoleto y **falla** con señales que tienen argumentos
(como `goEditClientView(cm::models::Client*)`). La forma moderna declara
funciones cuyo parámetro recibe directamente la señal:

```qml
// Qt 6
function onGoEditClientView(client) { contentFrame.replace("EditClientView", {selectedClient: client}) }
```

## 3. Corrección de un bug silencioso del proyecto original

En `cm-lib.pro`, `navigation-controller.h` estaba listado en `HEADERS` pero
ningún `.cpp` lo compilaba, por lo que **moc nunca generaba su código de
señales**: `goDashboardView()`, `goCreateClientView()`, etc. no existían en
tiempo de ejecución (el libro lo resuelve en capítulos posteriores añadiendo su
`.cpp`). En el `CMakeLists.txt` de Qt 6 incluimos la cabecera entre las fuentes
de `qt_add_library()`: AUTOMOC procesa los headers con `Q_OBJECT` y genera las
señales, de modo que la navegación funciona desde ya.

## 4. Imports QML sin versión

Todos los ficheros QML pasan de `import QtQuick 2.9` / `QtQuick.Window 2.2` /
`QtQuick.Controls 2.2` a imports sin número:

```qml
import QtQuick
import QtQuick.Window
import QtQuick.Controls
```

El motor resuelve automáticamente la versión compatible más reciente (en Qt
6.11, QtQuick 6.11), evitando obsolescencia prematura del código.

## 5. El scratchpad: una app, varias demos

`scratchpad/main.cpp` original cargaba `qrc:/SizingDemo.qml`. En Qt 6 las tres
demos (`main.qml` → tipo `Main`, `SizingDemo.qml`, `AnchorsDemo.qml`) se
registran en el módulo `Scratchpad` y se elige la raíz en una sola línea:

```cpp
engine.loadFromModule("Scratchpad", "SizingDemo");  // o "AnchorsDemo", o "Main"
```

Las demos de anclajes y dimensionado (`anchors.centerIn`, `verticalCenterOffset`,
`implicitWidth/Height`, `wrapMode`...) son 100 % compatibles con Qt 6: solo se
retiraron los números de versión de sus imports.

## 6. Compilar y ejecutar

```bash
# Proyecto cm (librería + UI + tests)
cd Chapter03/chapter3/cm
cmake -B build -DCMAKE_PREFIX_PATH=/ruta/a/Qt/6.11/gcc_64
cmake --build build
./build/cm-ui/cm-ui            # ejecuta la aplicación
ctest --test-dir build          # ejecuta client-tests

# Scratchpad
cd ../scratchpad
cmake -B build && cmake --build build
./build/scratchpad/scratchpad
```

También abre cualquiera de los dos `CMakeLists.txt` directamente en Qt Creator 11+
(seleccionando el kit Qt 6.11).

## Errores típicos al migrar este capítulo

| Síntoma | Causa | Solución |
|---|---|---|
| `Type SplashView unavailable` / pantalla en negro | Se sigue usando `"qrc:/views/..."` | Usar el nombre de tipo (`"SplashView"`) con `qt_add_qml_module` |
| `Connections: signal handler as property is not supported` | Sintaxis antigua `onGoXxx: ...` | Convertir a `function onGoXxx(...)` |
| Las señales de `NavigationController` no existen | Header con `Q_OBJECT` fuera del build | Incluirlo en `qt_add_library()` para que AUTOMOC lo procese |
| `No module named "QtQuick.Window 2.2"` | Imports versionados de Qt 5 | Imports sin versión |
| Enlazar `-lcm-lib` falla en Linux | Rutas `DESTDIR` de qmake | `target_link_libraries(cm-ui PRIVATE cm-lib)` |

## Compatibilidad

Todo el código usa APIs estables disponibles desde Qt 6.4+ (`loadFromModule`,
`objectCreationFailed`, `qt_add_qml_module`, `qt_standard_project_setup`), por
lo que compila sin cambios en la serie actual, incluida **Qt 6.11**.
