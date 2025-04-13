//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#include "Register.h"

void Register::addActivity(const Activity &activity) {
    this->activities.append(activity);
    this->filterActivities(QDate());
}

bool Register::removeActivity(int index) {
    if (index >= 0 && index < this->activities.size()) {
        this->activities.removeAt(index);
        this->filterActivities(QDate());

        return true;
    }

    return false;
}

void Register::clearAll() {
    this->activities.clear();
    this->filterActivities(QDate());
}

void Register::filterActivities(const QDate &date) {
    this->filteredActivities.clear();

    if (date.isValid()) {
        for (const Activity &activity: this->activities) {
            if (activity.getStartDateTime().date() == date) {
                this->filteredActivities.append(activity);
            }
        }
    } else {
        this->filteredActivities = this->activities;
    }

    this->notify();
}
