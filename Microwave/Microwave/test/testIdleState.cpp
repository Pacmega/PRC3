#include "Microwave.h"

#include "mLight.h"
#include "mMotor.h"
#include "mSystem.h"
#include "mUserInterface.h"

using ::testing::Return;
using ::testing::_;

class TestStates : public ::testing::Test 
{
  protected:

    TestStates() 
    {
        microwave = new Microwave(light, motor, system, ui);
    }

    virtual ~TestStates() 
    {
        delete microwave;
        microwave = NULL;
    }

    mLight light;
    mMotor motor;
    mSystem system;
    mUserInterface ui;
    Microwave* microwave;
};

TEST_F(TestStates, standby_test_start_event)
{
    EXPECT_CALL(light, LightOn())
                .Times(1);
    
    // After being created, the microwave has a default power of 0.
    EXPECT_CALL(motor, SetPower(0))
                .Times(1);

    EXPECT_EQ(STATE_OPERATING, microwave->HandleStandbyState(EV_START));
}

TEST_F(TestStates, standby_test_change_power_event)
{
    EXPECT_CALL(ui, GetReqPower())
                .Times(1);

    // State should not be changed
    EXPECT_EQ(STATE_STANDBY, microwave->HandleStandbyState(EV_CHANGEPOWER));
}

TEST_F(TestStates, standby_test_open_door_event)
{
    EXPECT_CALL(light, LightOn())
                .Times(1);

    // State should not be changed
    EXPECT_EQ(STATE_STANDBY, microwave->HandleStandbyState(EV_OPENDOOR));
}
