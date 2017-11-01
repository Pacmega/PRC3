CFLAGS=-Wall -Werror -Wextra -pedantic -O0 -ggdb -Icode -c -std=c++98
LDDFLAGS=-lpthread

MAIN_SOURCES=$(wildcard code/*.cpp)
MAIN_OBJECTS=$(MAIN_SOURCES:.cpp=.o) \
			 objects/FileStructure.o \
			 objects/Key.o \
			 objects/Value.o

TEST_LIBS=-lgtest -lgtest_main -lpthread

CC=g++

.phony: all clean

sort: $(MAIN_OBJECTS) Makefile code/FileStructure.h
	@$(CC) $(MAIN_OBJECTS) -fopenmp -o $@ $(LDDFLAGS)
	
all: sort

.cpp.o: Makefile
	$(CC) $(CFLAGS) -fopenmp $< -o $@

clean:
	@rm -rf sort code/*.o test/*.o *.bin
