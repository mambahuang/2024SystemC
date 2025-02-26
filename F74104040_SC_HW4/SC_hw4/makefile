#
# Makefile for Assignment 3
#

CC = g++
CFLAGS = -std=c++17 -Wall -g
TARGET = list
SRC = main.cpp
HDR = Node.h List.h

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARGET)

