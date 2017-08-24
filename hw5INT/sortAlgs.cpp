// Comp 15, HW5, sortAlgs.cpp

// Annamira O'Toole 10/30/16

#include "sortAlgs.h"

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>

using namespace std;

// functions used for running program  

void run(string alg, string mode); // interactive mode, reads from cin

void run(string alg, string mode, string filename); // automated mode, reads
// from cin
void sortVector(string alg, vector<int> *V); // calls correct sort algortithim
// based on whether -s1 -s2 or -s3 was input by user

string outputSave(vector<int> *V, string alg, string origin); // saves sorted
// vector to correctly named file

void outputPrint(vector<int> *V); // prints sorted vector to cout

vector<int> *readStream(istream &myStream); // used in this program by taking
// in cin (interactive) and istream (opened file) and reads integers into a 
// vector and returns a pointer to it


void run(string alg, string mode){
    
    vector<int> *V = readStream(cin);

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
    }
    delete V;
}

void run(string alg, string mode, string filename){

    vector<int> *V = new vector<int>();

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
    }
    delete V;
}

vector<int> *readStream(istream &myStream){

    vector<int> *list = new vector<int>();
    while (! myStream.eof()) {
        try {
            int next;
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

void sortVector(string alg, vector<int> *V){

    // decide which sort to call and sort V 
    if (alg == "-s1")
        insertionSort(V);
    else if (alg == "-s2")
        mergeSort(V);
    else if (alg == "-s3")
        shellSort(V);
    else
        throw "Please use a valid command for the algorithim";

}

string outputSave(vector<int> *V, string alg, string origin){

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

void outputPrint(vector<int> *V){

    int size = V->size();

    for (int i = 0; i < size; i++){
        cout << V->at(i) << endl;
    }

}

// function for insertion sort (sort 1)
void insertionSort(vector<int> *list) {

    int size = list->size();

    for (int i = 1; i < size; i++){

        int value = (*list)[i];

        for (int j = i - 1; j >= 0; j--){

            if (value > list->at(j)){
                (*list)[j + 1] = value;
                break;
            } else {
                int hold = list->at(j + 1);
                (*list)[j + 1] = list->at(j);
                (*list)[j] = hold;
            }

        }

    }

}

// functions for merge sort (sort 2)

vector<int> *copyOfRange(vector<int> *V, int start, int end){

    vector<int> *copy = new vector<int>();
    
    for (int i = start; i < end; i++){
        copy->push_back(V->at(i));
    }

    return copy;
}

void mergeSort(vector<int> *list){

    int size = list->size();

    if (size > 1) {

        vector<int> *left = copyOfRange(list, 0, size / 2);
        vector<int> *right = copyOfRange(list, size / 2, size);
        mergeSort(left);
        mergeSort(right);
        merge(list, left, right);
        delete left; delete right;
    }
}

void merge(vector<int> *list, vector<int> *left, vector<int> *right){
    
    int L = 0; int sizeL = left->size();
    int R = 0; int sizeR = right->size();

    while (R < sizeR && L < sizeL){
        
        if (left->at(L) < right->at(R)){
            (*list)[L + R] = left->at(L);
            L++;
        } else if (left->at(L) > right->at(R)){
            (*list)[L + R] = right->at(R);
            R++;
        } else {
            (*list)[L + R] = left->at(L);
            L++;
            (*list)[L + R] = right->at(R);
            R++;
        }
    }

    while (R < sizeR){
        (*list)[L + R] = right->at(R);
        R++;
    }

    while (L < sizeL){
        (*list)[L + R] = left->at(L);
        L++;
    }

}

// function for shell sort (sort 3)
void shellSort(vector<int> *list){
    int length = list->size();
    int gap = length;
    int i = 1; int temp = 1; int marker = 0;
    while (marker || (gap > 1)){
        
        marker = 0;
        gap = (gap + 1) / 2;
        for (i = 0; i < length - gap; i++){
            
            if (list->at(i + gap) < list->at(i)){
                temp = list->at(i + gap);
                (*list)[i + gap] = list->at(i);
                (*list)[i] = temp;
                marker = 1;
            }
        }
    }

}
