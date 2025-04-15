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
    static const int DUPLICATED_ACTIVITY = 3;
    static const int UNEXPECTED_ERROR = 4;


    explicit RegisterController(Register *reg) : reg(reg) {}

    int addActivity(const QString &description, const QDateTime &start, const QDateTime &end) const;

    int removeActivityByIndex(const QString &description, const QDateTime &start) const;

    void clearAllActivities() const;

    void filterAllActivities(const QDate &date) const;

    void resetAllActivities() const;

private:
    Register *reg;
};


#endif //REGISTERCONTROLLER_H
