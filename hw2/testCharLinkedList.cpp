// testCharLinkedList.cpp

// Annamira O'Toole 9/19/16                                                                                                                                                         

#include <iostream>
#include <string>

#include "CharLinkedList.h"

using namespace std;

void testConstructers();
void testIsEmpty();
void testClear();
void testConcatenate();
void testFirst();
void testLast();
void testElementAt();
void testInsertAtBack();
void testInsertAtFront();
void testInsertAt();
void testInsertInOrder();
void testRemoveFromFront();
void testRemoveFromBack();
void testRemoveFrom();
void testReplace();

int main()
{
    testConstructers();
    return 0;
}

void testConstructers(){
    CharLinkedList a = CharLinkedList();
    CharLinkedList b = CharLinkedList('b');
    a.print();
    b.print();
}

void testIsEmpty(){
    CharLinkedList a = CharLinkedList();
    cout << a.isEmpty() << endl;
}

void testClear(){
    CharLinkedList b = CharLinkedList('b');
    b.clear();
    b.print();
}

void testConcatenate(){
    CharLinkedList a = CharLinkedList();
    CharLinkedList b = CharLinkedList('b');
    CharLinkedList c = CharLinkedList('c');
    b.concatenate(&c);
    b.print();
    c.concatenate(&a);
    c.print();
    a.concatenate(&c);
    a.print();
}

void testFirst(){
    CharLinkedList a = CharLinkedList();
    CharLinkedList b = CharLinkedList('b');
    cout << b.first() <<endl;
    cout << a.first() <<endl;
}

void testLast(){
    CharLinkedList a = CharLinkedList();
    CharLinkedList b = CharLinkedList('b');
    cout << b.first() <<endl;
    cout << a.first() <<endl;
}

void testElementAt(){
    CharLinkedList b = CharLinkedList('b');
    CharLinkedList c = CharLinkedList('c');
    b.concatenate(&c);
    cout << b.elementAt(1) << endl;
    cout << b.elementAt(2) << endl;
}

void testInsertAtBack(){
    CharLinkedList b = CharLinkedList('b');
    b.insertAtBack('B');
    b.print();
}

void testInsertAtFront(){
    CharLinkedList b = CharLinkedList('b');
    b.insertAtFront('B');
    b.print();
}

void testInsertAt(){
    CharLinkedList b = CharLinkedList('b');
    CharLinkedList c = CharLinkedList('c');
    b.concatenate(&c);
    b.insertAt('I', 1);
    b.print();
    b.concatenate(&c); b.concatenate(&c);
    b.clear(); 
b.concatenate(&c);
b.insertAt('I', 1);
b.print();
}

void testRemoveFromFront(){
CharLinkedList b = CharLinkedList('b');
CharLinkedList c = CharLinkedList('c');
b.concatenate(&c);
b.removeFromFront();
b.print();
}

void testRemoveFromBack(){
CharLinkedList b = CharLinkedList('b');
CharLinkedList c = CharLinkedList('c');
b.concatenate(&c);
b.removeFromBack();
b.print();
}

void testRemoveFrom(){
CharLinkedList b = CharLinkedList('b');
CharLinkedList c = CharLinkedList('c');
b.concatenate(&c);
b.concatenate(&b);
b.concatenate(&b);
b.print();
b.removeFrom(2);
b.print();
}

void testReplace(){
CharLinkedList b = CharLinkedList('b');
CharLinkedList c = CharLinkedList('c');
b.concatenate(&c);
b.concatenate(&b);
b.concatenate(&b);
b.print();
b.replace('a', 2);
b.print();
}

