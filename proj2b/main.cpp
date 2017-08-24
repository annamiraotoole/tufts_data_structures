// Comp 15, Project 2 Final Submission, main.cpp

// Annamira O'Toole 11/30/16

#include "Gerp.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
    Gerp G;

    if (argc == 2){

        // index directory
        G.setUp(argv[1]);
        
        // ask for and answer queries
        while (!cin.eof()) {  // ??
            cout << "Query? "; // ask
            string command;
            cin >> command; // store command
            
            // get case insensitive answer
            if (command.compare("@i") == 0 || command.compare("@insensitive") \
                == 0) {
                string str;
                cin >> str;
                G.printInsensitiveAnswer(str);
            } 
            // quit
            else if (command.compare("@q") == 0 || command.compare("@quit") \
                     == 0) {
                break;
            }
            // get case sensitive answer 
            else {
                G.printAnswer(command);
            }
        }
        cout << endl;
        cout << "Goodbye! Thank you and have a nice day." << endl;

    } else {
        cerr << "Usage: gerp directory" << endl;
        cerr << "            where: directory is a valid directory" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;

}
