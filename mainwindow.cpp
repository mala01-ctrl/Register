#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

#include "Activity.h"


MainWindow::MainWindow(Register *reg, RegisterController *controller, QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->reg = reg;
    this->reg->addObserver(this);
    this->controller = controller;

    const QDateTime now = QDateTime::currentDateTime();
    ui->startTime->setDateTime(now);
    ui->endTime->setDateTime(now);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    ui->dateEdit->setDate(QDate::currentDate());

    //Connessione del segnale di selezione della riga
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onItemSelectionChanged);
}


MainWindow::~MainWindow() {
    delete ui;
    this->reg->removeObserver(this);
}

void MainWindow::on_btnAdd_clicked() {
    QString descrizione = ui->txtDescription->toPlainText();
    QDateTime startDate = ui->startTime->dateTime();
    QDateTime endDate = ui->endTime->dateTime();

    if (descrizione.isEmpty()) {
        //Qui si mostrerà l'errore
        return;
    }

    this->controller->addActivity(descrizione, startDate, endDate);

    this->ui->txtDescription->clear();
}

void MainWindow::update() {
    QVector<Activity> activities = this->reg->getActivities();
    this->ui->tableWidget->clearContents();

    const int rowCount = activities.size();
    while (this->ui->tableWidget->rowCount() < rowCount) {
        this->ui->tableWidget->insertRow(this->ui->tableWidget->rowCount());
    }

    while (this->ui->tableWidget->rowCount() > rowCount) {
        this->ui->tableWidget->removeRow(this->ui->tableWidget->rowCount() - 1);
    }

    for (int i = 0; i < rowCount; i++) {
        const Activity &activity = activities[i];

        this->ui->tableWidget->setItem(i, 0, new QTableWidgetItem(activity.getDescription()));
        this->ui->tableWidget->setItem(i, 1, new QTableWidgetItem(activity.getStartDateTime().toString()));
        this->ui->tableWidget->setItem(i, 2, new QTableWidgetItem(activity.getEndDateTime().toString()));
    }
}

void MainWindow::onItemSelectionChanged() const {
    if (this->ui->tableWidget->selectedItems().isEmpty())
        this->ui->btnClear->setEnabled(false);
    else
        this->ui->btnClear->setEnabled(true);
}

void MainWindow::on_btnClear_clicked() const {
    const int row = ui->tableWidget->currentRow();

    if (row != -1) {
        this->controller->removeActivityByIndex(row);
    }
}
