#include <gtest/gtest.h>
#include "ScanList.h"
#include "Scan.h"

TEST(getNrElements, correctInput)
{
	ScanList List = ScanList();
	// Test to see if it will work with 0 elements
	EXPECT_EQ(List.getNrElements(), 0);

	Scan firstScan = Scan(10);
	List.addScan(firstScan.getSerialNumber());

	EXPECT_EQ(List.getNrElements(), 1);

	Scan secondScan = Scan(645354);
	List.addScan(secondScan.getSerialNumber());

	EXPECT_EQ(List.getNrElements(), 2);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}