// CharLinkedList.h                                                                                                                                                 

// Annamira O'Toole 9/19/16                                                                                                                                       

#ifndef CHARLINKEDLIST_H
#define CHARLINKEDLIST_H

class CharLinkedList
{
 private:

    struct CharNode { char aChar; CharNode *next; CharNode *prev; };
    struct CharNode *start;
    struct CharNode *tail;

 public:

    CharLinkedList();
    CharLinkedList(char c);
    ~CharLinkedList();

    bool isEmpty();
    void clear();
    int size();
    void concatenate(CharLinkedList *p);
    char first();
    char last();
    char elementAt(int index);
    void print();
    void insertAtBack(char c);
    void insertAtFront(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);
    void removeFromFront();
    void removeFromBack();
    void removeFrom(int index);
    void replace(char c, int index);


};

#endif


