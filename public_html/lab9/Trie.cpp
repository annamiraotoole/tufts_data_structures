//
//  Trie.cpp
//  trie
//
//  Created by Chris Gregg on 3/29/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  [MAS 2015-10-17] Included string.h explicitly and put 
//                   using statement in.  Also cleaned up formatting.
//

#include <string>

#include "Trie.h"

using namespace std;

Trie::Trie()
{
        root = new Node();
}

Trie::~Trie()
{
        // Free memory
}

void Trie::addWord(string s)
{
        // TODO: Student writes this function
    Node *temp = root;
    for ( size_t i = 0; i < s.length(); i++){
        if (temp->findChild(s[i]) == NULL) {
            Node *add = new Node();
            add->setCharacter(s[i]);
            temp->appendChild(add);
        }
        temp = temp->findChild(s[i]);

    }
    temp->setWordMarker();

}


bool Trie::searchWord(string s)
{
        // TODO: Student writes this function
    Node *temp = root;
    while ( temp != NULL ) {
        for ( size_t i = 0; i < s.length(); i++) {
            if (temp->findChild(s[i]) != NULL) {
                if (i == s.length() - 1)
                    return true;
                temp = temp->findChild(s[i]);
            } else {
                return false;
            }
        }
    }

}

void Trie::printTrie()
{
        root->printNode(0);
}

void Trie::addPreNodes(vector<preNode> preNodes)
{
	root->addPreNodes(preNodes, 0, 1);
}
