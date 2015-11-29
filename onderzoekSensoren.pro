#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T20:48:47
#
#-------------------------------------------------

QT       += core gui

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
    Controller/function.cpp \
    Controller/sum.cpp \
    Controller/average.cpp \
    Controller/max.cpp \
    Controller/min.cpp \
    Controller/variance.cpp \
    Controller/deviation.cpp

HEADERS  += View\mainwindow.h\
	Controller\csvparser.h\
	Model\datacell.h\
	Model\mymodel.h\
	Controller\stringsplitter.h\
    	Model\csvvector.h \
        Controller\datetimeparser.h\
        Bayes\bayes_utils.h\
        Bayes\directed_graph.h\
        Bayes\graph.h\
        Bayes\graph_utils.h\
    Controller/csvwriter.h \
    Controller/function.h \
    Controller/sum.h \
    Controller/average.h \
    Controller/max.h \
    Controller/min.h \
    Controller/variance.h \
    Controller/deviation.h

FORMS    += View\mainwindow.ui

DISTFILES +=
