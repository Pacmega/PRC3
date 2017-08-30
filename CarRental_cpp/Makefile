CFLAGS=-Wall -Werror -pedantic -ggdb -O0 -std=c++98 -Iproduct

SOURCES=$(wildcard src/*.cpp)
HEADERS=$(wildcard src/*.h)

CC=g++

.phony: all clean

all: CarRental

CarRental: $(SOURCES) $(HEADERS) Makefile
	@$(CC) $(CFLAGS_NORMAL) $(SOURCES) -o $@

clean:
	@rm -rf CarRental
