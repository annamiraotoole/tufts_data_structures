/*
 * Unjumble.cpp
 *
 * Author:  Mark A. Sheldon, Tufts University, Fall 2016
 *          based on an original solution from Mitchell Katz
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Unjumbler.h"
#include "StringList.h"

using namespace std;

int main(int argc, char *argv[])
{
        if (argc < 2 or argc > 3) {
                cerr << "Usage:  " << argv[0] << " word [words_file]" << endl;
                exit(1);
        }
        string    words_file = (argc == 3) ? argv[2] : "words.text";
        Unjumbler unjumbler{words_file};

        unjumbler.unjumble(argv[1])->println();
        
        return 0;
}

