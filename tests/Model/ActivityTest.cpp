//
// Created by Lorenzo Malavolti on 13/04/2025.
//

#include "../lib/googletest/googletest/include/gtest/gtest.h"
#include "../../Model/Activity.h"
#include <QDateTime>
#include <QString>

#include "../../Exceptions/InvalidDateException.h"
#include "../../Exceptions/InvalidDateRangeException.h"
#include "../../Exceptions/InvalidDescriptionException.h"

TEST(ActivityTest, ToString) {
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");

    const Activity activity("Test Activity", start, end);

    const QString expected = "[2025-04-13 10:00 - 2025-04-13 12:00] Test Activity";
    EXPECT_EQ(activity.toString(), expected);
}

TEST(ActivityTest, ConstructorSuccessfull) {
    const QString description = "Meeting";
    const QDateTime start(QDate(2025, 4, 13), QTime(10, 0));
    const QDateTime end(QDate(2025, 4, 13), QTime(12, 0));

    std::unique_ptr<Activity> activity = nullptr;

    EXPECT_NO_THROW({
        activity = std::make_unique<Activity>(description, start, end);
        });
}

TEST(ActivityTest, ConstructorInvalidDescription) {
    QString description = "";
    const QDateTime start(QDate(2025, 4, 13), QTime(10, 0));
    const QDateTime end(QDate(2025, 4, 13), QTime(12, 0));

    //Stringa completamente vuota
    EXPECT_THROW(Activity(description, start, end), InvalidDescriptionException);

    //Stringa apparentemente vuota
    description = "  ";
    EXPECT_THROW(Activity(description, start, end), InvalidDescriptionException);
}

TEST(ActivityTest, ConstructorInvalidDate) {
    const QString description = "Meeting";
    QDateTime start(QDate(), QTime(10, 0));
    QDateTime end(QDate(2025, 4, 13), QTime(12, 0));

    //Caso 1: data inizio non valida
    EXPECT_THROW(Activity(description, start, end), InvalidDateException);

    //Caso 2: data di fine non valida
    start.setDate(QDate(2025, 4, 13));
    end.setDate(QDate());
    EXPECT_THROW(Activity(description, start, end), InvalidDateException);

    //Caso 3: due date non valide
    start.setDate(QDate());
    end.setDate(QDate());
    EXPECT_THROW(Activity(description, start, end), InvalidDateException);
}

TEST(ActivityTest, CostructorInvalidDateRange) {
    const QString description = "Meeting";
    const QDateTime start(QDate(2025, 4, 13), QTime(10, 0));
    const QDateTime end(QDate(2025, 4, 12), QTime(12, 0));

    EXPECT_THROW(Activity(description, start, end), InvalidDateRangeException);
}


TEST(ActivityTest, Getter) {
    const QString description = "Meeting";
    const QDateTime start(QDate(2025, 4, 13), QTime(10, 0));
    const QDateTime end(QDate(2025, 4, 13), QTime(12, 0));

    std::unique_ptr<Activity> activity = nullptr;

    //Controllo per eccezioni
    EXPECT_NO_THROW({
        activity = std::make_unique<Activity>(description, start, end);
        });

    ASSERT_EQ(activity->getDescription(), description);
    ASSERT_EQ(activity->getStartDateTime(), start);
    ASSERT_EQ(activity->getEndDateTime(), end);
}

TEST(ActivityTest, copyConstructor) {
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");

    const Activity activity("Test Activity", start, end);

    const Activity copyActivity(activity);

    //Verifico che le proprietà siano identiche
    ASSERT_EQ(copyActivity.getDescription(), activity.getDescription());
    ASSERT_EQ(copyActivity.getStartDateTime(), start);
    ASSERT_EQ(copyActivity.getEndDateTime(), end);

    //Confronto anche gli indirizzi di memoria
    ASSERT_NE(&activity, &copyActivity);
}
