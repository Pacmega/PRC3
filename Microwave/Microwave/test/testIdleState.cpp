#include "Microwave.h"

#include "mLight.h"
#include "mMotor.h"
#include "mSystem.h"
#include "mUserInterface.h"

using ::testing::Return;
using ::testing::_;

class TestIdleState : public ::testing::Test {
  protected:

    TestIdleState() {
        microwave = new Microwave(light, motor, system, ui);
    }

    virtual ~TestIdleState() {
        delete microwave;
        microwave = NULL;
    }

    mLight light;
    mMotor motor;
    mSystem system;
    mUserInterface ui;
    Microwave* microwave;
};

TEST_F(TestIdleState, test_start_event)
{
    // EXPECT_CALL(ui, GetRequestedPower()).WillOnce(Return(800));
    // EXPECT_CALL(motor, SetPower(800));
    EXPECT_EQ(STATE_HEATING, microwave->HandleIdleState(EV_START));
}

