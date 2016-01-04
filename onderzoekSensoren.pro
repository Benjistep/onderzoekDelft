#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T20:48:47
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

TARGET = onderzoekSensoren
TEMPLATE = app


SOURCES += main.cpp\
        View\mainwindow.cpp\
	Controller\csvparser.cpp\
	Model\datacell.cpp\
	Model\mymodel.cpp\
	Controller\stringsplitter.cpp\
    	Model\csvvector.cpp \
    	Controller\datetimeparser.cpp \
    Controller/csvwriter.cpp \
    Functions/function.cpp \
    Functions/sum.cpp \
    Functions/average.cpp \
    Functions/max.cpp \
    Functions/min.cpp \
    Functions/variance.cpp \
    Functions/deviation.cpp \
    Controller/analyser.cpp \
    Controller/result.cpp \
    Functions/count.cpp \
	Situations/Settings/setting.cpp \
    Situations/situation.cpp \
    Situations/Settings/co2setting.cpp \
    Situations/Settings/temperaturesetting.cpp \
    Situations/Settings/airflowsetting.cpp \
    Situations/Settings/lightsetting.cpp \
    Situations/Settings/pirsetting.cpp \
    Controller/situationreader.cpp

HEADERS  += View\mainwindow.h\
	Controller\csvparser.h\
	Model\datacell.h\
	Model\mymodel.h\
	Controller\stringsplitter.h\
    	Model\csvvector.h \
        Controller\datetimeparser.h\
    Controller/csvwriter.h \
    Functions/function.h \
    Functions/sum.h \
    Functions/average.h \
    Functions/max.h \
    Functions/min.h \
    Functions/variance.h \
    Functions/deviation.h \
    Controller/analyser.h \
    Controller/result.h \
    Functions/count.h \
    Situations/Settings/setting.h \
    Situations/situation.h \
    Situations/Settings/co2setting.h \
    Situations/Settings/temperaturesetting.h \
    Situations/Settings/airflowsetting.h \
    Situations/Settings/lightsetting.h \
    Situations/Settings/pirsetting.h \
    Controller/situationreader.h

FORMS    += View\mainwindow.ui

DISTFILES +=
