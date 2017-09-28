#include <gtest/gtest.h>
#include "Truck.h"
#include <string>

//------------------------------------Construct tests: --------------------------------
TEST(Construct, CreateTruckCorrect)
{
	Truck TestTruck = Truck("Burger on Wheels", "Rubber", 5, 4, 90);

	ASSERT_EQ(TestTruck.getModel(), "Burger on Wheels");
	ASSERT_EQ(TestTruck.getNrWheels(), 4);	
	ASSERT_EQ(TestTruck.getPower(), 90);
}

TEST(Construct, CreateTruckNotPossiblePower)
{
	std::string model = "Burger on Wheels";
	std::string material = "Rubber";
	int diameter = 15;
	int nrWheels = 6;
	int power = -10;

	EXPECT_THROW(Truck(model, material, diameter, nrWheels, power), std::out_of_range);
}

//------------------------------------CopyTruck tests: --------------------------------

TEST(copyTruck, CopyingATruck)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	int power = 50;
	Truck TestTruck = Truck(model, "Hout", diameter, nrWheels, power);

	Truck CopyTruck = Truck(TestTruck);

	ASSERT_EQ(CopyTruck.getNrWheels(), TestTruck.getNrWheels());
	ASSERT_EQ(CopyTruck.getModel(), TestTruck.getModel());
}

//------------------------------------AssignmentOperator tests: --------------------------------


TEST(AssignmentOperator, CorrectAssignmentOperator)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	int power = 50;
	Truck TestTruck = Truck(model, "Hout", diameter, nrWheels, power);

	Truck OperatorTruck = TestTruck;

	ASSERT_EQ(TestTruck.getModel(), OperatorTruck.getModel());
	ASSERT_EQ(TestTruck.getNrWheels(), OperatorTruck.getNrWheels());
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}