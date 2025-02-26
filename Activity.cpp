//
// Created by Lorenzo Malavolti on 26/02/2025.
//

#include "Activity.h"

Activity::Activity(const std::string &description, const std::string& startDateTime, const std::string& endDateTime, int id) {
    this->description = description;
    this->startDateTime = startDateTime;
    this->endDateTime = endDateTime;
    this->id = id;
}