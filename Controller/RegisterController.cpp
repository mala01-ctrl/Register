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
    reg->addActivity(a);
    return ERROR_NONE;
}

void RegisterController::removeActivityByIndex(int index) const {
    reg->removeActivity(index);
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
