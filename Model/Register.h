//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#ifndef REGISTER_H
#define REGISTER_H
#include <QVector>

#include "Activity.h"
#include "../Interfaces/Subject.h"


class Register: public Subject {

public:

    void addActivity(const Activity& activity);

    bool removeActivity(const QString &description, const QDateTime &start);

    void clearAll();

    void filterActivities(const QDate &date);

    void resetAllActivities();

    int findActivity(const QString &description, const QDateTime &start);

    virtual void addObserver(Observer *observer) {
        observers.push_back(observer);
    }

    virtual void removeObserver(Observer *observer) {
        observers.remove(observer);
    }

    virtual void notify() {
        for (auto observer : observers) {
            observer->update();
        }
    }

    ~Register();

    QVector<Activity *> getActivities() const {
        return filteredActivities;
    }

private:
    QVector<Activity *> activities;
    QVector<Activity *> filteredActivities;
    std::list<Observer *> observers;

};



#endif //REGISTER_H
