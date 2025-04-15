#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

#include "../Model/Activity.h"


MainWindow::MainWindow(Register *reg, RegisterController *controller, QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow) {
    this->ui->setupUi(this);

    // Imposta le dimensioni fisse della finestra a 800x600 pixel
    this->setFixedSize(844, 368);
    this->reg = reg;
    this->reg->addObserver(this);
    this->controller = controller;

    const QDateTime now = QDateTime::currentDateTime();
    this->ui->startTime->setDateTime(now);
    this->ui->endTime->setDateTime(now.addSecs(3600));
    this->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    this->ui->dateFilter->setDate(QDate::currentDate());
    //Inizialmente il pulsante di reset è nascosto
    this->ui->btnReset->setVisible(false);

    this->ui->btnClear->setEnabled(false);

    //Connessione del segnale di selezione della riga
    this->connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onItemSelectionChanged);
}


MainWindow::~MainWindow() {
    delete ui;
    this->reg->removeObserver(this);
}

void MainWindow::on_btnAdd_clicked() {
    const QString descrizione = ui->txtDescription->toPlainText();
    const QDateTime startDate = ui->startTime->dateTime();
    const QDateTime endDate = ui->endTime->dateTime();

    const int errorCode = this->controller->addActivity(descrizione, startDate, endDate);

    if (errorCode == RegisterController::ERROR_NONE) {
        this->ui->txtDescription->clear();
    } else if (errorCode == RegisterController::INVALID_DESCRIPTION) {
        QMessageBox::warning(this, "Errore", "La descrizione non può essere vuota");
    } else if (errorCode == RegisterController::INVALID_DATE_RANGE) {
        QMessageBox::warning(this, "Errore", "La data di inizio deve essere minore della data di fine");
    } else if (errorCode == RegisterController::DUPLICATED_ACTIVITY) {
        QMessageBox::warning(this, "Errore", "Esiste già un'attività con lo stesso nome e data");
    }
}

void MainWindow::update() {
    const bool sortingEnabled = this->ui->tableWidget->isSortingEnabled();
    this->ui->tableWidget->setSortingEnabled(false);
    QVector<Activity *> activities = this->reg->getActivities();
    this->ui->tableWidget->clearContents();
    this->ui->tableWidget->setRowCount(activities.size()); // Imposta il numero di righe

    for (int i = 0; i < activities.size(); i++) {
        const Activity* activity = activities[i];
        const QDateTime &startDateTime = activity->getStartDateTime();
        const QDateTime &endDateTime = activity->getEndDateTime();

        this->ui->tableWidget->setItem(i, 0, new QTableWidgetItem(activity->getDescription()));
        QTableWidgetItem *startDateItem = new QTableWidgetItem(startDateTime.toString("dd/MM/yyyy hh:mm"));
        startDateItem->setData(Qt::UserRole + 1, startDateTime);
        this->ui->tableWidget->setItem(i, 1, startDateItem);
        this->ui->tableWidget->setItem(i, 2, new QTableWidgetItem(endDateTime.toString("dd/MM/yyyy hh:mm")));
    }
    this->ui->tableWidget->setSortingEnabled(sortingEnabled);
}

void MainWindow::onItemSelectionChanged() const {
    if (this->ui->tableWidget->selectedItems().isEmpty())
        this->ui->btnClear->setEnabled(false);
    else
        this->ui->btnClear->setEnabled(true);
}

QMessageBox::StandardButton MainWindow::openMessageBox() {
    // Mostra una finestra di dialogo di conferma
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Conferma eliminazione",
        "Sei sicuro di voler eliminare tutte le attività?",
        QMessageBox::Yes | QMessageBox::No
    );

    return reply;
}

void MainWindow::on_btnClear_clicked() {
    QMessageBox::StandardButton reply = this->openMessageBox();

    if (reply == QMessageBox::Yes) {
        const int row = this->ui->tableWidget->currentRow();
        const QTableWidgetItem *descriptionItem = this->ui->tableWidget->item(row, 0);
        const QString description = descriptionItem->text();
        const QTableWidgetItem *startDateItem = this->ui->tableWidget->item(row, 1);
        const QVariant startDateVariant = startDateItem->data(Qt::UserRole + 1); // Usa un UserRole appropriato
        const QDateTime startDate = startDateVariant.toDateTime();

        this->controller->removeActivityByIndex(description, startDate);
    }
}

void MainWindow::on_btnClearAll_clicked() {
    // Mostra una finestra di dialogo di conferma
    QMessageBox::StandardButton reply = this->openMessageBox();

    // Se l'utente clicca su "Yes", esegui l'eliminazione
    if (reply == QMessageBox::Yes) {
        this->controller->clearAllActivities();
    }
}

void MainWindow::on_btnFilter_clicked() {
    QDate filterDate = ui->dateFilter->date();
    this->controller->filterAllActivities(filterDate);
    this->ui->btnReset->setVisible(true);
}

void MainWindow::on_btnReset_clicked() {
    this->reg->resetAllActivities();
    this->ui->dateFilter->clear();
    this->ui->btnReset->setVisible(false);
}
