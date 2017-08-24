// Comp 15, Project 2 Final Submission, KeyValueMap.cpp

// Annamira O'Toole 11/23/16

#include "KeyValueMap.h"

#include <functional>
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <fstream>

using namespace std;

KeyValueMap::KeyValueMap() {
    
    count = 0; // since nothing is in map yet
    capacity = 1000; // starting capacity to avoid tons of expand() calls at
    // beginning of use
    
    table = new entryp[capacity];

    for (int i = 0; i < capacity; i++) {
        table[i] = NULL;
    }

}

void KeyValueMap::insert(word_t key, hit_t value) {

    if (count > capacity / 2) // expands if necessary
        expand();

    int index = findWord(key);
    entryp p = table[index];

    if (p == NULL) { // stores new key-value pair
        answerhits_t hits = vector<hit_t>();
        hits.push_back(value);
        p = new entry{word_hash(key), key, hits};
        table[index] = p;
        count++;
    } else { // if word is already in map, add hit to its current list of
             // hits
        if (value.file != p->value[p->value.size() - 1].file || \
            value.line != p->value[p->value.size() - 1].line) {
            p->value.push_back(value);
        }
    }
    
}


int KeyValueMap::size() {

    return count;

}

// not protected from trying to look into NULL pointer, assuming never called
// with old key (key already in hashmap)
answerhits_t KeyValueMap::getValue(word_t key) {

    entryp p = table[findWord(key)];
    return p->value;
}

bool KeyValueMap::contains(word_t key) {
    
    return table[findWord(key)] != NULL;
}

int KeyValueMap::findWord(word_t key) {

    size_t  hash = word_hash(key);
    int index = hash % capacity; // resizes hash to fit in index of array
    entryp p = table[index]; // stores original value at index
    
    while (p != NULL) { // until you find an empty spot, linear probe
        
        if (p->hash == hash && p->key == key)
            return index;
        else { // collision handling
            index = (index + 1) % capacity;        
        }
        p = table[index];
    }
    return index;
}

void KeyValueMap::expand() {

    // resets KeyValueMap data members to correct values, without leaking
    // the array memory
    entryp *newTable = new entryp[capacity * 2];  
    int oldCapacity = capacity;
    capacity = capacity * 2;
    entryp *oldTable = table;
    table = newTable;
    newTable = NULL;

    // copy data to new array
    for (int i = 0; i < capacity; i++) {
        table[i] = NULL;
    }
    
    for (int i = 0; i < oldCapacity; i++) {
        entryp p = oldTable[i];
        if (p != NULL) {
            table[findWord(p->key)] = p;
        }
    }
    
    // delete old array/data
    delete [] oldTable;
}
