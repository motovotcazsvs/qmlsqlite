TEMPLATE = app

QT += qml quick sql widgets
CONFIG += c++11

SOURCES += main.cpp \
    sqlitebase.cpp \
    listmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    sqlitebase.h \
    listmodel.h
