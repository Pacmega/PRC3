#
#	Makefile for Sluice
#
#	© Joran van Teeffelen & Bas Witters
#

TARGET = sluice

FILES = code/*.cpp
HEADERS = code/*.h

LIBS = -lm

CFLAGS = -Wall -Werror -o

CC = g++

.PHONY: default all clean

sluice: $(FILES) Makefile $(HEADERS)
	@$(CC) $(CFLAGS) $(FILES) $(CFLAGS) $(TARGET)

clean:
	-rm -f *.o
	-rm -f $(TARGET)