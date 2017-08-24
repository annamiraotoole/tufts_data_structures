// Comp 15, HW4, StringBST.cpp

// Annamira O'Toole 10/24/16

// implements StringBST class

#include "StringBST.h"
#include <iostream>
#include <stdexcept>

using namespace std;

StringBST::StringBST(){

    root = NULL;
}


StringBST::StringBST(string arr[], int size){

    root = new Node;
    root->left = NULL;
    root->right = NULL;
    root->data = arr[0];
    root->num = 1;
    for (int i = 1; i < size; i++) {
        add(arr[i]);
    }

}


StringBST::~StringBST(){

    while (!isEmpty()){
        removeMin();
    }

}


bool StringBST::isEmpty(){

    return root == NULL;

}

// wrapper function for private size function
int StringBST::size(){

    return size(root);

}

// private size function, recursive
int StringBST::size(Node *tree){

    if (tree == NULL){
        return 0;
    } else {
        return tree->num + size(tree->left) + size(tree->right);
    }
}

bool StringBST::isLeaf(Node *nodep){
    
    if (nodep == NULL)
        throw runtime_error("tried to isLeaf of NULL pointer");

    return (nodep->left == NULL) && (nodep->right == NULL);
}

void StringBST::clear(){

    while (!isEmpty()){
        removeMin();
    }

}

// wrapper function for recursive private print function
void StringBST::print(){

    print(root);

}


// prints contents of BST in order
// private, recursive
void StringBST::print(Node *tree){

    // traverse left
    if (tree != NULL){
        cout << "[";
        print(tree->left);
    }

    // process current node
    if (tree == NULL)
        cout << "[]";
    else
        cout << " " << tree->data << " " << tree->num << " ";

    // traverse right
    if (tree != NULL){
        print(tree->right);
        cout << "]";
    }

}

// wrapper function for recursive contains
bool StringBST::contains(string str){

    return contains(str, root);
}

// recursive     
bool StringBST::contains(string str, Node *tree){

    // if empty tree        
    if (tree == NULL)
        return false;
    // compare str input->data  
    int compare = str.compare(tree->data);
    // if equal return true  
    if (compare == 0)
        return true;
    // if <0 go left  
    if (compare < 0)
        return contains(str, tree->left);
    // if >0 go right
    else
        return contains(str, tree->right);

}

// recursive
struct StringBST::Node * StringBST::getNode(string str, struct Node *tree){

    // if passed the NULL pointer, return NULL pointer (function is useless)
    if (tree == NULL)
        return tree;

    // compare str input->data 
    int compare = str.compare(tree->data);

    // if input->data = str
    if (compare == 0)
        return tree;

    // if not NULL and not equal to str
    // if <0 go left                   
    if (compare < 0){
        if (tree->left == NULL)
            return tree;
        return getNode(str, tree->left);
    }
    // if >0 go right   
    else {
        if (tree->right == NULL)
            return tree;
        return getNode(str, tree->right);    
    }
} 


void StringBST::add(string str){

    // if empty tree make str into the root (no longer empty afterwards)
    if (isEmpty()){
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->data = str;
        root->num = 1;
        return;
    }

    Node *temp = getNode(str, root);
    int compare = str.compare(temp->data);

    // if in tree already, up number    
    if (compare == 0){
        temp->num = temp->num + 1;
    }
    // if not in tree already, add it as a new leaf (find spot in log(n) time)
    else if (compare < 0){
        temp->left = new Node;
        temp->left->left = NULL;
        temp->left->right = NULL;
        temp->left->data = str;
        temp->left->num = 1;
    } else {
        temp->right = new Node;
        temp->right->left = NULL;
        temp->right->right = NULL;
        temp->right->data = str;
        temp->right->num= 1;
    }

}

// wrapper function for private recursive function
bool StringBST::remove(string str){
    int initSize = size(root);
    root = remove(str, root);
    return size(root) == initSize - 1;
}

// recurvise?-- calls another function that uses this one, private
// returns version of tree with one instance of str removed
struct StringBST::Node * StringBST::remove(string str, Node *tree){

    if (tree == NULL){
        return tree;
    }

    int compare = str.compare(tree->data);  

    // if str is before current node
    if (compare < 0){
        tree->left = remove(str, tree->left);
        return tree;
    }

    // if str is after current node
    if (compare > 0){
        tree->right = remove(str, tree->right);
        return tree;
    }

    // else we know that current node's data is str

    // more than one instance of str
    if (tree->num > 1){
        tree->num = tree->num - 1;
        return tree;
    }

    // else only one instance of str
    
    // if leaf
    if ((tree->left == NULL) && (tree->right == NULL)){
        delete tree;     
        tree = NULL;   
        return tree;
    }

    // else if one child
    // if only left child
    if ((tree->left != NULL) && (tree->right == NULL)){
        Node *temp = tree->left;
        tree->left = NULL;
        delete tree;
        tree = temp;
        return tree;
    }
    // if only right child
    if ((tree->right != NULL) && (tree->left == NULL)){
        Node *temp = tree->right;
        tree->right = NULL;
        delete tree;       
        tree = temp;
        return tree;
    }

    // else has two children
    else {
        Node *up= getMin(tree->right);
        tree->data = up->data;
        tree->num = up->num;
        tree->right = removeNum(up->num, up->data, tree->right);
        tree->left = tree->left;        
        return tree;
    }
    
}

// TODO very inefficient 
struct StringBST::Node * StringBST::removeNum(int n, string str, Node *tree){
    for (int i = 0; i < n; i++){
        tree = remove(str, tree);
    }
    return tree;
}

struct StringBST::Node * StringBST::getMin(Node *tree){

    if (tree == NULL)
        throw runtime_error("getMin:empty_tree");

    // base case
    if (tree->left == NULL){
        return tree;
    }
    return getMin(tree->left);
}

string StringBST::getMin(){
    
    return getMin(root)->data;
}

struct StringBST::Node *  StringBST::getMax(Node *tree){

    if (tree ==NULL)
        throw runtime_error("getMax:empty_tree");

    // base case     
    if (tree->right == NULL){
        return tree;
    }
    return getMax(tree->right);
}

string StringBST::getMax(){

    return getMax(root)->data;
}

void StringBST::removeMin(){
    
    remove(getMin(root)->data);
}

void StringBST::removeMax(){

    remove(getMax(root)->data);
}
