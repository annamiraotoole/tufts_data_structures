CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS = -g3

all: main testNozama testOrderqueue


testOrderqueue:	testOrderqueue.o Orderqueue.o 
	${CXX} ${CXXFLAGS} -o testOrderqueue testOrderqueue.o Orderqueue.o
testNozama: 	testNozama.o Nozama.o Orderqueue.o
	${CXX} ${CXXFLAGS} -o testNozama testNozama.o Nozama.o Orderqueue.o
Orderqueue:	Orderqueue.o Order.o
	${CXX} ${CXXFLAGS} -o Orderqueue Orderqueue.o
Nozama:	Nozama.o Orderqueue.o testNozama.o
	${CXX} ${CXXFLAGS} -o Nozama Nozama.o Orderqueue.o testNozama.o
main: main.o Nozama.o Orderqueue.o
	${CXX} ${CXXFLAGS} -o main main.o Nozama.o Orderqueue.o

testOrderqueue.o: Orderqueue.h testOrderqueue.cpp
Orderqueue.o: Orderqueue.h Orderqueue.cpp Order.h

testNozama.o: Nozama.h testNozama.cpp
Nozama.o: Nozama.h Nozama.cpp Orderqueue.h

main.o: main.cpp Nozama.h
 
clean:
	rm -rf Orderqueue *.o *.dSYM
	rm -rf Nozama *.o *.dSYM
	rm -rf main *.o *.dSYM

provide:
	provide comp15 proj1part1 Orderqueue.cpp Orderqueue.h Order.h Nozama.h README Makefile
