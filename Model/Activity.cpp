//
// Created by Lorenzo Malavolti on 26/02/2025.
//

#include "Activity.h"

Activity::Activity(const QString &description, const QDateTime& startDateTime, const QDateTime& endDateTime) {
    this->description = description;
    this->startDateTime = startDateTime;
    this->endDateTime = endDateTime;
}