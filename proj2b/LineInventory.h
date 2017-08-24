// Comp 15, Project 2 Final Submission, LineInventory.h
              
// Annamira O'Toole 11/21/16                                  

#ifndef LINEINVENTORY_H_
#define LINEINVENTORY_H_

#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>

//#include "KeyValueMap.h"

using namespace std;

// maps line numbers to line text

class LineInventory
{

 public:

    void processFile(ifstream &openFile); // opens file and adds line num--line
    // text pair to "linesInFile"
    
    string getLineText(int lineNum);

 private:

    //KeyValueMap linesInFile = KeyValueMap(int, string);

    map<int, string> linesInFile;

};

#endif
