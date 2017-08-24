// Comp 15, Project 2 Final Submission, TypeDefs.h

// Annamira O'Toole 11/30/16

#include <vector>
#include <set>
#include <string>

using namespace std;

typedef int filenum_t;

typedef int linenum_t;

typedef string filepath_t;

typedef string line_t;

typedef vector<line_t> lineindex_t;

typedef struct { filenum_t file; linenum_t line; } hit_t;

typedef vector<hit_t> answerhits_t;

typedef string word_t;
