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

TEST(nextScanSetGet, CorrectInput)
{
	Scan firstScan = Scan(145616);

	Scan secondScan = Scan(123);

	firstScan.setNext(&secondScan);

	EXPECT_EQ(firstScan.getNext()->getSerialNumber(), secondScan.getSerialNumber());
}

TEST(nextScanSetGet, NoSetBeforeGet)
{
	Scan firstScan = Scan(6353);

	EXPECT_THROW(firstScan.getNext(), std::invalid_argument);
}

TEST(recycle, recycleCorrect)
{
	// Recycling a few times to be sure
	Scan firstScan = Scan(5134);
	EXPECT_EQ(firstScan.getTimesRecycled(), 0);
	firstScan.recycle();
	EXPECT_EQ(firstScan.getTimesRecycled(), 1);
	firstScan.recycle();
	EXPECT_EQ(firstScan.getTimesRecycled(), 2);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}