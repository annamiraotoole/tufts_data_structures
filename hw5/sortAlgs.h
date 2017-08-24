// Comp 15, HW5 Sorting, sortAlgs.h

// Annamira O'Toole 10/31/16

#ifndef SORTALGS_H
#define SORTALGS_H

#include<vector>
#include<string>

using namespace std;


// used to comply with the 12 digit number handling mentioned in spec
typedef long int numb_t;

// used to comply with the part of the spec that says to use vector<int>,
// which contradicts the requirement to be able to handle 12 digits
// typedef int numb_t;

// function for insertion sort

void insertionSort(vector<numb_t> *list);

// function for merge sort

void mergeSort(vector<numb_t> *list);

// function for shell sort

void shellSort(vector<numb_t> *list);

#endif
