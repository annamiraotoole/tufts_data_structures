// Comp 15, HW5 Sorting, sortAlgs.h

// Annamira O'Toole 10/31/16

#ifndef SORTALGS_H
#define SORTALGS_H

#include<vector>
#include<string>

using namespace std;

// function for insertion sort

void insertionSort(vector<int> *list);

// functions for merge sort

void mergeSort(vector<int> *list);

void merge(vector<int> *list, vector<int> *left, vector<int> *right);

// function for shell sort

void shellSort(vector<int> *list);

// functions used for running program

void run(string alg, string mode);

void run(string alg, string mode, string filename);

void sortVector(string alg, vector<int> *V);

string outputSave(vector<int> *V, string alg, string origin);

void outputPrint(vector<int> *V);

vector<int> *readStream(istream &myStream);

#endif
