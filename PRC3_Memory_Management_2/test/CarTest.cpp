#include <gtest/gtest.h>
#include "Car.h"

TEST(TestingTest, TestedTest) // TestingTest is a test_case_name and TestedTest is a test_name
{
	// This test is just a test to test the GoogleTest testing environment
	EXPECT_TRUE( add(2,2) == 4 );
}

TEST(Construct, TestRealisticInput)
{
	Car TestCar = new Car("Henk 500", "Hout", 2, 4);

	TEST_
}

TEST(Construct, TestZeroDiameter)
{
	Car TestCar = new Car("Henk 500", "Hout", 0, 4);

	EXPECT_THROW(diameter, out_of_range);
}

TEST(Construct, TestWheelsLessThanTwo)
{
	Car TestCar = new Car("Henk 500", "Hout", 2, 1);

	EXPECT_THROW(nrWheels, out_of_range);
}



int main(int argc, char const *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}