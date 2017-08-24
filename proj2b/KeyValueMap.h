// Comp 15, Project 2 Final Submission, KeyValueMap.h

// Annamira O'Toole 11/21/16

#ifndef KEYVALUEMAP_H_
#define KEYVALUEMAP_H_

#include <functional>
#include <vector>
#include <string>
#include <set>
#include "TypeDefs.h"

using namespace std;

// my implementation of a Hash Map, with key type word_t and value type
// answerhits_t, both of which are defined in TypeDefs.h

class KeyValueMap
{

 public:

    KeyValueMap(); 
    void insert(word_t key, hit_t newValue);
    bool contains(word_t key);
    int size();
    answerhits_t getValue(word_t key); // returns value stored with key

 private:

    struct entry {size_t hash; word_t key; answerhits_t value;};
    typedef struct entry *entryp;

    int capacity;
    int count;

    entryp *table; // hashmap implemented with arrays, table stores
    // pointer to start of the array

    std::hash<word_t> word_hash; // defines KeyValueMap's version of c++'s
    // std::hash function
    
    int findWord(word_t key); // calls word_hash

    void expand(); // expands and re-hashes hashmap
};

#endif
