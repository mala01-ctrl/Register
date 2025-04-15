//
// Created by Lorenzo Malavolti on 26/02/2025.
//

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QDateTime>
#include <QString>


class Activity {
public:
    Activity(const QString &description, const QDateTime &startDateTime, const QDateTime &endDateTime);

    Activity(const Activity &activity) = default;

    QString getDescription() const {
        return description;
    }

    QDateTime getStartDateTime() const {
        return startDateTime;
    }

    QDateTime getEndDateTime() const {
        return endDateTime;
    }

    QString toString() const {
        return QString("[%1 - %2] %3")
                .arg(startDateTime.toString("yyyy-MM-dd HH:mm"))
                .arg(endDateTime.toString("yyyy-MM-dd HH:mm"))
                .arg(description);
    }

private:
    QString description;
    QDateTime startDateTime;
    QDateTime endDateTime;
};


#endif //ACTIVITY_H
