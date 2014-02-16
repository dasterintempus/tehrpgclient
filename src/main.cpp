#include <QtWidgets/QApplication>
#include "mainscreen.h"

int main(int argc, char** argv)
{
	QApplication application(argc, argv);
	teh::MainScreen mainscreen;
	mainscreen.show();
	return application.exec();
}