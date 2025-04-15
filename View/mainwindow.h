#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <ui_mainwindow.h>

#include "../Model/Register.h"
#include "../Controller/RegisterController.h"
#include "../Interfaces/Observer.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT

public:
    MainWindow(Register *reg, RegisterController *controller, QWidget *parent = nullptr);

    ~MainWindow();

    virtual void update();

    void onItemSelectionChanged() const;


private slots:
    void on_btnAdd_clicked();

    void on_btnClear_clicked();

    void on_btnClearAll_clicked();

    void on_btnFilter_clicked();

    void on_btnReset_clicked();

private:
    QMessageBox::StandardButton openMessageBox(const QString &text);

    void enableBtnClearAll() const;

    Ui::MainWindow *ui;
    Register *reg;
    RegisterController *controller;
};
#endif // MAINWINDOW_H
