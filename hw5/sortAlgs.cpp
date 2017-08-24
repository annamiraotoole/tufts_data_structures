// Comp 15, HW5, sortAlgs.cpp

// Annamira O'Toole 10/30/16

#include "sortAlgs.h"

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>

using namespace std;

// function for insertion sort (sort 1)
void insertionSort(vector<numb_t> *list) {

    int size = list->size();

    for (int i = 1; i < size; i++){

        numb_t value = (*list)[i];

        for (int j = i - 1; j >= 0; j--){

            if (value > list->at(j)){
                (*list)[j + 1] = value;
                break;
            } else {
                numb_t hold = list->at(j + 1);
                (*list)[j + 1] = list->at(j);
                (*list)[j] = hold;
            }

        }

    }

}

// functions for merge sort (sort 2)

vector<numb_t> *copyOfRange(vector<numb_t> *V, int start, int end){

    vector<numb_t> *copy = new vector<numb_t>();
    
    for (int i = start; i < end; i++){
        copy->push_back(V->at(i));
    }

    return copy;
}


void merge(vector<numb_t> *list, vector<numb_t> *left, vector<numb_t> *right){
    
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


void mergeSort(vector<numb_t> *list){

    int size = list->size();

    if (size > 1) {

        vector<numb_t> *left = copyOfRange(list, 0, size / 2);
        vector<numb_t> *right = copyOfRange(list, size / 2, size);
        mergeSort(left);
        mergeSort(right);
        merge(list, left, right);
        delete left; delete right;
    }
}

// function for shell sort (sort 3)
void shellSort(vector<numb_t> *list){
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
