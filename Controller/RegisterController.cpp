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
    const Activity a(description, start, end);
    if (this->reg->getFilterActivities().isEmpty()) {
        this->reg->addActivity(a);
        return ERROR_NONE;
    }
    const int position = this->reg->findActivity(description, start);
    if (position >= 0)
        return DUPLICATED_ACTIVITY;
    this->reg->addActivity(a);
    return ERROR_NONE;
}

int RegisterController::removeActivity(const QString &description, const QDateTime &start) const {
    const bool status = this->reg->removeActivity(description, start);
    return status ? ERROR_NONE : UNEXPECTED_ERROR;
}

void RegisterController::clearAllActivities() const {
    if (!this->reg->getFilterActivities().isEmpty()) {
        this->reg->clearAll();
    }
}

void RegisterController::filterAllActivities(const QDate &date) const {
    if (!this->reg->getFilterActivities().isEmpty()) {
        this->reg->filterActivities(date);
    }
}

void RegisterController::resetAllActivities() const {
    this->reg->resetAllActivities();
}
