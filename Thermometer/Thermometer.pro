#-------------------------------------------------
#
# Project created by QtCreator 2017-05-30T16:22:31
#
#-------------------------------------------------

QT += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Thermometer
TEMPLATE = lib
DEFINES += THERMOMETER_LIB
DESTDIR += bin
MOC_DIR += ./tmp/moc
OBJECTS_DIR += ./tmp/object
UI_DIR += ./tmp/ui
RCC_DIR += ./tmp/rcc
INCLUDEPATH += ./include
RESOURCES += Thermometer.qrc
CONFIG += console qt warn_on release

HEADERS += include/Thermometer.h \
		   include/PointItem.h \
		   include/ThermometerDef.h

SOURCES += src/main.cpp \
		   src/Thermometer.cpp \
		   src/PointItem.cpp
		   

win32 {
	build_pass:CONFIG(release, debug|release) {
	}

	build_pass:CONFIG(debug, debug|release) {
		TARGET = $$join(TARGET,,,d)
	}
}
