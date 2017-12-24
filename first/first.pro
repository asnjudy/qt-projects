TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    myfunc.cpp \
    complex.cpp \
    static/static.cpp \
    uml/chicken.cpp \
    uml/egg.cpp

HEADERS += \
    complex.h \
    static/static.h \
    uml/chicken.h \
    uml/egg.h
