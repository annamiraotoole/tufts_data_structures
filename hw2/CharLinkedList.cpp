// CharLinkedList.cpp                                                                                                                                                                 
// Annamira O'Toole 9/19/16                                                                                                                                                         

#include <iostream>
#include <string>

#include "CharLinkedList.h"

using namespace std;

CharLinkedList::CharLinkedList()
{
    start = NULL;
    tail = NULL;   // TODO
}

CharLinkedList::CharLinkedList(char c)
{
    start = new struct CharNode;
    start->aChar = c; // TODO
    start->prev = NULL;
    start->next = NULL;
    tail = start;
}

// TODO need to deallocate memory
CharLinkedList::~CharLinkedList(){
    while (start != NULL){
        struct CharNode *temp = start->next;
        delete start;
        start = temp;
    }
    tail = NULL;
}

bool CharLinkedList::isEmpty()
{
    if (start == NULL)
        return true;
    else
        return false;
}

void CharLinkedList::clear(){
    while (start != NULL){
        struct CharNode *temp = start->next;
        delete start;
        start =temp;
    }
    tail = NULL;
}

int CharLinkedList::size(){
    if (start == NULL)
        return 0;
    int count = 1;
    struct CharNode *temp = start;
    while (temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void CharLinkedList::concatenate(CharLinkedList *p){
    int initInputListSize = p->size();
    struct CharNode *temp = p->start;
    for (int i = 0; i < initInputListSize; i++){
        insertAtBack(temp->aChar);
        temp = temp->next;
    }
    
}

char CharLinkedList::first(){
    if(isEmpty())
        throw 0;
    else
        return start->aChar;
}

char CharLinkedList::last(){
    if(isEmpty())
        throw 0;
    else{
        return tail->aChar;
    } 
}

char CharLinkedList::elementAt(int index){
    if (index >= size()) // TODO >= OR > ??????
        throw 0;
    else{  
        CharNode *temp = start;
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->aChar;
    }
}

void CharLinkedList::print(){                                                                                                                          
    cout << "[CharLinkedList of size " << size() << " <<";
    CharNode *temp = start;
    while (temp != NULL) {
        cout << temp->aChar;
        temp = temp->next;
    }
    cout << ">>]";
}

void CharLinkedList::insertAtBack(char c){
    if (isEmpty()){
        start = new struct CharNode;
        start->aChar = c; // TODO                
        start->prev = NULL;
        start->next = NULL;
        tail = start;
    }else{
        tail->next = new struct CharNode;
        tail->next->aChar = c; 
        tail->next->prev = tail; 
        tail->next->next = NULL;
        tail = tail->next;
    }
}

void CharLinkedList::insertAtFront(char c){                                                          
    if (isEmpty()){
        start = new struct CharNode;
        start->aChar = c; // TODO                                                                                                                 
        start->prev = NULL;
        start->next = NULL;
        tail = start;
    }else{
        CharNode *temp = start;
        start = new struct CharNode;
        start->aChar = c;
        start->next = temp;
        start->prev = NULL;
        temp->prev = start;
    }
}

void CharLinkedList::insertAt(char c, int index){
    if (index > size())
        throw 0;
    if (index == 0){
        insertAtFront(c);
        return;
    }
    if (index == size()){
        insertAtBack(c);
        return;
    }
    CharNode *before = start;
    for (int i = 0; i < index - 1; i++){
        before = before->next;
    }
    CharNode *after = before->next;
    CharNode *insert = new struct CharNode;
    insert->next = before->next;
    insert->aChar = c;
    before->next = insert;
    insert->prev = before;
    after->prev = insert;
}

void CharLinkedList::insertInOrder(char c){
    int index = 0;
    CharNode *temp = start;
    while (temp != NULL && c > temp->aChar){
        temp = temp->next;
        index++;
    }
    insertAt(c, index);
}

void CharLinkedList::removeFromFront(){
    if(isEmpty())
        throw 0;
    else {
        CharNode *temp = start->next;
        delete start;
        start = temp;
        if (start == NULL)
            tail = NULL;
        else
            start->prev = NULL;
    }
}

 void CharLinkedList::removeFromBack(){
     if(isEmpty())
         throw 0;
     else {
         CharNode *temp = tail->prev;;
         delete tail;
         tail = temp;
         if (tail == NULL)
             start = NULL;
         else
             tail->next = NULL;

     }
 }

 void CharLinkedList::removeFrom(int index){                                                                                                                                                    
     if (index >= size())
         throw 0;
     if (index == 0)
         removeFromFront();
     if (index == size() - 1)
         removeFromBack();
     else {
         CharNode *before = start;
         for (int i = 0; i < index - 1; i++){
             before = before->next;
         }
         CharNode *temp = before->next;
         CharNode *after = before->next->next;
         before->next = after;
         after->prev = before;
         delete temp;
     }
 }

 void CharLinkedList::replace(char c, int index){
     if (index >= size())
         throw 0;
     else {
         CharNode *temp = start;
         for (int i = 0; i < index; i++){
             temp = temp->next;
         }
         temp->aChar = c;
     }
 }

