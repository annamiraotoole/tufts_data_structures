// RPNCalc.h, Homework 3, Comp 15

// Annamira O'Toole 9/23/16

#ifndef RPNCALC_H
#define RPNCALC_H

#include "DoubleStack.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

class RPNCalc {

 public:

    RPNCalc();
    ~RPNCalc();

    void run();

 private:

    DoubleStack stack;
    
    void runStream(istream &input);
    bool got_double(string s, double *resultp);
    void clear();
    void add();
    void subtract();
    void multiply();
    void divide();
    void print();

};

#endif
