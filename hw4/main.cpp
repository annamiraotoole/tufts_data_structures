// Comp 15, HW4, main.cpp

// Annamira O'Toole 10/24/16

// main function for HW4

#include "Alphabetizer.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) 
{
    Alphabetizer A;

    // interactive mode (only run with ./Alphabetizer)
    if (argc == 1){
        A.run();
    }

    // automated mode (./Alphabetizer order filename)
    else if (argc == 3){
        A.run(argv[2], argv[1]);
    }

    else {
        cerr << "Usage: alphabetizer [order filename]" << endl;
        return 1;
    }

    return 0;

}
