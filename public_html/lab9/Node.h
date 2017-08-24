//
//  Node.h
//  trie lab
//
//  Created by Chris Gregg on 3/29/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#ifndef __trie__Node__
#define __trie__Node__

#include <vector>

using namespace std;

/*
 * This node structure is public, because it's used to interact with
 * the cgiBackend code to support the web interface.
 */
struct preNode {
	int  level;
	char c;
	bool wordMarker;
};

class Node {
public:
        Node ();
        ~Node() {}

        char   content()            { return theCharacter; }
        void   setCharacter(char c) { theCharacter = c; }
        bool   getWordMarker()      { return wordMarker; }
        void   setWordMarker()      { wordMarker = true; }
        Node  *findChild(char c);
        void   appendChild(Node *child);
        void   printNode(int level);
        size_t addPreNodes(vector <preNode> preNodes, int level, size_t index);
        
private:
	static const int ALPHABET_LENGTH = 26;

        char  theCharacter;
        bool  wordMarker;
        Node *children[ALPHABET_LENGTH];
};


#endif /* defined(__trie__Node__) */
