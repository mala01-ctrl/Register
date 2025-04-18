//
// Created by Lorenzo Malavolti on 13/04/2025.
//

#include "../../Exceptions/InvalidDateException.h"
#include "gtest/gtest.h"
#include "../../Model/Register.h"

class RegisterSuite : public ::testing::Test {
protected:
    void SetUp() override {
        const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
        const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");

        ASSERT_NO_THROW({
            const Activity activity1("meeting", start, end);

            reg.addActivity(activity1);
            });
    }

    Register reg;
};

TEST_F(RegisterSuite, addActivity) {
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");
    const Activity activity1("Workout", start, end);

    //Verifico il numero di attività in partenza
    ASSERT_EQ(reg.getActivities().size(), 1);

    reg.addActivity(activity1);

    //Verifico il numero di attività e se esiste una proprietà
    ASSERT_EQ(reg.getActivities().size(), 2);
    ASSERT_EQ(reg.getActivities()[1]->getDescription(), "Workout");
}

TEST_F(RegisterSuite, removeActivity) {
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    const QString description = "meeting";

    //Verifico che il valore di ritorno e il numero di attività
    ASSERT_TRUE(reg.removeActivity(description, start));
    ASSERT_EQ(reg.getActivities().size(), 0);
}

TEST_F(RegisterSuite, removeActivityFailed) {
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    const QString description = "Workout";

    //Verifico che il valore di ritorno e il numero di attività
    ASSERT_FALSE(reg.removeActivity(description, start));
    ASSERT_EQ(reg.getActivities().size(), 1);
}

TEST_F(RegisterSuite, clearAll) {
    reg.clearAll();
    ASSERT_EQ(reg.getActivities().size(), 0);
}

TEST_F(RegisterSuite, filterActivities) {
    //Applico filtro che mostra quello che c'è già
    QDate start = QDate::fromString("2025-04-13", "yyyy-MM-dd");

    reg.filterActivities(start);

    ASSERT_EQ(reg.getActivities().size(), 1);

    //Applico filtro che mi svuota le attività
    start = start.addDays(1);

    reg.filterActivities(start);

    ASSERT_EQ(reg.getActivities().size(), 0);

    //Applico filtro con data non valida
    EXPECT_THROW(reg.filterActivities(QDate()), InvalidDateException);
}

TEST_F(RegisterSuite, resetAllActivities) {
    //Prima applico un filtro che mi svuota l'elenco di attività
    const QDate start = QDate::fromString("2025-04-14", "yyyy-MM-dd");

    reg.filterActivities(start);

    //Verifico che sia vuoto
    ASSERT_EQ(reg.getActivities().size(), 0);

    reg.resetAllActivities();

    //Verifico che si sia ripopolato

    ASSERT_EQ(reg.getActivities().size(), 1);
}

TEST_F(RegisterSuite, findActivity) {
    //Cerco quello che ho gia inserito
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    QString description = "meeting";

    int position = reg.findActivity(description, start);

    ASSERT_GE(position, 0);

    //cerco elemento non esistente
    description = "Workout";

    position = reg.findActivity(description, start);

    ASSERT_EQ(position, -1);
}

TEST_F(RegisterSuite, getActivities) {
    //Inizialmente verifico che il QVector rimanga invariato
    ASSERT_EQ(this->reg.getActivities().size(), 1);

    //Applico un filtro al registro
    const QDate start = QDate::fromString("2025-04-14", "yyyy-MM-dd");
    this->reg.filterActivities(start);

    ASSERT_EQ(this->reg.getActivities().size(), 0);
}
