// DoubleStack.cpp, Homework 3, Comp 15

// Annamira O'Toole 9/23/16

// DoubleStack.cpp implements the functions declared in DoubleStack.h

#include <iostream>
#include <stdexcept>

#include "DoubleStack.h"

using namespace std;

// initializes an empty linked list
DoubleStack::DoubleStack(){
    start = NULL;
    tail = NULL;
}

// initializes an empty linked list if the passed in array is empty
// else it initializes a linked list containing every element of the
// passed in array in order
DoubleStack::DoubleStack(double arr[], int size){
    if (size == 0){
        start = NULL;
        tail = NULL;
    }    
    start = new DoubleNode;
    start->aDouble = arr[0];
    start->prev = NULL;
    DoubleNode *temp = start;
    for (int i = 1; i < size; i++){
        temp->next = new DoubleNode;
        temp->next->aDouble = arr[i];
        temp->next->prev = temp;
        temp->next->next = NULL;
        temp = temp->next;
    }
    tail = temp;
}

DoubleStack::~DoubleStack(){

}

// returns true if the linked list is empty
bool DoubleStack::isEmpty()
{
    if (start == NULL)
        return true;
    else
        return false;
}

// traverses linked list and deletes each node from
// end to start of list
// sets tail to null (leaving an empty list, does not delete list)
void DoubleStack::clear(){
    while (start != NULL){
        struct DoubleNode *temp = start->next;
        delete start;
        start =temp;
    }
    tail = NULL;
}

// returns number of elements in the linked list
int DoubleStack::size(){
    if (start == NULL)
        return 0;
    int count = 1;
    struct DoubleNode *temp = start;
    while (temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// returns the value of the element at the end of the list
double DoubleStack::top(){
    if(isEmpty())
        throw runtime_error("empty_stack");
    else{
        return tail->aDouble;
    }
}

// removes element at the end of the list
// and returns its value
double DoubleStack::pop(){
    if(isEmpty())
        throw runtime_error("empty_stack");
    else {
        DoubleNode *temp = tail->prev;;
        double last = tail->aDouble;
        delete tail;
        tail = temp;
        if (tail == NULL)
            start = NULL;
        else
            tail->next = NULL;
        return last;
    }

}

// adds new node to the end of the list
// sets the new node's value to the value of
// the double passed in
// if the list is empty, the node added is also 
// pointed to by start
void DoubleStack::push(double d){
    if (isEmpty()){
        start = new struct DoubleNode;
        start->aDouble = d;
        start->prev = NULL;
        start->next = NULL;
        tail = start;
    }else{
        tail->next = new struct DoubleNode;
        tail->next->aDouble = d;
        tail->next->prev = tail;
        tail->next->next = NULL;
        tail = tail->next;
    }
}
