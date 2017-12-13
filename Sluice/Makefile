#
#	Makefile for Sluice
#
#	(c) Fontys 2010, Joris Geurts
#

BINARIES = /code/*

FILES = 

CC = g++
CFLAGS = -g3 -Wall -W -Wshadow -Wcast-qual -Wwrite-strings
LDLIBS = -lrt
CLIENT_AUX_OBJS = Auxiliary.o CreateTCPClientSocket.o

all:	$(BINARIES)

clean:
	rm *.o $(BINARIES)

TCPEchoClient: TCPEchoClient.o $(CLIENT_AUX_OBJS)


