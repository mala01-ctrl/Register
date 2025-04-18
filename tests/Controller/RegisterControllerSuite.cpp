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

        ASSERT_NO_THROW({
            const Activity activity1("meeting", start, end);

            reg = new Register();

            reg->addActivity(activity1);
            regController = new RegisterController(reg);
            });
    }

    void TearDown() override {
        delete regController;
        delete reg;
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
    description = "Call";
    start = start.addDays(2);

    errorCode = this->regController->addActivity(description, start, end);

    ASSERT_EQ(errorCode, 2);

    //caso 4 Attività duplicata

    description = "Workout";
    start = QDateTime::currentDateTime();

    errorCode = this->regController->addActivity(description, start, end);

    ASSERT_EQ(errorCode, 3);

    //caso 5: data non valida
    description = "Verifica";
    start = QDateTime(QDate(), QTime());
    errorCode = this->regController->addActivity(description, start, end);
    ASSERT_EQ(errorCode, 5);
}

TEST_F(RegisterControllerSuite, removeActivity) {
    const QString description = "meeting";
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");

    const int errorCode = this->regController->removeActivity(description, start);

    ASSERT_EQ(errorCode, 0);
}

TEST_F(RegisterControllerSuite, removeActivityFailure) {
    const QString description = "Call";
    const QDateTime start = QDateTime::currentDateTime();

    const int errorCode = this->regController->removeActivity(description, start);

    ASSERT_EQ(errorCode, 4);
}

TEST_F(RegisterControllerSuite, clearAllActivities) {
    this->regController->clearAllActivities();

    ASSERT_EQ(this->reg->getActivities().size(), 0);
}

TEST_F(RegisterControllerSuite, filterAllActivities) {
    const QDate filterDate = QDate::fromString("2025-04-14", "yyyy-MM-dd");

    const int errorCode = this->regController->filterAllActivities(filterDate);
    ASSERT_EQ(errorCode, 0);
}

TEST_F(RegisterControllerSuite, filterAllActivitiesFailure) {
    constexpr auto filterDate = QDate();

    const int errorCode = this->regController->filterAllActivities(filterDate);
    ASSERT_EQ(errorCode, 5);
}

TEST_F(RegisterControllerSuite, resetAllActivities) {
    //Applico un filtro che mi nasconde le attività
    const QDate filterDate = QDate::fromString("2025-04-14", "yyyy-MM-dd");

    const int errorCode = this->regController->filterAllActivities(filterDate);

    ASSERT_EQ(errorCode, 0);
    ASSERT_EQ(this->reg->getActivities().size(), 0);

    //Applico il reset del filtro
    this->regController->resetAllActivities();
    ASSERT_EQ(this->reg->getActivities().size(), 1);
}
