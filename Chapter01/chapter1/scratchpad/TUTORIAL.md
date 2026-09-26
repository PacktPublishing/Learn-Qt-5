# Capítulo 1 — Scratchpad migrado a Qt 6 (tutorial)

Este fichero explica, paso a paso, cómo se migró el ejemplo *Scratchpad* del
capítulo 1 de *Learn Qt 5* (QMake + QML 2.9) a **Qt 6** con **CMake**, que es
el sistema de construcción recomendado oficialmente desde Qt 6.2 y la base de
las plantillas actuales de Qt Creator (Qt 6.8 LTS / Qt 6.9+).

## 1. Estructura del proyecto

| Antes (Qt 5)              | Ahora (Qt 6)                         | Por qué                                                                 |
|---------------------------|--------------------------------------|-------------------------------------------------------------------------|
| `scratchpad.pro`          | `CMakeLists.txt`                     | QMake está en modo mantenimiento; CMake es el sistema oficial de Qt 6.  |
| `qml.qrc`                 | *(eliminado)*                        | `qt_add_qml_module()` empaqueta los QML automáticamente; ya no hace falta un `.qrc` manual. |
| `scratchpad.pro.user`     | *(eliminado)*                        | Es configuración local de Qt Creator para una versión concreta de Qt 5; no es portable. |
| `main.cpp` (carga `qrc:/`) | `main.cpp` (carga por módulo)       | En Qt 6 las resources pasan a ser internas del módulo QML.              |
| `import QtQuick 2.9`      | `import QtQuick`                     | Los imports "dotless" resuelven contra la versión mayor de Qt usada al compilar. |

## 2. El fichero `CMakeLists.txt`, línea a línea

```cmake
cmake_minimum_required(VERSION 3.21)          # mínimo necesario para las funciones Qt6
project(Scratchpad VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)                    # Qt 6 exige C++17 como mínimo

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
qt_standard_project_setup()                   # fija políticas, AUTOMOC y helpers de Qt

qt_add_executable(Scratchpad main.cpp)        # crea el ejecutable

qt_add_qml_module(Scratchpad                  # define el módulo QML "Scratchpad"
    URI Scratchpad                            #   -> se importa con "import Scratchpad"
    VERSION 1.0
    QML_FILES main.qml                        #   -> main.qml queda registrado como tipo "Main"
)

target_link_libraries(Scratchpad PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)
```

Conceptos clave:

- **`qt_add_qml_module()`** sustituye a `RESOURCES += qml.qrc`. Empaqueta los
  ficheros QML dentro de la resource del binario y genera el *type registry*
  para que `engine.loadFromModule()` los encuentre.
- La **URI del módulo** (`Scratchpad`) es el nombre con el que otros ficheros
  QML podrían importar nuestros componentes reutilizables más adelante.
- Cada fichero `foo.qml` del módulo queda disponible como tipo `Foo`
  (primera letra mayúscula): `main.qml` → tipo **`Main`**.

## 3. El punto de entrada (`main.cpp`)

Cambios respecto al original de Qt 5:

```cpp
// Qt 5 (antes):
engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

// Qt 6 (ahora): carga desde el módulo QML declarado en CMake:
engine.loadFromModule("Scratchpad", "Main");
```

Además:

- Se fija la **identidad de la app** (`setApplicationName`, `setOrganizationName`,
  `setOrganizationDomain`), necesaria para `QSettings` y servicios del sistema
  en Qt 6.
- Se conecta la señal **`objectCreationFailed`** del motor: si el QML no puede
  crearse, la aplicación termina con error en lugar de quedarse sin ventana.
  Es el patrón de las plantillas oficiales de Qt 6.

## 4. El interfaz (`main.qml`)

```qml
// Qt 5 (antes):                      // Qt 6 (ahora):
import QtQuick 2.9                   import QtQuick
import QtQuick.Window 2.3            import QtQuick.Window
```

En Qt 6 los módulos QML usan **imports sin versión** ("dotless"). Resuelven
siempre contra la versión con la que se compiló la aplicación, evitando el
clásico error *"module ... is not installed"* cuando se actualiza Qt. El
contenido visual (`Window` + `Text` centrado) no cambia: esos tipos siguen
siendo válidos e idénticos en Qt 6.

## 5. Cómo compilar y ejecutar

Necesitas Qt 6 instalado (por ejemplo vía *Qt Online Installer*, marcando
**Qt 6.x → Desktop** y la herramienta **CMake**). Con Qt 6.8 LTS o superior:

```bash
cd Chapter01/chapter1/scratchpad
cmake -B build -DCMAKE_PREFIX_PATH=/ruta/a/Qt/6.8.0/gcc_64   # solo si cmake no encuentra Qt
cmake --build build
./build/Scratchpad            # abre la ventana con "Hello Qt Scratchpad!"
```

Alternativamente, abre `CMakeLists.txt` directamente en **Qt Creator**
(Archivo → Abrir proyecto) y pulsa *Construir y ejecutar*.

> Nota: en este entorno de trabajo no hay un SDK de Qt 6 instalado, por lo que
> la compilación debe realizarse en una máquina con Qt 6.8+ (la serie 6.8 LTS
> es la base sobre la que se construyen las versiones 6.9/6.1x posteriores; el
> código usa únicamente APIs disponibles desde Qt 6.4, como
> `loadFromModule()` y `objectCreationFailed`).

## 6. Errores típicos al migrar

| Síntoma                                        | Causa y solución                                                        |
|------------------------------------------------|-------------------------------------------------------------------------|
| `Module QtQuick 2.9 is not installed`          | Cambia a `import QtQuick` (sin versión).                                |
| `QQmlApplicationEngine failed to load component` | Verifica que el nombre del módulo y del tipo coinciden con `qt_add_qml_module` (`"Scratchpad"`, `"Main"`). |
| CMake no encuentra `Qt6Config.cmake`           | Pasa `-DCMAKE_PREFIX_PATH=<instalación>/6.x/gcc_64` o añade Qt al PATH. |
| `undefined reference to ...v6`                 | Mezcla de cabeceras Qt5 con librerías Qt6: usa solo el kit Qt6 en Qt Creator. |
