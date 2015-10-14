#-------------------------------------------------
#
# Project created by QtCreator 2015-10-13T20:48:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = onderzoekSensoren
TEMPLATE = app


SOURCES += main.cpp\
        View\mainwindow.cpp\
	Model\cell.cpp\
	Controller\csvparser.cpp\
	Model\datacell.cpp\
	Model\datecell.cpp\
	Model\mymodel.cpp\
	Model\namecell.cpp\
	Controller\stringsplitter.cpp\
	Model\timecell.cpp\
    	Model\csvvector.cpp

HEADERS  += View\mainwindow.h\
	Model\cell.h\
	Controller\csvparser.h\
	Model\datacell.h\
	Model\datecell.h\
	Model\mymodel.h\
	Model\namecell.h\
	Controller\stringsplitter.h\
	Model\timecell.h\
    	Model\csvvector.h

FORMS    += View\mainwindow.ui
