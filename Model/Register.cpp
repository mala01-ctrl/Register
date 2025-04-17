//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#include "Register.h"

void Register::addActivity(const Activity &activity) {
    this->activities.append(activity);
    this->filterActivities(QDate());
}

bool Register::removeActivity(const QString &description, const QDateTime &start) {
    const int position = this->findActivity(description, start);
    if (position == -1)
        return false;

    const Activity activityToRemove = this->activities.at(position);

    this->activities.removeAt(position);
    this->filterActivities(QDate());
    return true;
}

void Register::clearAll() {
    this->activities.clear();
    this->filterActivities(QDate());  //Questo forse non serve
}

void Register::filterActivities(const QDate &date) {
    this->filteredActivities.clear();

    if (date.isValid()) {
        for (const Activity& activity: this->activities) {
            if (activity.getStartDateTime().date() == date) {
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
        if (QString::compare(this->activities[i].getDescription(), description) == 0 && this->activities[i].
            getStartDateTime() == start) {
            return i;
        }
    }
    return -1;
}

Register::~Register() {
    this->clearAll();
}
