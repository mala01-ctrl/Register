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
    /**
     * Cosutruttore
     * @param reg Puntatore a oggetto Register
     * @param controller Puntatore a Oggetto RegisterCon
     * @param parent (QWidget) parent widget
     */
    MainWindow(Register *reg, RegisterController *controller, QWidget *parent = nullptr);


    ~MainWindow();

    /**
     * Preleva i dati aggiornati dal model e aggiorna la view
     */
    virtual void update();

    /**
     * Abilita o disabilita il pulsante btnClear in base alla selezione di una riga della tabella
     */
    void onItemSelectionChanged() const;


private slots:
    /**
     * Aggiunta di un'attività
     */
    void on_btnAdd_clicked();

    /**
     * Rimozione di un'attività
     */
    void on_btnClear_clicked();

    /**
     * Rimozione di tutte le attività
     */
    void on_btnClearAll_clicked();

    /**
     * Filtraggio delle attività
     */
    void on_btnFilter_clicked() const;

    /**
     * Ripristino del filtro
     */
    void on_btnReset_clicked() const;

private:
    /**
     * Apre un messageBox per la conferma visualizzando un messaggio per l'utente
     * @param text Messaggio per l'utente
     * @return Risposta dell'utente
     */
    QMessageBox::StandardButton openMessageBox(const QString &text);

    /**
     * Abilita o disabilita il btnClearAll in base al numero di attività nel registro
     */
    void enableBtnClearAll() const;

    Ui::MainWindow *ui;
    Register *reg;
    RegisterController *controller;
};
#endif // MAINWINDOW_H
