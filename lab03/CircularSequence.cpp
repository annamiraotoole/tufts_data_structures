/*
 *      CircularSequence.cpp 
 *      PartyPlaylist 
 *      Comp 15 Lab 3
 *
 *      2016-09-16 Created by Yennie Jun
 *      2016-09-20 Documentation added by Mark A. Sheldon, Tufts University
 */

#include <iostream>
#include <stdexcept>

#include "CircularSequence.h"


using namespace std;


/*
 * Return the index of the next element in the sequence.
 * Wraps around!
 */
int CircularSequence::nextIndex(int index)
{
        // TODO
    if (index == back)
        return front;
    if (index >= capacity)
        throw 0;
    else
        return index + 1;

}


/* Default Constructor */
CircularSequence::CircularSequence()
{
        init(INIT_CAPACITY);
}

/* 
 * Overloaded Constructor for a sequence with a hint for an initial
 * capacity. 
 */
CircularSequence::CircularSequence(int initialCapacity)
{
        init(initialCapacity);
}

/*
 * Initialize a new, empty sequence with an initial capacity.
 */
void CircularSequence::init(int initialCapacity)
{
        capacity      = initialCapacity;
        sequenceArray = new ElementType[capacity];
        currentSize   = 0;
        front         = 0;
        back          = 0;
}

/*
 * Destructor:  recycles the dynamically allocated array containing
 * the data.
 */
CircularSequence::~CircularSequence()
{
        delete [] sequenceArray;
}

/* 
 *  Add given element to the back of the list (at element
 *  currentSize). 
 *  Return true if element is successfully added.
 */
bool CircularSequence::addAtBack(ElementType elem) 
{
        if (currentSize == capacity) {
                expand();
        }
        sequenceArray[back] = elem;
        back                = nextIndex(back);
        currentSize++;

        return true;
}

/* 
 *  Add given element to the front of the list (at element 0)
 *  Return true if element is successfully added.
 */
bool CircularSequence::addAtFront(ElementType elem)
{
        // TODO
    if (currentSize == capacity)
        expand();
    if (front != 0){
        front = front - 1;
        sequenceArray[front] = elem;
        return true;
    }
    else {
        front = capacity - 1;
        sequenceArray[front] = elem;
        return true;
    }
}
                
/*
 * Remove the element at the back of the list (index currentSize - 1)
 * and return it.
 */
ElementType CircularSequence::removeFromBack() 
{
        // TODO
    sequenceArray[back] = NULL;
    if (back == 0)
        back = capacity - 1;
    else
        back = back - 1;
}
 
/*
 * Remove the element at the front of the list (element 0)
 * and return it.
 */
ElementType CircularSequence::removeFromFront()
{
         // TODO
    if (front == 0) {
        front = capacity - 1;
    }
    else {
        front = front + 1;
    }
}

/*
 * Expand the capacity of the array by a factor of 2.
 */
void CircularSequence::expand() 
{
        // TODO
    int newCapacity = capacity;
    ElementType *newArray [newCapacity * 2];
    newArray[0] = sequenceArray[front];
    for (int i = 0; i < currentSize - 1; i++){
        newArray[i + 1] = sequenceArray[nextIndex(i + front)];
    }
    delete sequenceArray;
    sequenceArray = *newArray;
    front = 0;
    back = currentSize - 1;
}

/*
 * Print the contents of the sequence, one element per line.
 */
void CircularSequence::printSequence() 
{
        int currIndex = front;
        for (int i = 0; i < currentSize; i++) {
                cout << sequenceArray[currIndex] << endl;
                currIndex = nextIndex(currIndex);
        }
}
