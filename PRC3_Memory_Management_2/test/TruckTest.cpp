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

	Truck * TestTruck = new Truck(model, material, diameter, nrWheels, power);

	EXPECT_TRUE(TestTruck->getModel() == model);
	EXPECT_TRUE(TestTruck->getNrWheels()== nrWheels);	
	EXPECT_TRUE(TestTruck->getPower() == power);

	delete TestTruck;

}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}