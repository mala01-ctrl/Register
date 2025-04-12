//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"


class Subject {

public:
    virtual ~Subject() = default;
    virtual void notify() = 0;
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;

};



#endif //SUBJECT_H
