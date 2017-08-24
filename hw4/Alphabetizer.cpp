// Comp 15, HW4, Alphabetizer.cpp

// Annamira O'Toole 10/27/16

// implements Alphabetizer class, includes fstream

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>

#include "Alphabetizer.h"
#include "StringBST.h"

using namespace std;

Alphabetizer::Alphabetizer(){

}

Alphabetizer::~Alphabetizer(){

}

void Alphabetizer::run(){
    
    string s;
    cin >> s;

    // sets order
    if (s == "f")
        order = FORWARDS;
    else if (s == "r")
        order = REVERSE;

    // read in strings
    runStream(cin);

    // print tree    
    cout << "[ cin, " + s + " : ";
    if (order == FORWARDS)
        printForwards();
    else if (order == REVERSE)
        printReverse();

    cout << " ]";

}

void Alphabetizer::run(string filename, string s){
    
    // sets order
    if (s == "f")
        order = FORWARDS;
    else if (s == "r")
        order = REVERSE;

    // read in strings with ifstream code from hw3
    std::ifstream input;
    input.open(filename.c_str());
    if (not input.is_open()) {
        cerr << "Unable to read " << filename << endl;
    } else {
        runStream(input);
        input.close();
    }

    // print tree
    cout << "[ " + filename + ", " + s + " : ";
    if (order == FORWARDS)
        printForwards();
    else if (order == REVERSE)
        printReverse();

    cout << " ]";

}

// reads istream string by string and adds each one to String BST "tree"
void Alphabetizer::runStream(istream &myStream){
    while (! myStream.eof()) {
        try {
            string next;
            myStream >> next;
            if ((next != "") && (next != " "))
                tree.add(next);
        } catch (...) {
            cout << "ERROR" << endl;
        }
    }
}

void Alphabetizer::printForwards(){
    
    cout << tree.getMin();
    tree.removeMin();
    while (!tree.isEmpty()){
        cout << ", " + tree.getMin();
        tree.removeMin();
    }

}

void Alphabetizer::printReverse(){

    cout << tree.getMax();
    tree.removeMax();
    while (!tree.isEmpty()){
        cout << ", " + tree.getMax();
        tree.removeMax();
    }

}
