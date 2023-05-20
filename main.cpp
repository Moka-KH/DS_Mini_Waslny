#include "mini_wasalni_gui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mini_Wasalni_GUI w;
    w.show();

    bool s = a.exec();
    return s;
}
