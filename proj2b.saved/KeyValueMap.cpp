// Comp 15, Project 2 Final Submission, KeyValueMap.cpp

// Annamira O'Toole 11/23/16

#include "KeyValueMap.h"

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>

using namespace std;

template <typename ElemType1, typename ElemType2>

void KeyValueMap<ElemType1,ElemType2>::insert(ElemType1 A, ElemType2 B) {

    theMap.insert(A, B);

}

    void KeyValueMap<ElemType1,ElemType2>::remove(ElemType1 A, ElemType2 B) {

    theMap.remove(A, B);

}

void KeyValueMap<ElemType1,ElemType2>::
