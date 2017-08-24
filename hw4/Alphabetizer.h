// Comp 15, HW4, Alphabetizer.h

// Annamira O'Toole 10/27/16

// header file for Alphabetizer class, includes iostream and cstdio

#ifndef ALPHABETIZER_H
#define ALPHABETIZER_H

#include "StringBST.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

class Alphabetizer {

public:

Alphabetizer();
~Alphabetizer();

void run(); // launches command line version of Alphabetizer
void run(string filename, string order); // reads from files and prints to cout

private:

const int FORWARDS = 0;
const int REVERSE = 1;
StringBST tree;
int order;

void runStream(istream &myStream); // handles reading strings into the
// StringBST "tree"

void printForwards();
void printReverse();

};

#endif
