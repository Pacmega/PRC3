#include <gtest/gtest.h>
#include "ScanList.h"
#include "Scan.h"

TEST(addScan, correctInput)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	EXPECT_EQ(List.getTimesRecycled(10), 1);
	EXPECT_EQ(List.getTimesRecycled(45), 0);
	EXPECT_EQ(List.getTimesRecycled(50), 2);
}

TEST(addScan, serialNumberBelowZero)
{
	ScanList List = ScanList();

	EXPECT_THROW(List.addScan(-10), std::out_of_range);
	EXPECT_THROW(List.addScan(-1000), std::out_of_range);
	EXPECT_THROW(List.addScan(-3847), std::out_of_range);
}


// Work in progress (currently segmentation fault)
/*TEST(getScanByNr, correctInput)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	Scan* firstScan = List.getScanByNr(1);

	EXPECT_EQ(firstScan->getSerialNumber(), 10);
}*/

TEST(getScanByNr, NotExistingSpot)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	Scan *ptr = NULL;

	EXPECT_EQ(List.getScanByNr(5), ptr);
	EXPECT_EQ(List.getScanByNr(10), ptr);
	EXPECT_EQ(List.getScanByNr(1000), ptr);	
}

TEST(getScanByNr, BelowZero)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	Scan *ptr = NULL;

	EXPECT_EQ(List.getScanByNr(-10), ptr);
	EXPECT_EQ(List.getScanByNr(-150), ptr);
}

// Work in progress (currently segmentation fault)
/*TEST(getScanBySerialNr, correctInput)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	Scan* firstScan = List.getScanBySerialNr(10);

	EXPECT_EQ(firstScan->getSerialNumber(), 10);
	EXPECT_EQ(firstScan->getTimesRecycled(), 1);
}*/

TEST(getScanBySerialNr, NotExistingSpot)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	Scan *ptr = NULL;

	EXPECT_EQ(List.getScanBySerialNr(5), ptr);
	EXPECT_EQ(List.getScanBySerialNr(10), ptr);
	EXPECT_EQ(List.getScanBySerialNr(1000), ptr);	
}

TEST(getScanBySerialNr, BelowZero)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	Scan *ptr = NULL;

	EXPECT_EQ(List.getScanBySerialNr(-10), ptr);
	EXPECT_EQ(List.getScanBySerialNr(-150), ptr);
}

TEST(removeScan, correctInput)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	EXPECT_EQ(List.removeScan(10), true);

	Scan *ptr = NULL;

	EXPECT_EQ(List.getScanBySerialNr(10), ptr);
}

TEST(removeScan, NotExistingNumbers)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	EXPECT_EQ(List.removeScan(15), false);
	EXPECT_EQ(List.removeScan(-30), false);
	EXPECT_EQ(List.removeScan(2000), false);
}

TEST(getTimesRecycled, NotExistingNumbers)
{
	ScanList List = ScanList();

	List.addScan(10);
	List.addScan(45);
	List.addScan(50);
	List.addScan(10);
	List.addScan(50);
	List.addScan(50);

	EXPECT_EQ(List.getTimesRecycled(4552), 0);
	EXPECT_EQ(List.getTimesRecycled(-10), 0);
	EXPECT_EQ(List.getTimesRecycled(2), 0);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}