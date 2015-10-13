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
        mainwindow.cpp\
	cell.cpp\
	csvparser.cpp\
	datacell.cpp\
	datecell.cpp\
	mymodel.cpp\
	namecell.cpp\
	stringsplitter.cpp\
	timecell.cpp\

HEADERS  += mainwindow.h\
	cell.h\
	csvparser.h\
	datacell.h\
	datecell.h\
	mymodel.h\
	namecell.h\
	stringsplitter.h\
	timecell.h\

FORMS    += mainwindow.ui
