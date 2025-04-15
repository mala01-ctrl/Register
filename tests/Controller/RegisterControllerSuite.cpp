//
// Created by Lorenzo Malavolti on 15/04/2025.
//

#include <QDateTime>
#include <QString>
#include <gtest/gtest.h>

#include "../../Controller/RegisterController.h"

class RegisterControllerSuite : public ::testing::Test {
protected:
    void SetUp() override {
        const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
        const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");
        const Activity activity1("meeting", start, end);

        reg = new Register();

        reg->addActivity(activity1);
        regController = new RegisterController(reg);
    }

    Register *reg = nullptr;
    RegisterController *regController = nullptr;
};

TEST_F(RegisterControllerSuite, addActivity) {
    QString description = "Workout";
    QDateTime start = QDateTime::currentDateTime();
    const QDateTime end = QDateTime::currentDateTime().addDays(1);

    //Caso 1: dati tutti validi
    int errorCode = this->regController->addActivity(description, start, end);

    ASSERT_EQ(errorCode, 0);

    //Caso 2: descrizione vuota

    description = "";

    errorCode = this->regController->addActivity(description, start, end);
    ASSERT_EQ(errorCode, 1);

    //Caso 3: data di inizio > data di fine
    start = start.addDays(2);

    errorCode = this->regController->addActivity(description, start, end);

    ASSERT_EQ(errorCode, 2);

    //caso 4 Attività duplicata

    description = "Workout";
    start = QDateTime::currentDateTime();

    errorCode = this->regController->addActivity(description, start, end);

    ASSERT_EQ(errorCode, 3);
}

TEST_F(RegisterControllerSuite, removeActivityByIndexSuccessfull) {
    const QString description = "meeting";
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");

    const int errorCode = this->regController->removeActivityByIndex(description, start);

    ASSERT_EQ(errorCode, 0);
}

TEST_F(RegisterControllerSuite, removeActivityByIndexFailure) {
    const QString description = "Workout";
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");

    const int errorCode = this->regController->removeActivityByIndex(description, start);

    ASSERT_EQ(errorCode, 4);
}

