//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#ifndef OBSERVER_H
#define OBSERVER_H


class Observer {

public:
    virtual void update() = 0;
    virtual ~Observer() = default;

};



#endif //OBSERVER_H
