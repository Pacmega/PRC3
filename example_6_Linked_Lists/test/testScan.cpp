#include <gtest/gtest.h>
#include "Scan.h"

TEST(constructor, CorrectInput)
{
	Scan firstScan = Scan(145616);

	EXPECT_EQ(firstScan.getSerialNumber(), 145616);

	Scan secondScan = Scan(123);

	EXPECT_EQ(secondScan.getSerialNumber(), 123);

}

TEST(constructor, NumberBelowZero)
{
	// Shoudln't allow objectnumbers smaller than 0
	EXPECT_THROW(Scan(-200), std::out_of_range);
}

TEST(NextScanSetGet, CorrectInput)
{
	Scan firstScan = Scan(145616);

	Scan secondScan = Scan(123);

	firstScan.setNext(&secondScan);

	EXPECT_EQ(firstScan.getNext()->getSerialNumber(), secondScan.getSerialNumber());
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

// This is just a test