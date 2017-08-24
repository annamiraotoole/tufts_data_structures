/*
 * Comp 15 Lab 1
 * Sequences
 * Solution
 *
 * Mark A. Sheldon and Erica Schwartz
 * based on prior versions by Chris Gregg
 *
 * Annamira O'Toole 9/9/16
 */

#include <iostream>
#include <string>

#include "IntList.h"

using namespace std;


/* Constructor */
IntList::IntList()
{
        intArray     = new int[INIT_CAPACITY];
        intCapacity  = INIT_CAPACITY;
        intCount     = 0;
}

/* Destructor */
IntList::~IntList()
{
        deleteList();
}

/*
 * The function you will write
 */
bool IntList::addAtBack(int value)
{
    // TODO
    // makes new larger array, copies contents, deletes old array
    // updates storage index
    // adds new value

  if (intCapacity == intCount){
    intCapacity = intCapacity + 1;  //increases intCapacity
    int *hold =  new int[intCapacity];  // creates new and larger array
    for (int i = 0; i < intCount; i++){  //copy first intCount element to new array
      hold[i] = intArray[i];
    }
    delete [] intArray; //deallocating contents of intArray
    intArray = hold;  //sets intstance variable intArray to new and larger array
    hold = NULL;
  }
 
  intArray[intCount] = value; //adds new value
  intCount = intCount + 1;
  return true;
}

/* Prints the sequence separated by spaces */
void IntList::print() const
{
        for (int i = 0; i < intCount; i++) {
                cout << intArray[i] << " ";
        }
}

/* Returns the value at the given index */
bool IntList::getAtIndex(int index)
{
        return intArray[index];
}

/* Deletes the list and frees the memory it occupied */
void IntList::deleteList()
{
        if (intArray != NULL) {
                delete [] intArray;
                intArray = NULL;
        }
}

/**********************************************************************/
/*                      Private member functions                      */
/*                                                                    */
/* Feel free to add more.                                             */
/* Just remember to add them to the .h file, too.                     */
/**********************************************************************/