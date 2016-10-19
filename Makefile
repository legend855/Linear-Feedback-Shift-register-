#Author: Patrick Kyoyetera
#Makefile for PS2b project part b

CC = g++
CFLAGS = -pedantic
OFLAGS =
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

default: PhotoMagic

PhotoMagic: LFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) LFSR.o PhotoMagic.o -o PhotoMagic $(LFLAGS)

lfsr.o: LFSR.cpp LFSR.hpp
	$(CC) $(CFLAGS) -c LFSR.cpp 

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp

clean:
	rm *.o PhotoMagic
