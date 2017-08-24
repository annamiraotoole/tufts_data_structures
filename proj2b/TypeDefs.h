// Comp 15, Project 2 Final Submission, TypeDefs.h

// Annamira O'Toole 11/30/16

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include <vector>
#include <set>
#include <string>

using namespace std;

// types used for answers (in two data members of Gerp) to store word 
// occurence info 
typedef int filenum_t;

typedef int linenum_t;

typedef struct { filenum_t file; linenum_t line; } hit_t;

typedef vector<hit_t> answerhits_t;

// types used for storing individual lines found in each file in Gerp data
// member AllLines
typedef string filepath_t;

typedef string line_t;

typedef vector<line_t> lineindex_t;

// used to store words found in files, Gerp has maps from word_t to that word's
// occurences in the directory
typedef string word_t;

#endif 
