//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#include "Register.h"

void Register::addActivity(const Activity& activity) {
    this->activities.append(activity);
}

bool Register::removeActivity(int index) {
    if (index >= 0 && index < this->activities.size()) {
        this->activities.removeAt(index);
        return true;
    }

    return false;
}

void Register::clearAll() {
    this->activities.clear();
}
