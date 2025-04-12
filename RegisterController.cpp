//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#include "RegisterController.h"

void RegisterController::addActivity(const QString &decription, const QDateTime &start, const QDateTime &end) const {
    Activity a(decription, start, end);
    reg->addActivity(a);
}

void RegisterController::removeActivityByIndex(int index) const {
    reg->removeActivity(index);
}

