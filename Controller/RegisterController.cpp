//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#include "RegisterController.h"

#include "../Exceptions/InvalidDateException.h"
#include "../Exceptions/InvalidDateRangeException.h"
#include "../Exceptions/InvalidDescriptionException.h"

int RegisterController::addActivity(const QString &description, const QDateTime &start, const QDateTime &end) const {
    try {
        const Activity a(description, start, end);
        if (this->reg->getActivities().isEmpty()) {
            this->reg->addActivity(a);
            return ERROR_NONE;
        }
        const int position = this->reg->findActivity(description, start);
        if (position >= 0)
            return DUPLICATED_ACTIVITY;
        this->reg->addActivity(a);
        return ERROR_NONE;
    } catch (const InvalidDescriptionException &) {
        return INVALID_DESCRIPTION;
    } catch (const InvalidDateException &) {
        return INVALID_DATE;      //Quando una delle due date passate non è valida
    } catch (const InvalidDateRangeException &) {
        return INVALID_DATE_RANGE;
    }
}

int RegisterController::removeActivity(const QString &description, const QDateTime &start) const {
    const bool status = this->reg->removeActivity(description, start);
    return status ? ERROR_NONE : UNEXPECTED_ERROR;
}

void RegisterController::clearAllActivities() const {
    this->reg->clearAll();
}

int RegisterController::filterAllActivities(const QDate &date) const {
    try {
        this->reg->filterActivities(date);
        return ERROR_NONE;
    }catch (const InvalidDateException &) {
        return INVALID_DATE;
    }
}

void RegisterController::resetAllActivities() const {
    this->reg->resetAllActivities();
}
