// Comp 15, HW5, sorter.cpp

// Annamira O'Toole 10/30/16

#include "sortAlgs.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>


using namespace std;

void run(string alg, string mode); // interactive mode, reads from cin 

void run(string alg, string mode, string filename); // automated mode, reads 
// from cin

// functions used for running program  

void sortVector(string alg, vector<numb_t> *V); // calls correct sort 
// algortithim based on whether -s1 -s2 or -s3 was input by user

string outputSave(vector<numb_t> *V, string alg, string origin); // saves 
// sorted vector to correctly named file

void outputPrint(vector<numb_t> *V); // prints sorted vector to cout

vector<numb_t> *readStream(istream &myStream); // used in this program by 
// taking in cin (interactive) and istream (opened file) and reads integers
// into a vector and returns a pointer to it


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


void run(string alg, string mode){
    
    vector<numb_t> *V = readStream(cin);

    // sort list
    sortVector(alg, V);

    // decide which output mode and output list
    if (mode == "--print"){
        outputPrint(V);
    }
    else if (mode == "--save"){
        outputSave(V, alg, "cin");
    }
    else {
        cerr << "Usage: sorter sortAlg outputMode [fileName]" << endl;
        cerr << "where: sortAlg is −s1, −s2, or −s3" << endl;
        cerr << "and outputMode is −−print or −−save" << endl;
        exit(1);
    }
    delete V;
}


void run(string alg, string mode, string filename){

    vector<numb_t> *V = new vector<numb_t>();

    // read in strings with ifstream code from hw3                             
    std::ifstream input;
    input.open(filename.c_str());
    if (not input.is_open()) {
        cerr << "Unable to read " << filename << endl; // different message?
    } else {
        V = readStream(input);
        input.close();
        // sort list 
        sortVector(alg, V);
    }

    // decide which output mode and output list  
    if (mode == "--print") {
        outputPrint(V);
    } else if (mode == "--save") {
        outputSave(V, alg, filename);
    } else {
        cerr << "Usage: sorter sortAlg outputMode [fileName]" << endl;
        cerr << "where: sortAlg is −s1, −s2, or −s3" << endl;
        cerr << "and outputMode is −−print or −−save" << endl;   
        exit(1);
    }
    delete V;
}


vector<numb_t> *readStream(istream &myStream){

    vector<numb_t> *list = new vector<numb_t>();
    while (! myStream.eof()) {
        try {
            numb_t next;
            myStream >> next;
            if (!myStream.fail()){
                list->push_back(next);
            }
        } catch (...) {
            cout << "ERROR" << endl;
        }
    }
    return list;

}


void sortVector(string alg, vector<numb_t> *V){

    // decide which sort to call and sort V 
    if (alg == "-s1")
        insertionSort(V);
    else if (alg == "-s2")
        mergeSort(V);
    else if (alg == "-s3")
        shellSort(V);
    else {
        cerr << "Usage: sorter sortAlg outputMode [fileName]" << endl;
        cerr << "where: sortAlg is −s1, −s2, or −s3" << endl;
        cerr << "and outputMode is −−print or −−save" << endl;
        exit(1);
    }

}


string outputSave(vector<numb_t> *V, string alg, string origin){

    int size = V->size();
    string sizeString = to_string(size);

    string algNumString;
    if (alg.compare("-s1") == 0)
        algNumString = "1";
    else if (alg.compare("-s2") == 0)
        algNumString = "2";
    else if (alg.compare("-s3") == 0)
        algNumString = "3";
    else {
        cerr << "Usage: sorter sortAlg outputMode [fileName]" << endl;
        cerr << "where: sortAlg is −s1, −s2, or −s3" << endl;
        cerr << "and outputMode is −−print or −−save" << endl;
        exit(1);
    }
    string file = "";

    file = file + origin + "_";
    file = file + algNumString + "_";
    file = file + sizeString + "_sorted.txt";

    std::ofstream output;
    output.open(file.c_str());
    if (not output.is_open()) {
        cerr << "Unable to write " << file << endl;    
    }

    for(int i = 0; i < size; i++){
        output << V->at(i) << endl;
    }

    output.close();

    return file;

}

void outputPrint(vector<numb_t> *V){

    int size = V->size();

    for (int i = 0; i < size; i++){
        cout << V->at(i) << endl;
    }

}
