// RPNCalc.cpp, Homework 3, Comp 15

// Annamira O'Toole 9/23/16

// RPNCalc.cpp implements the public and private functions declared in RPNCalc.h
                                                                                                                  

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>
#include "RPNCalc.h"

using namespace std;

RPNCalc::RPNCalc(){
    stack = DoubleStack();
}

RPNCalc::~RPNCalc(){
    
}

// if stack is not already empty clear() pops off (removes)
// every element on the stack
void RPNCalc::clear(){
    if (stack.size() == 0)
        return;
    while (stack.size() != 0)
        stack.pop();
}

// pops off and remembers values of top two elements
// on stack, takes the sum, and pushes the sum onto
// the top of the stack
void RPNCalc::add(){
    double a = stack.pop();
    double b = stack.pop();
    stack.push(a + b);
}

// pops off and remembers values of top two elements                
// on stack, takes the difference, and pushes it onto         
// the top of the stack 
void RPNCalc::subtract(){
    double a = stack.pop();
    double b = stack.pop();
    stack.push(a - b);
}

// pops off and remembers values of top two elements
// on stack, takes the product, and pushes it onto
// the top of the stack  
void RPNCalc::multiply(){
    double a = stack.pop();
    double b = stack.pop();
    stack.push(a * b);
}

// pops off and remembers values of top two elements                           
// on stack, takes the quotient, and pushes it onto                               
// the top of the stack  
void RPNCalc::divide(){
    double a = stack.pop();
    double b = stack.pop();
    stack.push(a / b);
}

// prints the value of the element at the top of the stack
void RPNCalc::print(){
    cout << stack.top() <<endl;
}

bool RPNCalc::got_double(string s, double *resultp)
{
    return sscanf(s.c_str(), "%lf", resultp) == 1;
}

// private
// takes in parameter of type istream, such as cin
// while it hasn't reached the end of the stream,
// it takes off and checks if each substring (term?)
// is a valid command, if so it executes it, if not
// a message is printed to alert the user
void RPNCalc::runStream(istream &myStream){
    while (! myStream.eof()) {
        try {
        double n;
        string s;
        myStream >> s;
        if (s == "p") {
            print();
        } else if (got_double(s, &n)) { // use got_double from Mark's file got_double.cpp
            stack.push(n);            
        } else if (s == "c" || s == "C") {
            clear();
        } else if (s == "f" || s == "F") { // use Mark's file reading code
            string filename;
            ifstream input;
            myStream >> filename;
            input.open(filename.c_str());
            if (not input.is_open()) {
                cerr << "Unable to read " << filename << endl;
            } else {
                runStream(input);
                input.close();
            }
        } else if (s == "q" || s == "Q") {
            return;
        } else if (s == "+") {
            add();
        } else if (s == "-") {
            subtract();
        } else if (s == "*") {
            multiply();
        } else if (s == "/") {
            divide();
        } else if (!(s == "")) {
            cerr << s << ": unimplemented" << endl;
        }
        } catch (...) {
            cout << "empty_stack" << endl;
        }
    }
}

// private run fuction, taking in no parameters, calls runStream()
void RPNCalc::run(){
    runStream(cin);
}
