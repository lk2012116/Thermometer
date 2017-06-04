#include <QApplication>
#include "Thermometer.h"

int main(int argc, char** argv)
{
	QApplication a(argc, argv);
	CThermometer w;
	w.show();
	return a.exec();
}