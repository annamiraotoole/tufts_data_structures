CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS = -g3

all: gerp TestGerp

gerp: Gerp.o main.o FSTree.o DirNode.o KeyValueMap.o
	${CXX} ${CXXFLAGS} -o gerp Gerp.o main.o FSTree.o DirNode.o KeyValueMap.o

TestGerp: Gerp.o TestGerp.o FSTree.o DirNode.o KeyValueMap.o
	${CXX} ${CXXFLAGS} -o TestGerp Gerp.o TestGerp.o FSTree.o DirNode.o KeyValueMap.o

TestGerp.o: Gerp.h TestGerp.cpp FSTree.h DirNode.h KeyValueMap.h

main.o: Gerp.h TypeDefs.h 

Gerp.o: KeyValueMap.h Gerp.h Gerp.cpp main.cpp TypeDefs.h FSTree.h DirNode.h

KeyValueMap.o: KeyValueMap.h KeyValueMap.cpp TypeDefs.h

clean:
	rm -rf gerp *.dSYM
	rm -rf TestGerp *.dSYM

provide:
	provide comp15 proj2part3 KeyValueMap.h KeyValueMap.cpp Gerp.h Gerp.cpp main.cpp TypeDefs.h TestGerp.cpp FSTree.h DirNode.h FSTree.o DirNode.o README Makefile
