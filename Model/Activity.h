//
// Created by Lorenzo Malavolti on 26/02/2025.
//

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QDateTime>
#include <QString>

/**
 * Classe che rappresenta le attività del registro
 */
class Activity {
public:
    /**
     * Costruttore di classe con parametri
     * @param description Descrizione dell'attività
     * @param startDateTime Data e ora di inizio attività
     * @param endDateTime Data e ora di fine attività
     */
    Activity(const QString &description, const QDateTime &startDateTime, const QDateTime &endDateTime);

    /**
     * Costruttore di copia
     * @param activity Attività da copiare
     */
    Activity(const Activity &activity) = default;

    /**
     * Metodo get per la descrizione
     * @return Descrizione attività
     */
    QString getDescription() const {
        return description;
    }

    /**
     * Metodo get per la data e ora di inizio
     * @return Data e ora di inizio
     */
    QDateTime getStartDateTime() const {
        return startDateTime;
    }

    /**
     * Metodo get per la data e ora di fine
     * @return Data e ora di fine
     */
    QDateTime getEndDateTime() const {
        return endDateTime;
    }

    /**
     * Metodo toString per visualizzazione attributi di classe
     * @return QString con gli attributi di classe
     */
    QString toString() const {
        return QString("[%1 - %2] %3")
                .arg(startDateTime.toString("yyyy-MM-dd HH:mm"), endDateTime.toString("yyyy-MM-dd HH:mm"), description);
    }

private:
    QString description;
    QDateTime startDateTime;
    QDateTime endDateTime;
};


#endif //ACTIVITY_H
