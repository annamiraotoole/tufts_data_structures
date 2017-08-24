###
### Makefile for Trie lab
###
### Author:  Mark A. Sheldon, Tufts University
###
### Note: There are two executables built here, both from the same
### sources:
###
###     trie:      The program you can run from the command line.
###     trie_web:  The program run by the web server when you use
###                the web interface.
###
### The issue is that web server's configuration may be different, so
### that it may not be able to run the same binary as the computers
### you log into.  (In fall of 2016, this is true.)
### 
### When you "make trie", the program is compiled and linked as usual,
### and you can run "trie" from the command line to test.  But we also
### need a binary built on the web server, which you cannot log in to.
### To accomplish this, we installed a CGI script that you can run on
### the server that will compile and link your program and print out
### any messages that result.  This script is run by the "wget"
### command that runs when you run "make".  Read these messages: It's
### possible to have a program compile locally and not on the web
### server.  If the remote build is successful, then the web server
### will run "trie_web".
###
### Interestingly, right now, you can run both binaries on the
### homework servers, but only trie_web on the web server.
###
###
### More background:
###
### In Fall 2016, a change in server configurations meant executables
### produced by the students would not run on the web server, because
### they couldn't load the correct dynamic libraries.  One option was
### to statically link.  We tried to statically link the C++ library,
### but that wasn't enough, and rather than just throw all the static
### linking switches at it, we decided to convince the web server to
### build the program.
###

CXX      = clang++
CXXFLAGS = -O0 -g -Wall -Wextra

HDRS  = Node.h Trie.h cgiBackend.h
SRCS  = main.cpp Node.cpp cgiBackend.cpp Trie.cpp
EXECS = trie trie_web

trie: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} -o trie ${SRCS}
	chmod a+rx trie
	wget -O- -q http://www.cs.tufts.edu/~$$USER/lab9/build_on_server.cgi

trie_web:  ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} -o $@ ${SRCS}
	chmod a+rx $@

clean:
	rm -rf ${EXECS} *.dSYM

provide:
	provide comp15 lab9 main.cpp Node.cpp Node.h Trie.cpp Trie.h \
	                    Makefile cgiBackend.h cgiBackend.cpp
