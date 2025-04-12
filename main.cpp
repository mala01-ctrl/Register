#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Register* reg = new Register();
    RegisterController* controller = new RegisterController(reg);
    MainWindow w(reg, controller);
    w.show();
    return a.exec();
}
