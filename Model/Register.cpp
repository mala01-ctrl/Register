//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#include "Register.h"

void Register::addActivity(const Activity &activity) {
    this->activities.append(new Activity(activity));
    this->filterActivities(QDate());
}

bool Register::removeActivity(const QString &description, const QDateTime &start) {
    const int position = this->findActivity(description, start);
    if (position == -1)
        return false;

    const Activity *activityToRemove = this->activities.at(position);

    if (activityToRemove == nullptr)
        return false;

    this->activities.removeAt(position);
    delete activityToRemove;
    this->filterActivities(QDate());
    return true;
}

void Register::clearAll() {
    for (const Activity *activity: this->activities) {
        delete activity;
    }
    this->activities.clear();
    this->filterActivities(QDate());
}

void Register::filterActivities(const QDate &date) {
    this->filteredActivities.clear();

    if (date.isValid()) {
        for (Activity *activity: this->activities) {
            if (activity->getStartDateTime().date() == date) {
                this->filteredActivities.append(activity);
            }
        }
    } else {
        this->filteredActivities = this->activities;
    }

    this->notify();
}

void Register::resetAllActivities() {
    this->filteredActivities = this->activities;
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

Register::~Register() {
    this->clearAll();
}
