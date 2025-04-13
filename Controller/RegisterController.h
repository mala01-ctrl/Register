//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#ifndef REGISTERCONTROLLER_H
#define REGISTERCONTROLLER_H
#include "../Model/Register.h"


class RegisterController {
public:
    explicit RegisterController(Register *reg) : reg(reg) {}

    void addActivity(const QString &decription, const QDateTime &start, const QDateTime &end) const;

    void removeActivityByIndex(int index) const;

private:
    Register *reg;
};


#endif //REGISTERCONTROLLER_H
