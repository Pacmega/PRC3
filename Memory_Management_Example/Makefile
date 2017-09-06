PROJECT_NAME=MemoryManagement

CFLAGS=-Wall -Werror -Wextra -pedantic -Wno-unused-variable -ggdb -O0 -Iproduct

SOURCES=$(wildcard product/*.cpp)
HEADERS=$(wildcard product/*.h)

CC=g++

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(SOURCES) $(HEADERS) Makefile
	@$(CC) $(CFLAGS) $(SOURCES) -o $@

clean:
	@rm -rf $(PROJECT_NAME)
