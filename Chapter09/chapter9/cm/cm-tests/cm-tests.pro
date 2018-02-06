QT += testlib network
QT -= gui

TARGET = client-tests
TEMPLATE = app

CONFIG += c++14
CONFIG += console
CONFIG -= app_bundle

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

INCLUDEPATH += source \
    ../cm-lib/source

SOURCES += source/models/client-tests.cpp \
    source/test-suite.cpp \
    source/main.cpp \
    source/controllers/master-controller-tests.cpp \
    source/data/datetime-decorator-tests.cpp \
    source/data/enumerator-decorator-tests.cpp \
    source/data/int-decorator-tests.cpp \
    source/data/string-decorator-tests.cpp

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

HEADERS += \
    source/test-suite.h \
    source/controllers/master-controller-tests.h \
    source/data/datetime-decorator-tests.h \
    source/data/enumerator-decorator-tests.h \
    source/data/int-decorator-tests.h \
    source/data/string-decorator-tests.h \
    source/models/client-tests.h \
    source/mocks/mock-object-factory.h
