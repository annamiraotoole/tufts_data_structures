// testCharSequence.cpp

// Annamira O'Toole 9/13/16

#include <iostream>
#include <string>

#include "CharSequence.h"

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
void testRemoveFromFront();
void testRemoveFromBack();
void testRemoveFrom();
void testReplace();

int main()
{
    cout << "No tests being called in main function" << endl;
    return 0;
}

void testConstructers(){
    CharSequence a = CharSequence();
    CharSequence b = CharSequence('b');
    a.print();
    b.print(); 
}

void testIsEmpty(){
    CharSequence a = CharSequence();
    cout << a.isEmpty() << endl;
}

void testClear(){
    CharSequence b = CharSequence('b');
    b.clear();
    b.print();
}

void testConcatenate(){
    CharSequence a = CharSequence();
    CharSequence b = CharSequence('b');  
    CharSequence c = CharSequence('c');
    b.concatenate(&c);
    b.print();
    c.concatenate(&a);
    c.print();
    a.concatenate(&c);
    a.print();
}

void testFirst(){
    CharSequence a = CharSequence();
    CharSequence b = CharSequence('b');
    cout << b.first() <<endl;
    cout << a.first() <<endl;
}

void testLast(){
    CharSequence a = CharSequence();
    CharSequence b = CharSequence('b');
    cout << b.first() <<endl;
    cout << a.first() <<endl;
}

void testElementAt(){
    CharSequence b = CharSequence('b');
    CharSequence c = CharSequence('c');
    b.concatenate(&c);
    cout << b.elementAt(1) << endl;
    cout << b.elementAt(2) << endl;
}

void testInsertAtBack(){
    CharSequence b = CharSequence('b');
    b.insertAtBack('B');
    b.print();
}

void testInsertAtFront(){
    CharSequence b = CharSequence('b');
    b.insertAtFront('B');
    b.print();
}       

void testInsertAt(){
    CharSequence b = CharSequence('b');
    CharSequence c = CharSequence('c');
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
    CharSequence b = CharSequence('b');
    CharSequence c = CharSequence('c');
    b.concatenate(&c);
    b.removeFromFront();
    b.print();
}

void testRemoveFromBack(){
    CharSequence b = CharSequence('b');
    CharSequence c = CharSequence('c');
    b.concatenate(&c);
    b.removeFromBack();
    b.print();
}

void testRemoveFrom(){
    CharSequence b = CharSequence('b');
    CharSequence c = CharSequence('c');
    b.concatenate(&c);
    b.concatenate(&b);
    b.concatenate(&b);
    b.print();
    b.removeFrom(2);
    b.print();
}

void testReplace(){
    CharSequence b = CharSequence('b');
    CharSequence c = CharSequence('c');
    b.concatenate(&c);
    b.concatenate(&b);
    b.concatenate(&b);
    b.print();
    b.replace('a', 2);
    b.print();
}
