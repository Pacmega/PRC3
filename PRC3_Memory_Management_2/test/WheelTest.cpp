#include <gtest/gtest.h>
#include "Wheel.h"
#include <string>
//------------------------------------Constructor tests: --------------------------------

TEST(Construct, CorrectWheel)
{
	int diameter = 5;
	std::string material = "Aluminium";
	Wheel TestWiel = new Wheel(diameter, material);

	EXPECT_TRUE(TestWiel->getMaterial() == material);
	EXPECT_TRUE(TestWiel->getDiameter() == diameter);
}

TEST(Construct, ZeroDiameter)
{
	int diameter = 0;
	std::string material = "Aluminium";
	EXPECT_THROW(new Wheel(diameter, material), std::out_of_range);
}

TEST(Construct, BelowZeroDiameter)
{
	int diameter = -1;
	std::string material = "Aluminium";
	EXPECT_THROW(new Wheel(diameter, material), std::out_of_range);
}

TEST(Construct, NoMaterial)
{
	int diameter = 5;
	std::string material = "";
	EXPECT_THROW(new Wheel(diameter, material), std::invalid_argument);
}

//------------------------------------SetAndGetMaterial tests: --------------------------------

TEST(SetAndGetMaterial, SetAndGetMaterialCorrect)
{
	int diameter = 5;
	std::string material = "Aluminium";	
	std::string newMaterial = "Staal";

	Wheel TestWiel = new Wheel(diameter, material);

	EXPECT_TRUE(TestWiel->getMaterial() == material);
	TestWiel->setMaterial(newMaterial);
	EXPECT_TRUE(TestWiel->getMaterial() = newMaterial);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}