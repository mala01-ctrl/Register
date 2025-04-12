#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>

#include "Register.h"
#include "RegisterController.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer{
    Q_OBJECT

public:
    MainWindow(Register* reg, RegisterController* controller, QWidget *parent = nullptr);

    ~MainWindow();

    virtual void update();

    void onItemSelectionChanged() const;

private slots:
    void on_btnAdd_clicked();

    void on_btnClear_clicked() const;

private:
    Ui::MainWindow *ui;
    Register* reg;
    RegisterController* controller;

};
#endif // MAINWINDOW_H
