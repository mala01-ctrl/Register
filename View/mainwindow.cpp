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

    this->ui->btnClearAll->setEnabled(false);

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
        return;
    }

    QString errorMessage = "";
    if (errorCode == RegisterController::INVALID_DESCRIPTION) {
        errorMessage = "La descrizione non può essere vuota";
    } else if (errorCode == RegisterController::INVALID_DATE_RANGE) {
        errorMessage = "La data di inizio deve essere minore della data di fine";
    } else if (errorCode == RegisterController::DUPLICATED_ACTIVITY) {
        errorMessage = "Esiste già un'attività con lo stesso nome e data";
    }
    QMessageBox::warning(this, "Errore", errorMessage);
}

void MainWindow::update() {
    //Disabilito l'ordinamento della tabella
    const bool sortingEnabled = this->ui->tableWidget->isSortingEnabled();
    this->ui->tableWidget->setSortingEnabled(false);

    //Abilto e disabilito il btnClearAll in base ai dati della tabella
    this->enableBtnClearAll();

    //Rimuovo gli elementi in tabella
    this->ui->tableWidget->clearContents();

    QVector<Activity> activities = this->reg->getActivities();
    this->ui->tableWidget->setRowCount(activities.size()); // Imposta il numero di righe

    for (int i = 0; i < activities.size(); i++) {
        const Activity& activity = activities[i];
        const QDateTime &startDateTime = activity.getStartDateTime();
        const QDateTime &endDateTime = activity.getEndDateTime();

        this->ui->tableWidget->setItem(i, 0, new QTableWidgetItem(activity.getDescription()));
        QTableWidgetItem *startDateItem = new QTableWidgetItem(startDateTime.toString("dd/MM/yyyy hh:mm"));
        startDateItem->setData(Qt::UserRole + 1, startDateTime);
        this->ui->tableWidget->setItem(i, 1, startDateItem);
        this->ui->tableWidget->setItem(i, 2, new QTableWidgetItem(endDateTime.toString("dd/MM/yyyy hh:mm")));
    }

    //Riabilito l'ordinamento in tabella
    this->ui->tableWidget->setSortingEnabled(sortingEnabled);
}

void MainWindow::onItemSelectionChanged() const {
    if (this->ui->tableWidget->selectedItems().isEmpty())
        this->ui->btnClear->setEnabled(false);
    else
        this->ui->btnClear->setEnabled(true);
}

QMessageBox::StandardButton MainWindow::openMessageBox(const QString &text) {
    // Mostra una finestra di dialogo di conferma
    const QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Conferma eliminazione",
        text,
        QMessageBox::Ok | QMessageBox::No
    );

    return reply;
}

void MainWindow::on_btnClear_clicked() {
    QMessageBox::StandardButton reply = this->openMessageBox("Vuoi eliminare questa attività?");

    if (reply == QMessageBox::Ok) {
        const int row = this->ui->tableWidget->currentRow();
        const QTableWidgetItem *descriptionItem = this->ui->tableWidget->item(row, 0);
        const QString description = descriptionItem->text();
        const QTableWidgetItem *startDateItem = this->ui->tableWidget->item(row, 1);
        const QVariant startDateVariant = startDateItem->data(Qt::UserRole + 1); // Usa un UserRole appropriato
        const QDateTime startDate = startDateVariant.toDateTime();

        const int errorCode = this->controller->removeActivityByIndex(description, startDate);
        if (errorCode == RegisterController::UNEXPECTED_ERROR)
            QMessageBox::warning(this, "Errore", "Si è verificato un errore");
    }
}

void MainWindow::on_btnClearAll_clicked() {
    // Mostra una finestra di dialogo di conferma
    QMessageBox::StandardButton reply = this->openMessageBox("Sei sicuro di voler eliminare tutte le attività?");

    // Se l'utente clicca su "Ok", esegui l'eliminazione
    if (reply == QMessageBox::Ok) {
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

void MainWindow::enableBtnClearAll() const {
    QVector<Activity> activities = this->reg->getActivities();
    if (activities.isEmpty())
        this->ui->btnClearAll->setEnabled(false);
    else
        this->ui->btnClearAll->setEnabled(true);
}
