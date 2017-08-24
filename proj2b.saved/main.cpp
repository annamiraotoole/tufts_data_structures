// Comp 15, Project 2 Final Submission, main.cpp

// Annamira O'Toole 11/30/16

#include "Gerp.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <vector>
// include other stuff? TODO 

using namespace std;

int main(int argc, char *argv[]) 
{
    Gerp G;

    if (argc == 2){

        G.setUp(argv[1]);
        
        while (!cin.eof()) {  // ??
            cout << "Query? ";
            string command;
            cin >> command;
            if (command.compare("@i") == 0 || command.compare("@insensitive") \
                == 0) {
                string str;
                cin >> str;
                G.printInsensitiveAnswer(str);
            } else if (command.compare("@q") == 0 || command.compare("@quit")\
                        == 0) {
                return 0;
            } else {
                G.printAnswer(command);
            }
        }

    } else {
        cerr << "Usage: gerp directory" << endl;
        cerr << "            where: directory is a valid directory" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;

}
