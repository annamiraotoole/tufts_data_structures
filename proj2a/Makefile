CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS = -g3

all: treeTraversal

treeTraversal: FSTreeTraversal.o FSTree.o DirNode.o
	${CXX} ${CXXFLAGS} -o treeTraversal FSTreeTraversal.o FSTree.o DirNode.o

FSTreeTraversal.o: FSTreeTraversal.cpp FSTree.h DirNode.h

clean:
	rm -rf FSTreeTraversal.o *.dSYM


provide:
	provide comp15 proj2part2 FSTreeTraversal.cpp
