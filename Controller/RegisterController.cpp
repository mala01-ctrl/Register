//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#include "RegisterController.h"

int RegisterController::addActivity(const QString &description, const QDateTime &start, const QDateTime &end) const {
    if (start >= end) {
        return INVALID_DATE_RANGE;
    }
    if (description.isEmpty()) {
        return INVALID_DESCRIPTION;
    }
    Activity a(description, start, end);
    if (this->reg->getActivities().isEmpty()) {
        this->reg->addActivity(a);
        return ERROR_NONE;
    }
    const int position = this->reg->findActivity(description, start);
    if (position >= 0)
        return DUPLICATED_ACTIVITY;
    this->reg->addActivity(a);
    return ERROR_NONE;
}

void RegisterController::removeActivityByIndex(const QString &description, const QDateTime &start) const {
    reg->removeActivity(description, start);
}

void RegisterController::clearAllActivities() const {
    if (reg->getActivities().size() > 0) {
        this->reg->clearAll();
    }
}

void RegisterController::filterAllActivities(const QDate &date) const {
    if (reg->getActivities().size() > 0) {
        this->reg->filterActivities(date);
    }
}

void RegisterController::resetAllActivities() const {
    this->reg->resetAllActivities();
}
