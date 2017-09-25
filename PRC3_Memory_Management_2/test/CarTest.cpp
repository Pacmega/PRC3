#include <gtest/gtest.h>
#include "Car.h"

TEST(TestingTest, TestedTest) // TestingTest is a test_case_name and TestedTest is a test_name
{
	// This test is just a test to test the GoogleTest testing environment
	EXPECT_TRUE( (2+2) == 4 );
}

TEST(Construct, TestRealisticInput)
{
	EXPECT_NO_THROW(new Car("Henk 500", "Hout", 2, 4););
}

TEST(Construct, TestZeroDiameter)
{
	int diameter = 0;
	int nrWheels = 4;
	EXPECT_THROW(new Car("Henk 500", "Hout", diameter, nrWheels), std::out_of_range);
}

TEST(Construct, TestWheelsLessThanTwo)
{
	int diameter = 2;
	int nrWheels = 1;
	EXPECT_THROW(new Car("Henk 500", "Hout", diameter, nrWheels), std::out_of_range);
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}