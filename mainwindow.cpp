#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

#include "Activity.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    QString descrizione = ui->textEdit->toPlainText();
    QDateTime startDate = ui->dateTimeEdit->dateTime();
    QDateTime endDate = ui->dateTimeEdit->dateTime();

    if (descrizione.isEmpty()) {
        //Qui si mostrerà l'errore
        return;
    }

    Activity activity(descrizione, startDate, endDate);
    this->reg.addActivity(activity);

    this->ui->listWidget->addItem(activity.toString());
    this->ui->textEdit->clear();
}
