//
// Created by Lorenzo Malavolti on 13/04/2025.
//

#include "gtest/gtest.h"
#include "../Register.h"

class RegisterSuite : public ::testing::Test {
protected:
    void SetUp() override {
        const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
        const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");
        const Activity activity1("meeting", start, end);

        reg.addActivity(activity1);
    }

    Register reg;
};

TEST_F(RegisterSuite, addActivity) {
    const QDateTime start = QDateTime::fromString("2025-04-13 10:00", "yyyy-MM-dd HH:mm");
    const QDateTime end = QDateTime::fromString("2025-04-13 12:00", "yyyy-MM-dd HH:mm");
    const Activity activity1("Workout", start, end);

    ASSERT_EQ(reg.getActivities().size(), 1);

    reg.addActivity(activity1);

    ASSERT_EQ(reg.getActivities().size(), 2);
    ASSERT_EQ(reg.getActivities()[1].getDescription(), "Workout");
}

TEST_F(RegisterSuite, removeActivity) {
    ASSERT_TRUE(reg.removeActivity(0));
    ASSERT_EQ(reg.getActivities().size(), 0);
}

TEST_F(RegisterSuite, clearAll) {
    reg.clearAll();
    ASSERT_EQ(reg.getActivities().size(), 0);
}
