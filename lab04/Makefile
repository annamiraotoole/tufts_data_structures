CXX      = clang++
CXXFLAGS = -g -Wall -Wextra -std=c++11
LDFLAGS  = -g

unjumble:  unjumble.o Unjumbler.o StringList.o string_utils.o
	${CXX} ${CXXFLAGS} -o unjumble unjumble.o   Unjumbler.o     \
                                       StringList.o string_utils.o

unjumble.o:      unjumble.cpp     Unjumbler.h
Unjumbler.o:     Unjumbler.cpp    Unjumbler.h  StringList.h string_utils.h
StringList.o:    StringList.cpp   StringList.h
string_utils.o:  string_utils.cpp string_utils.h

clean:
	rm -rf unjumble *.o *.dSYM

provide:
	provide comp15 lab4 unjumble.cpp Unjumbler.cpp Unjumbler.h  \
                            StringList.cpp StringList.h             \
                            string_utils.cpp string_utils.h
