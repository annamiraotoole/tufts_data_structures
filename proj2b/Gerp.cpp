// Comp 15, Project 2 Final Submission, Gerp.cpp

// Annamira O'Toole 11/23/16

#include "Gerp.h"

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include "KeyValueMap.h"

using namespace std;

Gerp::Gerp() {

}

Gerp::~Gerp() {

}

void Gerp::process_file(ifstream &openFile, filenum_t num) {

    lineindex_t index;
    index.push_back("NULL"); // so that index of first stored line is 1 not 0

    AllLines.resize(num + 1);
    AllLines[num] = index;

    // adds each line to respective lineindex_t in AllLines
    linenum_t lineNum = 1;
    line_t line;
    while (!openFile.eof()) {

        getline(openFile, line);

        AllLines[num].push_back(line);

        lineNum++;

    }

    
}

void Gerp::construct_AllLines() {

    // for every file/filepath, process that file and add it to AllLines
    int size = AllPaths.size();
    for (int i = 0; i < size; i++) {

        // open file and process
        // read in strings with ifstream code from hw3 
        ifstream file;
        file.open(AllPaths.at(i).c_str());
        if (not file.is_open()) {
            cerr << "Unable to read " << AllPaths.at(i) << endl;
        } else {
            process_file(file, i); // process open file
            file.close();
        }
    }
}

void Gerp::printAllLines() {

    int size = AllLines.size();

    // traverses AllLines and prints each line with number and filepath
    for (int i = 0; i < size; i++) {
        
        int size2 = AllLines.at(i).size();
        for (int j = 1; j < size2; j++) {
            cout << AllPaths.at(i) << ":" << j << ": ";
            cout << AllLines.at(i).at(j) << endl;
        }
    }
}

// uses pre order tree traversal 
void Gerp::recursive_construct_AllPaths(DirNode *folder, string str){
    
    // process node: adds path/strings to AllPaths for files in node
    int num = folder->numFiles();
    if (num > 0){

        for (int i = 0; i < num; i++){
            AllPaths.push_back(str + "/" + folder->getFile(i));
        }

    }
    
    // process other nodes within passed in "folder"
    int numOfSubDirs = folder->numSubDirs();
    
    if (numOfSubDirs > 0){
        
        for (int j = 0; j < numOfSubDirs; j++){
            
            DirNode* dir = folder->getSubDir(j);
            recursive_construct_AllPaths(dir, str + "/" + dir->getName());
            
        }
    }
}


void Gerp::construct_AllPaths(string directory) {

    FSTree tree = FSTree(directory);

    recursive_construct_AllPaths(tree.getRoot(), directory);

}

void Gerp::printAllPaths() {

    int size = AllPaths.size();

    for (int i = 0; i < size; i++) {
        cout << AllPaths.at(i) << endl;
    }

}

string Gerp::makeLowercase(string word) {

    int i = 0;
    string str = word;

    // traverses string, makes each char lowercase
    while (str[i]) {
        str[i] = tolower(str[i]); // cctype tolower built in c++ function
        i++; 
    }
    return str;
    
}

void Gerp::construct_answers() {

    int size = AllPaths.size();
    int size2;
    
    // for every file in AllLines
    for (int i = 0; i < size; i++) {
        
        // for every line in that file
        size2 = AllLines.at(i).size();
        for (int j = 1; j < size2; j++) {

            // for every word in that line

            line_t line = AllLines.at(i).at(j);
            istringstream iss(line);
            word_t nextWord;

            while (!iss.eof()) {

                if (!(iss >> nextWord)) { break; } // error       
            
                // add word to all answers map
                hit_t hit;
                hit.file = i;
                hit.line = j;
                AllAnswers.insert(nextWord, hit);
                
                // add to insensitive map
                word_t lower = makeLowercase(nextWord);
                InsensitiveAnswers.insert(lower, hit);
            }
        }
    }
}

// old test function from when my hashmap had not yet been implemented

/*
void Gerp::printAllAnswers() {

    for (std::map<word_t, answerhits_t>::iterator it=AllAnswers.begin(); \
         it!=AllAnswers.end(); ++it) {
        std::cout << it->first << " => ";
        int hitcount = it->second.size();
        for (int i = 0; i < hitcount; i++) {
            cout << "(" << it->second[i].file << ",";
            cout << it->second[i].line <<") ";
        }
        cout << '\n';
    }
    
}
*/

void Gerp::printAnswer(word_t word) {
    
    if (AllAnswers.contains(word) == 0)
        return;

    // retrieve all hits from case sensitive KeyValueMap    
    answerhits_t answers = AllAnswers.getValue(word);
    
    // traverse hits and print each one with line num and file path
    int hitcount = answers.size();
    for (int i = 0; i < hitcount; i++) {
        cout << AllPaths.at(answers[i].file) << ":";
        cout << answers[i].line << ": ";
        cout << AllLines.at(answers[i].file).at(answers[i].line);
        cout << endl;
    }
    
}

// old test function from when my hashmap had not yet been implemented  

/*
void Gerp::printInsensitiveAnswers() {
    
    for (std::map<word_t, answerhits_t>::iterator it=InsensitiveAnswers\
             .begin();
         it!=InsensitiveAnswers.end(); ++it) {
        std::cout << it->first << " => ";
        int hitcount = it->second.size();
        for (int i = 0; i < hitcount; i++) {
            cout << "(" << it->second[i].file << ",";
            cout << it->second[i].line <<") ";
        }
        cout << '\n';
    }
    
}
*/

void Gerp::printInsensitiveAnswer(word_t word) {
    
    word = makeLowercase(word);

    if (InsensitiveAnswers.contains(word) == 0)
        return;
    
    // retrieve hits from insensitive KeyValueMap 
    answerhits_t answers = InsensitiveAnswers.getValue(word);
    
    // traverse hits and print each one with line num and file path  
    int hitcount = answers.size();
    for (int i = 0; i < hitcount; i++) {
        cout << AllPaths.at(answers[i].file) << ":";
        cout << answers[i].line << ": ";
        cout << AllLines.at(answers[i].file).at(answers[i].line);
        cout << endl;
    }

}

void Gerp::setUp(string directory) {
    
    // construct AllPaths
    
    construct_AllPaths(directory);
    
    // construct AllLines
    
    construct_AllLines();

    // use AllLines to index words (make AllAnswers and InsensitiveAnswers)
    
    construct_answers();

}
