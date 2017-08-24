CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS = -g3

all: main


testOrderqueue:	testOrderqueue.o Orderqueue.o 
	${CXX} ${CXXFLAGS} -o testOrderqueue testOrderqueue.o Orderqueue.o
testNozama: 	testNozama.o Nozama.o Orderqueue.o Parser.o
	${CXX} ${CXXFLAGS} -o testNozama testNozama.o Nozama.o Orderqueue.o \
		Parser.o
main: main.o Nozama.o Orderqueue.o Parser.o
	${CXX} ${CXXFLAGS} -o main main.o Nozama.o Orderqueue.o Parser.o

testOrderqueue.o: Orderqueue.h testOrderqueue.cpp
Orderqueue.o: Orderqueue.h Orderqueue.cpp Order.h

testNozama.o: Nozama.h testNozama.cpp
Nozama.o: Nozama.h Nozama.cpp Orderqueue.h Parser.h

main.o: main.cpp Nozama.h

testoutput:
	./main data/random1.txt 3 ROUND_ROBIN > out1-3r.txt
	./main data/random1.txt 3 FEWEST_ITEMS > out1-3f.txt
	./main data/random1.txt 3 SHORTEST_TIME > out1-3s.txt

viewdiff-r:
	diff data/rand1_3packers_ROUND_ROBIN.txt out1-3r.txt
 
viewdiff-f:
	diff data/rand1_3packers_FEWEST_ITEMS.txt out1-3f.txt
 
viewdiff-s:
	diff data/rand1_3packers_SHORTEST_TIME.txt out1-3s.txt
 
clean:
	rm -rf Orderqueue *.o *.dSYM
	rm -rf Nozama *.o *.dSYM
	rm -rf main *.o *.dSYM

provide:
	provide comp15 proj1part2 Orderqueue.cpp Orderqueue.h Order.h \
		Parser.h Parser.cpp Nozama.cpp Nozama.h main.cpp README \
		Makefile
