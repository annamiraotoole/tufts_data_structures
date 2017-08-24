// Comp 15, HW5, sorter.cpp

// Annamira O'Toole 10/30/16

#include "sortAlgs.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) 
{

    // interactive mode (only run with ./sorter)
    if (argc == 3){
        run(argv[1], argv[2]);
    }

    // automated mode (./sorter sortAlg outputMode filename)
    else if (argc == 4){
        run(argv[1], argv[2], argv[3]);
    }

    else { // not sure if the cerr message is correct
        cerr << "Usage: sorter sortAlg outputMode [fileName]" << endl;
        cerr << "where: sortAlg is −s1, −s2, or −s3" << endl;
        cerr << "and outputMode is −−print or −−save" << endl;
        return 1;
    }

    return 0;

}
