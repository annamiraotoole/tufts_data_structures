// Comp 15, Project 2 Final Submission, TestGerp.cpp

// Annamira O'Toole 11/30/166

#include "Gerp.h"

void printPaths();
void printLines();
void printWords1();
//void printAnswers1();
//void printAnswers2();
void printOneAnswer(word_t word);

int main() 
{

    // call desired test functions:
    
 
    return 1;

}

void printPaths() {

    Gerp G;
    
    G.construct_AllPaths("Seeds");
    
    G.printAllPaths();

}

void printLines() {

    Gerp G;

    G.construct_AllPaths("Seeds");
    G.construct_AllLines();

    G.printAllLines();

}

void printWords1() {

    Gerp G;

    G.construct_AllPaths("Seeds");
    G.construct_AllLines();
    G.construct_answers();

}

// commented out because test was written for Gerp before it was implemented 
// with KeyValueMap and used std::map instead

/*
void printAnswers1() {

    Gerp G;

    G.construct_AllPaths("Seeds");
    G.construct_AllLines();
    G.construct_answers();
    G.printAllAnswers();
}

void printAnswers2() {

    Gerp G;

    G.construct_AllPaths("Seeds");
    G.construct_AllLines();
    G.construct_answers();
    G.printInsensitiveAnswers();
}
*/


void printOneAnswer(word_t word) {

    Gerp G;

    G.construct_AllPaths("Seeds");
    G.construct_AllLines();
    G.construct_answers();
    G.printAnswer(word);

}
