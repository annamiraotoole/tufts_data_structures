CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS = -g3

all: gerp TestGerp

gerp: Gerp.o main.o FSTree.o DirNode.o
	${CXX} ${CXXFLAGS} -o gerp Gerp.o main.o FSTree.o DirNode.o

TestGerp: Gerp.o TestGerp.o FSTree.o DirNode.o
	${CXX} ${CXXFLAGS} -o TestGerp Gerp.o TestGerp.o FSTree.o DirNode.o

TestGerp.o: Gerp.h TestGerp.cpp FSTree.h DirNode.o

main.o: Gerp.h TypeDefs.h

Gerp.o: KeyValueMap.h Gerp.h Gerp.cpp main.cpp TypeDefs.h FSTree.h DirNode.o

KeyValueMap.o: KeyValueMap.h

clean:
	rm -rf Gerp *.dSYM
	rm -rf TestGerp *.dSYM

provide:
	provide comp15 proj2part2 KeyValueMap.h LineInventory.h LineInventory.cpp Gerp.h Gerp.cpp main.cpp TypeDefs.h TestGerp.cpp Makefile
