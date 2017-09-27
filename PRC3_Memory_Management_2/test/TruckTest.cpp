#include <gtest/gtest.h>
#include "Truck.h"
#include <string>

//------------------------------------Construct tests: --------------------------------
TEST(Construct, CreateTruckCorrect)
{
	std::string model = "Burger on Wheels";
	std::string material = "Rubber";
	int diameter = 15;
	int nrWheels = 6;
	int power = 9000;

	Truck TestTruck = Truck(model, material, diameter, nrWheels, power);

	EXPECT_TRUE(TestTruck.getModel() == model);
	EXPECT_TRUE(TestTruck.getNrWheels()== nrWheels);	
	EXPECT_TRUE(TestTruck.getPower() == power);
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

	EXPECT_EQ(CopyTruck.getNrWheels(), TestTruck.getNrWheels());
	EXPECT_EQ(CopyTruck.getModel(), TestTruck.getModel());
	EXPECT_EQ(CopyTruck.getPower(), TestTruck.getPower());
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

	EXPECT_EQ(TestTruck.getModel(), OperatorTruck.getModel());
	EXPECT_EQ(TestTruck.getNrWheels(), OperatorTruck.getNrWheels());
	EXPECT_EQ(TestTruck.getPower(), OperatorTruck.getPower());

	// Since OperatorCar is a reference to TestCar, there is no need to delete it.
	// Everything it had that contained allocated memory was cleared by deleting TestCar,
	// deleting OperatorCar as well would cause invalid reads to occur.
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}