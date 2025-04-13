//
// Created by Lorenzo Malavolti on 13/04/2025.
//

#include "gtest/gtest.h"
#include "../Activity.h"
#include <QDateTime>
#include <QString>
#include <QTime>

TEST(ActivityTest, ToString) {
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");

    Activity activity("Test Activity", start, end);

    const QString expected = "[2025-04-13 10:00 - 2025-04-13 12:00] Test Activity";
    EXPECT_EQ(activity.toString(), expected);
}

TEST(ActivityTest, ConstructorAndGetter) {
    const QString description = "Meeting";
    const QDateTime start(QDate(2025, 4, 13), QTime(10, 0));
    const QDateTime end(QDate(2025, 4, 13), QTime(12, 0));

    Activity activity(description, start, end);

    ASSERT_EQ(activity.getDescription(), description);
    ASSERT_EQ(activity.getStartDateTime(), start);
    ASSERT_EQ(activity.getEndDateTime(), end);
}
