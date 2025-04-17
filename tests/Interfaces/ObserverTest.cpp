//
// Created by Lorenzo Malavolti on 17/04/2025.
//

#include <gtest/gtest.h>

#include "../../Controller/RegisterController.h"
#include "../../Interfaces/Observer.h"
#include "../../Model/Register.h"

class ObserverTest : public testing::Test, public Observer {
public:
    void update() override {
        updated = true;
    }

    bool isUpdated() const {
        return updated;
    }

protected:
    void SetUp() override {
        this->reg = new Register();
        this->regController = new RegisterController(this->reg);

        this->reg->addObserver(this);
    }

    void TearDown() override {
        this->reg->removeObserver(this);
    }

    Register *reg = nullptr;
    RegisterController *regController = nullptr;
    bool updated = false;
};

TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());

    //Questa era quella più facile
    this->regController->resetAllActivities();
    ASSERT_TRUE(isUpdated());
}
