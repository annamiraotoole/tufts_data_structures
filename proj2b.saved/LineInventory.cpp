// Comp 15, Project 2 Final Submission, LineInventory.cpp  
 
// Annamira O'Toole 11/23/16                            

#include "LineInventory.h"

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

void LineInventory::processFile(ifstream &openFile) {
    
    /*  where openFile has to be of type istream NOT ifstream
       
    int lineNum = 1;
    while (! openFile.eof()) {
        try {
            string nextLine;
            openFile >> nextLine;
            if (!openFile.fail()){
                linesInFile.insert(lineNum, nextLine);
                lineNum++;
            }
        } catch (...) {
            cout << "ERROR" << endl;
        }
        
    }

    */

    // copied from stackoverflow.com/questions/7868936/read-file-line-by-line
    int lineNum = 1;
    string line;
    while (getline(openFile, line)) {
        
        istringstream iss(line);
        string nextLine;
        
        if (!(iss >> nextLine)) { break; } // error
        
        // CHANGE linesInFile.insert(lineNum, nextLine);
        linesInFile.insert(pair<int, string>(lineNum, nextLine));

        lineNum++;

    }

}


string LineInventory::getLineText(int lineNum) {
    
    // CHANGE return linesInFile.getValue(lineNum);
    return linesInFile.find(lineNum)->second;
    
}
