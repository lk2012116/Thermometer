#include <QApplication>
#include "ThermometerDemo.h"

int main(int argc, char** argv)
{
	QApplication a(argc, argv);
	CThermometerDemo w;
	w.show();
	return a.exec();
}