#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T13:56:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = onderzoekDelft
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mymodel.cpp \
    csvparser.cpp \
    C:/Users/Benjamin/Dropbox/Onderzoek Sensoren Delft/.CSV parser code/versie2.0/DataCell.cpp \
    C:/Users/Benjamin/Dropbox/Onderzoek Sensoren Delft/.CSV parser code/versie2.0/DateCell.cpp \
    datacell.cpp \
    datecell.cpp \
    namecell.cpp \
    stringsplitter.cpp \
    timecell.cpp \
    cell.cpp

HEADERS  += mainwindow.h \
    mymodel.h \
    csvparser.h \
    C:/Users/Benjamin/Dropbox/Onderzoek Sensoren Delft/.CSV parser code/versie2.0/DataCell.h \
    C:/Users/Benjamin/Dropbox/Onderzoek Sensoren Delft/.CSV parser code/versie2.0/DateCell.h \
    datacell.h \
    datecell.h \
    namecell.h \
    stringsplitter.h \
    timecell.h \
    cell.h

FORMS    += mainwindow.ui
