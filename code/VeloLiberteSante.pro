#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T13:10:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VeloLiberteSante
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ajouterstation.cpp \
    ajouterborne.cpp \
    ajoutervelo.cpp \
    modifierstation.cpp \
    modifierborne.cpp \
    modifiervelo.cpp \
    consulterabonne.cpp \
    ajouterabonne.cpp \
    modifierabonne.cpp \
    consultervelo.cpp \
    Bike.cpp \
    Controller.cpp \
    Station.cpp \
    Emplacement.cpp \
    stationtablemodel.cpp \
    serializable_main.cpp

HEADERS  += mainwindow.h \
    ajouterstation.h \
    ajouterborne.h \
    ajoutervelo.h \
    modifierstation.h \
    modifierborne.h \
    modifiervelo.h \
    consulterabonne.h \
    ajouterabonne.h \
    modifierabonne.h \
    consultervelo.h \
    Bike.h \
    Controller.h \
    Station.h \
    Serializable.h \
    Emplacement.h \
    stationtablemodel.h

FORMS    += mainwindow.ui \
    ajouterstation.ui \
    ajouterborne.ui \
    ajoutervelo.ui \
    modifierstation.ui \
    modifierborne.ui \
    modifiervelo.ui \
    consulterabonne.ui \
    ajouterabonne.ui \
    modifierabonne.ui \
    consultervelo.ui
