#include <gtest/gtest.h>
#include "Truck.h"
#include <string>
//------------------------------------Construct tests: --------------------------------
TEST(Construct, CreateTruckCorrect)
{
	std::string model = "Burger on Wheels";
	
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}