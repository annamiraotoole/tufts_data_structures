// Comp 15, Project 2 Final Submission, KeyValueMap.h

// Annamira O'Toole 11/21/16

#ifndef KEYVALUEMAP_H_
#define KEYVALUEMAP_H_

#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

// This class is a template for a mapping between keys, and values BUT
// is NOT a hash map, and instead takes advantage of the C++ set template's
// type comparison function.

template<typename ElemType1, typename ElemType2>

class KeyValueMap
{

 public:

    void insert(ElemType1 key, ElemType2 value);
    void remove(ElemType1 key);
    void contains(ElemType1 A, ElemType2 B);
    int size();
    ElemType2 getValue(ElemType1 key);

 private:

    map<ElemType1, ElemType2> theMap; 

};

template <typename ElemType1, typename ElemType2>

void KeyValueMap::KeyValueMap(ElemType1 key, ElemType2 value) {

    theMap = map<ElemType1, ElemType2>
        theMap.insert(pair<key, value>);

}

void KeyValueMap<ElemType1,ElemType2>::insert(ElemType1 key, ElemType2 value) {

    theMap.insert(pair<key, value>);

}

void KeyValueMap<ElemType1,ElemType2>::remove(ElemType1 key, ElemType2 value) {
    
    theMap.remove(key);

}

// void KeyValueMap<ElemType1,ElemType2>::


#endif
