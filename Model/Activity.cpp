//
// Created by Lorenzo Malavolti on 26/02/2025.
//

#include "Activity.h"

#include "../Exceptions/InvalidDateException.h"
#include "../Exceptions/InvalidDateRangeException.h"
#include "../Exceptions/InvalidDescriptionException.h"

Activity::Activity(const QString &description, const QDateTime &startDateTime,
                   const QDateTime &endDateTime) : description(description), startDateTime(startDateTime),
                                                   endDateTime(endDateTime) {
    if (description.trimmed().isEmpty()) {
        throw InvalidDescriptionException();
    }

    if (!startDateTime.isValid() || !endDateTime.isValid()) {
        throw InvalidDateException();
    }

    if (endDateTime < startDateTime) {
        throw InvalidDateRangeException();
    }
}

Activity::Activity(const Activity &activity) : description(activity.getDescription()),
                                               startDateTime(activity.getStartDateTime()),
                                               endDateTime(activity.getEndDateTime()) {
}
