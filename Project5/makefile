#makefile for StringList class with three files:
# StringList.h, StringList.cpp, Driver.cpp

a.out: Driver.o StringList.o
	g++ Driver.o StringList.o

Driver.o: Driver.cpp StringList.h
	g++ -c Driver.cpp

StringList.o: StringList.cpp StringList.h
	g++ -c StringList.cpp



