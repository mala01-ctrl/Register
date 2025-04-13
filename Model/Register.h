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

    bool removeActivity(int index);

    void clearAll();

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

    QVector<Activity> getActivities() const {
        return activities;
    }

private:
    QVector<Activity> activities;
    std::list<Observer *> observers;

};



#endif //REGISTER_H
