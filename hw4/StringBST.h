// Comp 15, HW4, StringBST.h

// Annamira O'Toole 10/24/16

// header file for StringBST

#ifndef STRINGBST_H
#define STRINGBST_H
#include <string>

using std::string;

class StringBST {

 public: 
    
    StringBST(); // default constructor
    StringBST(string arr[], int size); // creates a binary search tree with 
    //strings inserted in the  order in which they appear in the array
    ~StringBST(); // destroys the heap allocated data of current BST

    bool isEmpty();
    void clear(); // makes current BST into an empty one
    int size(); // returns size of BST (number of strings in tree)
    void print(); // prints BST in-order to cout
    void add(string str); // adds str to the BST
    bool remove(string str); // tries to remove str, if successful returns true
    // if unsuccessful returns false (doesn't throw exception)
    string getMin(); // returns left-most/smallest string in the BST, if 
    // empty throws runtime_error exception with the message getMin:empty_tree
    string getMax(); // returns right-most/largest string in the BST, if 
    // empty throws runtime_error exception with the message getMax:empty_tree
    void removeMin(); // removes left-most/smallest string and returns it
    void removeMax(); // removes right-most/largest string and returns it
    bool contains(string str); // returns true if in BST, false if not
    
 private:
    
    struct Node { Node *left; Node *right; string data; int num; };

    /*
    StringBST(const StringBST &source); // declared but undefined, I do not 
    //need StringBSTs to be copyable
    StringBST &operator= (const StringBST &source); // declared but undefined
    // I do not need StringBSTs to be copyable         
    */

    Node *root; // root of tree

    int size(Node *tree);
    bool isLeaf(Node *tree);
    struct Node * getNode(string str, struct Node *tree);
    bool contains(string str, Node *tree);
    void print(Node *tree);
    struct Node * remove(string str, struct Node *tree);
    struct Node * removeNum(int n, string str, struct Node *tree);
    struct Node * getMin(Node *tree);
    struct Node * getMax(Node *tree);
};

#endif
