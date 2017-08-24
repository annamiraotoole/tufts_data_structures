CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS = -g3

all: sorter

sorter: sorter.o sortAlgs.o
	${CXX} ${CXXFLAGS} -o sorter sorter.o sortAlgs.o

sorter.o: sorter.cpp sortAlgs.h

sortAlgs.o: sortAlgs.h sortAlgs.cpp

clean:
	rm -rf sorter *.o *.dSYM
	rm -rf sortAlgs *.o *.dSYM


provide:
	provide comp15 hw5 sorter.cpp sortAlgs.h sortAlgs.cpp README Makefile
