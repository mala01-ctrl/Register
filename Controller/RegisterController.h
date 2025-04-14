//
// Created by Lorenzo Malavolti on 12/04/2025.
//

#ifndef REGISTERCONTROLLER_H
#define REGISTERCONTROLLER_H
#include "../Model/Register.h"


class RegisterController {
public:
    static const int ERROR_NONE = 0;
    static const int INVALID_DESCRIPTION = 1;
    static const int INVALID_DATE_RANGE = 2;


    explicit RegisterController(Register *reg) : reg(reg) {}

    int addActivity(const QString &description, const QDateTime &start, const QDateTime &end) const;

    void removeActivityByIndex(int index) const;

    void clearAllActivities() const;

    void filterAllActivities(const QDate &date) const;

    void resetAllActivities() const;

private:
    Register *reg;
};


#endif //REGISTERCONTROLLER_H
