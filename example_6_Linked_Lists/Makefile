PROJECT_NAME=LinkedList

CFLAGS=-Wall -Werror -ggdb -O0 -Iproduct

MAIN_SOURCES=product/*.cpp

SCANLIST_SOURCES=product/ScanList.cpp \
				 product/Scan.cpp \
				 test/testScanList.cpp \

SCAN_SOURCES=product/Scan.cpp \
			 test/testScan.cpp

TEST_LIBS=-lgtest -lgtest_main -lpthread

GCC=g++

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(MAIN_SOURCES) Makefile product/*.h
	@$(GCC) $(CFLAGS) $(MAIN_SOURCES) -o $@

testScanlist: $(SCANLIST_SOURCES) Makefile product/ScanList.h
	@$(GCC) $(CFLAGS) $(SCANLIST_SOURCES) $(TEST_LIBS) -o $@

testScan: $(SCAN_SOURCES) Makefile product/Scan.h
	@$(GCC) $(CFLAGS) $(SCAN_SOURCES) $(TEST_LIBS) -o $@

clean:
	@rm -rf $(PROJECT_NAME) testScanlist testScan

scanlist: testScanlist
	@valgrind ./testScanlist
	@rm testScanlist

scan: testScan
	@valgrind ./testScan
	@rm testScan