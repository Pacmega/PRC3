#include <gtest/gtest.h>
#include "Car.h"
#include <string>

//------------------------------------removeWheel tests: --------------------------------
// Check if removeWheel works correctly when you use it properly
TEST(removeWheel, removeWheelFromEnd)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
	TestCar.removeWheel(3);
	EXPECT_TRUE(TestCar.getNrWheels() == 3);
}

// Remove wheel from the middle
TEST(removeWheel, removeWheelFromMiddle)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
	TestCar.removeWheel(2);
	EXPECT_TRUE(TestCar.getNrWheels() == 3);
}

// Check if removeWheel outputs an error when you do give an index that is out of range
TEST(removeWheel, removeWheelNotExistingIndex)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
	EXPECT_THROW(TestCar.removeWheel(5), std::out_of_range);
}

//------------------------------------addWheel tests: --------------------------------
// Check if you add a wheel when you give correct input
TEST(AddingWheel, AddWheelCorrectly)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
	TestCar.addWheel(5, "Aluminium");
	EXPECT_TRUE(TestCar.getNrWheels() == 5);
}

// When giving a diameter that's zero
TEST(AddingWheel, AddWheelZeroDiameter)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
	EXPECT_THROW(TestCar.addWheel(0, "Aluminium"), std::out_of_range);
}

// When giving a diameter that's below zero
TEST(AddingWheel, AddWheelBelowZeroDiameter)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
	EXPECT_THROW(TestCar.addWheel(-1, "Aluminium"), std::out_of_range);
}

// When giving a weird material
TEST(AddingWheel, addWheelSpaceAsMaterial)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
	EXPECT_THROW(TestCar.addWheel(-1, " "), std::out_of_range);
}

//------------------------------------Constructor tests: --------------------------------
// Normal input in the constructor
TEST(Construct, TestRealisticInput)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car* TestCar;

	EXPECT_NO_THROW(TestCar = new Car(model, "Hout", diameter, nrWheels));

	// Because we need to check no errors are thrown, we need to use a pointer. This means it needs to be
	// deleted when we're done with it.
	delete TestCar;
}

// 0 diameter as input in the constructor
TEST(Construct, TestZeroDiameter)
{
	int diameter = 0;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	EXPECT_THROW(Car(model, "Hout", diameter, nrWheels), std::out_of_range);
}

// Less wheels than recommended
TEST(Construct, TestWheelsLessThanTwo)
{
	int diameter = 2;
	int nrWheels = 1;
	std::string model = "Henk 9000";
	EXPECT_THROW(Car(model, "Hout", diameter, nrWheels), std::out_of_range);
}

//------------------------------------getModel tests: --------------------------------

// Making a normal model and test if the parameters are equal
TEST(GetModel, getModelNormal)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getModel() == model);
}

//------------------------------------setLicencePlate tests: --------------------------------
// Setting a decent licenceplate and trying to retrieve it (for comparison)
TEST(SetAndGetLicencePlate, SetLicencePlateCorrect)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	std::string Plate = "AABBCC11";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	TestCar.setLicencePlate(Plate);
	EXPECT_TRUE(TestCar.getLicencePlate() == Plate);
}

//------------------------------------getNrWheels tests: --------------------------------

TEST(getNrWheels, TestFor4WheelsCorrect)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 4);
}

TEST(getNrWheels, TestFor3WheelsCorrect)
{
	int diameter = 2;
	int nrWheels = 3;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	EXPECT_TRUE(TestCar.getNrWheels() == 3);
}

//------------------------------------CopyCar tests: --------------------------------

TEST(copyCar, CopyingACar)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels);

	//Car * CopyCar = TestCar;
	Car CopyCar = Car(TestCar);

	EXPECT_TRUE(CopyCar.getNrWheels() == TestCar.getNrWheels());
	EXPECT_TRUE(CopyCar.getModel() == TestCar.getModel());

<<<<<<< HEAD
	delete TestCar;
=======
	//
	//delete CopyCar;
>>>>>>> 04e2a0bceb11354769a03019bc900d0cf1170563
}

//------------------------------------AssignmentOperator tests: --------------------------------


TEST(AssignmentOperator, CorrectAssignmentOperator)
{
	int diameter = 2;
	int nrWheels = 4;
	std::string model = "Henk 9000";
	Car TestCar = Car(model, "Hout", diameter, nrWheels); 

	Car OperatorCar = TestCar;

	EXPECT_TRUE(TestCar.getModel() == OperatorCar.getModel());
	EXPECT_TRUE(TestCar.getNrWheels() == OperatorCar.getNrWheels());

	

	// Since OperatorCar is a reference to TestCar, there is no need to delete it.
	// Everything it had that contained allocated memory was cleared by deleting TestCar,
	// deleting OperatorCar as well would cause invalid reads to occur.
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}