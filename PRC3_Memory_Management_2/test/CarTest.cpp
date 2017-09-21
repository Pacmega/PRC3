#include <gtest/gtest.h>

TEST(TestingTest, TestedTest)
{
	// This test is just a test to test the GoogleTest testing environment
	EXPECT_TRUE( add(2,2) == 4 );
}

int main(int argc, char const *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}