#include "IM.h"
#include <QtWidgets/QApplication>
#include "IM_Login.h"
#include "connecting.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//IM w;
	IM_Login ww;
	
	ww.show();
	//w.show();
	return a.exec();
}
