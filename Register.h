//
// Created by Lorenzo Malavolti on 10/04/2025.
//

#ifndef REGISTER_H
#define REGISTER_H
#include <QVector>

#include "Activity.h"


class Register {

public:

    void addActivity(const Activity& activity);

    bool removeActivity(int index);

    void clearAll();

private:
    QVector<Activity> activities;

};



#endif //REGISTER_H
