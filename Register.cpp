#include "Register.h"
#include "ui_Register.h"

Register::Register(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}
