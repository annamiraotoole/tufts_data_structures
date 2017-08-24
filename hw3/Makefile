CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS = -g3

all: testRPNCalc RPNCalc

testDoubleStack: testDoubleStack.o DoubleStack.o
	${CXX} ${CXXFLAGS} -o testDoubleStack testDoubleStack.o DoubleStack.o
testRPNCalc: testRPNCalc.o RPNCalc.o DoubleStack.o
	${CXX} ${CXXFLAGS} -o testRPNCalc testRPNCalc.o RPNCalc.o DoubleStack.o
RPNCalc: RPNCalc.o DoubleStack.o testRPNCalc.o
	${CXX} ${CXXFLAGS} -o RPNCalc RPNCalc.o DoubleStack.o testRPNCalc.o

testDoubleStack.o: DoubleStack.h testDoubleStack.cpp
DoubleStack.o: DoubleStack.h DoubleStack.cpp

testRPNCalc.o: RPNCalc.h testRPNCalc.cpp
RPNCalc.o: RPNCalc.h RPNCalc.cpp DoubleStack.h
 
clean:
	rm -rf DoubleStack *.o *.dSYM
	rm -rf RPNCalc *.o *.dSYM


provide:
	provide comp15 hw3 DoubleStack.h DoubleStack.cpp RPNCalc.h RPNCalc.cpp README
