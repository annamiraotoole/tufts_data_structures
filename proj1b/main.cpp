// main.cpp, Project 1b, Comp 15

// Annamira O'Toole 10/12/16

// main function that simulates Nozama, only can call public Nozama functions
// uses sscanf function to parse number of packers from command line

#include "Nozama.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    string filename;
    int numOfPackers;
    string algName;

    // Make sure we got 1 command-line argument:  the file name
    if (argc != 4){
        //usage_abort(argv[0]);
        throw 0;
    }

    filename = argv[1];

    // parses and sets numOfPackers = number of packers wanted by client
    sscanf(argv[2], "%d", &numOfPackers);

    algName = argv[3];

    Nozama factory(numOfPackers, algName, filename);

    factory.simulate();

    return 0;
}
