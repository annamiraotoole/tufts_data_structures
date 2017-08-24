//
//  Trie.h
//

#ifndef __trie__Trie__
#define __trie__Trie__

#include <string>
#include <vector>

#include "Node.h"

using std::string;
using std::vector;

class Trie {
public:
        Trie();
        ~Trie();

        void addWord(string s);
        bool searchWord(string s);
        void deleteWord(string s);
        void printTrie();
        void addPreNodes(vector<preNode> preNodes);

private:
        Node *root;
};

#endif /* defined(__trie__Trie__) */
