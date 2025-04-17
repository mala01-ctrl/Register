//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#ifndef REGISTER_H
#define REGISTER_H
#include <QVector>

#include "Activity.h"
#include "../Interfaces/Subject.h"


class Register : public Subject {
public:
    /**
     * Aggiunge un attività all'interno del registro
     * @param activity Attività da aggiungere
     */
    void addActivity(const Activity &activity);

    /**
     * Rimuove un attività dal registro cercandola per descrizione e data e ora di inizio. I parametri
     * sono necessari dato che non esiste un identificativo di attività
     * @param description Descrizione attività
     * @param start Data e ora di inizio
     * @return (bool) True se l'attività è stata rimossa, false altrimenti
     */
    bool removeActivity(const QString &description, const QDateTime &start);

    /**
     * Rimuove tutte le attività all'interno del registro
     */
    void clearAll();

    /**
     * Filtra le attività del registro in base alla data di inizio
     * @param date Data di inizio con cui si vuole filtrare le attività
     */
    void filterActivities(const QDate &date);

    /**
     * Ripristina il filtro precedente.
     */
    void resetAllActivities();

    /**
     * Cerca la posizione di un attività nel registro in base alla descrizione e alla data di inizio
     * @param description Descrizione attività
     * @param start Data e ora di inizio attività
     * @return Posizione nel registro attività o -1 se non si trova
     */
    int findActivity(const QString &description, const QDateTime &start);

    void addObserver(Observer *observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer) override {
        observers.remove(observer);
    }

    /**
     * Si notifica tutti gli observer per l'aggiornamento
     */
    void notify() override {
        for (const auto observer: observers) {
            observer->update();
        }
    }

    ~Register() override;

    /**
     * Metodo get per rendere accessibili le attività filtrate
     * @return Attività filtrate
     */
    const QVector<Activity>& getFilterActivities() const {
        return filteredActivities;
    }

private:
    QVector<Activity> activities;
    QVector<Activity> filteredActivities;
    std::list<Observer *> observers;
};


#endif //REGISTER_H
