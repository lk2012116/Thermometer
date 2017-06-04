#-------------------------------------------------
#
# Project created by QtCreator 2017-05-30T16:52:31
#
#-------------------------------------------------

QT += core gui svg network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThermometerDemo
TEMPLATE = app
DESTDIR += bin
MOC_DIR += ./tmp/moc
OBJECTS_DIR += ./tmp/object
UI_DIR += ./tmp/ui
RCC_DIR += ./tmp/rcc
INCLUDEPATH += ./include ./src ../Thermometer/include
CONFIG += console qt warn_on release

HEADERS += src/ThermometerDemo.h \

SOURCES += src/main.cpp \
		   src/ThermometerDemo.cpp
		   
FORMS += forms/ThermometerDemo.ui
		   

win32 {
	build_pass:CONFIG(release, debug|release) {
		LIBS += -L./lib/Thermometer.lib
	}

	build_pass:CONFIG(debug, debug|release) {
		LIBS += -L./lib/Thermometer.lib
		TARGET = $$join(TARGET,,,d)
	}
}
