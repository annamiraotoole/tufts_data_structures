// Orderqueue.cpp, Project 1b, Comp 15

// Annamira O'Toole 10/11/16

// implements the Orderqueue class

#include <iostream>
#include <stdexcept>

#include "Orderqueue.h"

using namespace std;

// UNDEFINED to prevent use, I do not need Orderqueues to be copyable
// assignment (=) overload
/* Orderqueue &Orderqueue::operator=(const Orderqueue &source){

}

// UNDEFINDED to prevent use, I do not need Ordersqueues to be copyable
// copy constructor
Orderqueue::Orderqueue(const Orderqueue &source){

}
*/

// initializes an empty linked list
Orderqueue::Orderqueue(){
    start = NULL;
    tail = NULL;
}

// initializes an empty linked list if the passed in array is empty
// else it initializes a linked list containing every element of the
// passed in array in order
Orderqueue::Orderqueue(Order arr[], int size){
    if (size == 0){
        start = NULL;
        tail = NULL;
        return;
    }    
    start = new OrderNode;
    start->anOrder = arr[0];
    start->prev = NULL;
    start->next = NULL;
    OrderNode *temp = start;
    for (int i = 1; i < size; i++){
        temp->next = new OrderNode;
        temp->next->anOrder = arr[i];
        temp->next->prev = temp;
        temp->next->next = NULL;
        temp = temp->next;
    }
    tail = temp;
}

Orderqueue::~Orderqueue(){

}

// returns true if the linked list is empty
bool Orderqueue::isEmpty()
{
    if (start == NULL)
        return true;
    else
        return false;
}

// traverses linked list and deletes each node from
// end to start of list
// sets tail to null (leaving an empty list, does not delete list)
void Orderqueue::clear(){
    while (start != NULL){
        struct OrderNode *temp = start->next;
        delete start;
        start =temp;
    }
    tail = NULL;
}

// returns number of elements in the linked list
int Orderqueue::size(){
    if (start == NULL)
        return 0;
    int count = 1;
    struct OrderNode *temp = start;
    while (temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// returns the value of the element at the end of the list
Order Orderqueue::top(){
    if(isEmpty())
        throw runtime_error("empty_queue");
    else{
        return start->anOrder;
    }
}

// removes element at the end of the list
// and returns its value
Order Orderqueue::pop(){
    if(isEmpty())
        throw runtime_error("empty_stack");
    else {
        OrderNode *temp = start->next;;
        Order val = start->anOrder;
        delete start;
        start = temp;
        if (start == NULL)
            tail = NULL;
        else
            start->prev = NULL;
        return val;
    }

}

// adds new node to the end of the list
// sets the new node's value to the value of
// the order  passed in
// if the list is empty, the node added is also 
// pointed to by start
void Orderqueue::push(Order d){
    if (isEmpty()){
        start = new struct OrderNode;
        start->anOrder = d;
        start->prev = NULL;
        start->next = NULL;
        tail = start;
    }else{
        tail->next = new struct OrderNode;
        tail->next->anOrder = d;
        tail->next->prev = tail;
        tail->next->next = NULL;
        tail = tail->next;
    }
}
