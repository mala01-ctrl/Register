//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#include "Register.h"
#include <memory>

#include "../Exceptions/InvalidDateException.h"

void Register::addActivity(const Activity &activity) {
    this->activities.append(std::make_shared<Activity>(activity));
    this->notify();
}

bool Register::removeActivity(const QString &description, const QDateTime &start) {
    for (auto it = this->activities.begin(); it != this->activities.end(); ++it) {
        if ((*it)->getDescription() == description && (*it)->getStartDateTime() == start) {
            this->activities.erase(it);
            this->notify();
            return true;
        }
    }
    return false;
}

void Register::clearAll() {
    if (!this->activities.isEmpty()) {
        this->activities.clear();
        this->notify();
    }
}

void Register::filterActivities(const QDate &date) {
    if (!date.isValid())
        throw InvalidDateException();

    if (!this->activities.isEmpty()) {
        this->currentFilterDate = date;
        this->notify();
    }
}

void Register::resetAllActivities() {
    this->currentFilterDate = QDate();
    this->notify();
}

int Register::findActivity(const QString &description, const QDateTime &start) {
    for (int i = 0; i < this->activities.size(); i++) {
        if (QString::compare(this->activities[i]->getDescription(), description) == 0 && this->activities[i]->
            getStartDateTime() == start) {
            return i;
        }
    }
    return -1;
}

QVector<std::shared_ptr<Activity>> Register::getActivities() const {
    //se il filtro non è valido
    if (!currentFilterDate.isValid()) {
        return this->activities;
    }
    //Quando il filtro è valido
    QVector<std::shared_ptr<Activity> > filteredActivities;
    for (const auto &ptr: this->activities) {
        if (ptr->getStartDateTime().date() == currentFilterDate) {
            filteredActivities.append(ptr);
        }
    }
    return filteredActivities;
}
