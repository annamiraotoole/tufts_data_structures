CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3

TurkeySim: Simulation.o TurkeyMap.o Turkey.o
	${CXX} ${LDFLAGS} -o TurkeySim Simulation.o TurkeyMap.o Turkey.o

Simulation.o:   Simulation.cpp
TurkeyMap.o:    TurkeyMap.cpp   TurkeyMap.h
Turkey.o:	Turkey.cpp Turkey.h

clean:
	rm -rf  TurkeySim *.o *.dSYM

provide:
	provide comp15 lab11 \
                Simulation.cpp \
		TurkeyMap.cpp TurkeyMap.h \
		Turkey.cpp Turkey.h \
                Makefile README
