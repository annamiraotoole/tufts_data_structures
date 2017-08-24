// Comp 15, HW4, BSTTesting.cpp

// Annamira O'Toole

#include "StringBST.h"
#include <iostream>
using namespace std;

void testPrint();
void testAdd();
void testRemoveRoot();
void testRemoveLeaf();
void testRemoveOneChild();
void testRemoveTwoChildren();
void testRemoveTreeSizeOne();

int main()
{

    testRemoveTwoChildren();
    return 1;

}

void testPrint(){
    string arr[] = {"B", "A", "C"};
    StringBST T = StringBST(arr, 3);
    T.print();
}

void testAdd(){
    string arr[] = {"B", "A", "C"};
    StringBST T = StringBST(arr, 3);
   
    T.add("B");
    T.print();
    cout << endl;

}

void testRemoveRoot(){
    string arr[] = {"B", "A", "C"};
    StringBST T = StringBST(arr, 3);
    T.print();
    cout << endl;
    T.remove("B");
    T.print();
    cout << endl;
}

void testRemoveLeaf(){
    string arr[] = {"B", "A", "C"};
    StringBST T = StringBST(arr, 3);

    T.remove("A");
    T.print();
    cout << endl;
}

void testRemoveTwoChildren(){
    string arr[] = {"D", "B", "A", "C", "F", "E", "G"};
    StringBST T = StringBST(arr, 7);

    T.print();
    cout << endl;
    T.remove("B");
    T.print();
    cout << endl;
}

void testRemoveOneChild(){
    string arr[] = {"D", "B", "A", "C", "F", "E"};
    StringBST T = StringBST(arr, 6);

    T.remove("F");
    T.print();
    cout << endl;
}

void testRemoveTreeSizeOne(){
    string arr[] = {"A"};
    StringBST T = StringBST(arr, 1);
    T.remove("A");
    T.print();
}
