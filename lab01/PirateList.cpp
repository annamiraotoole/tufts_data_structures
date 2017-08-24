/*
 * Comp 15 Lab 1
 * Sequences
 *
 * Mark A. Sheldon and Erica Schwartz
 * based on prior versions by Chris Gregg
 *
 * Annamira O'Toole 9/9/16
 */

#include <iostream>
#include <string>

#include "PirateList.h"

using namespace std;


/* constructor */
PirateList::PirateList()
{
        pirateArray    = new Pirate[INIT_CAPACITY];
        pirateCapacity = INIT_CAPACITY;
        pirateCount    = 0;
}

/* destructor */
PirateList::~PirateList()
{
        for (int i = 0; i < pirateCount; i++) {
                pirateArray[i].friendList->deleteList();
                delete pirateArray[i].friendList;
                pirateArray[i].friendList = NULL;
        }
        delete [] pirateArray;
}

/* 
 * You will write this function.
 * If pirate with that memberID already exists, returns false
 * Otherwise, adds the pirate to the sequence and returns true
 */
bool PirateList::addPirate(int memberID, string memberName)
{
    // TODO
    //if  pirateArray contains memberID?
    //return false
    for(int i = 0; i < pirateCount; i++){
      if(pirateArray[i].memberID == memberID){
        return false;
      }
    }

    //if search finds nothing and doesn't return true
    //call initializePirate  and return true
    if (pirateCapacity == pirateCount){
      pirateCapacity = pirateCapacity + 1;  //increases pirateCapacity                                                                             
      Pirate *hold =  new Pirate[pirateCapacity];  // creates new and larger array                                                                 
      for (int i = 0; i < pirateCount; i++){  //copy first pirateCount element to new array                                                       
	hold[i] = pirateArray[i];
      }
      delete [] pirateArray; //deallocating contents of pirateArray                                                                                
      pirateArray = hold;  //sets intstance variable pirateArray to new and larger array                                                           
      hold = NULL;
    }

    initializePirate(pirateCount, memberID, memberName); //adds new Pirate                                                                         
    pirateCount = pirateCount + 1;
    return true;

}

/* Prints the values in the list in ascending order. */
/* This method is "const", which is a promise to the compiler
 * that it won't change the value of any private variables. 
 */
void PirateList::print() const
{
        cout << "There are " << pirateCount
             << " pirates in the system." << endl;

        for (int i = 0; i < pirateCount; i++) {
                cout << "Pirate: "         << pirateArray[i].name
                     << " with memberID: " << pirateArray[i].memberID
                     << " has friends ";
        
                // print pirate i's friend list 
                pirateArray[i].friendList->print();
                cout << endl;
        }
}

/* Add a new friend to memID's friend list.
 * Return false if there is no pirate with ID memID
 * Calls IntList's addFriend function
 */
bool PirateList::addFriend(int memID, int friendID)
{
        int pirateIdx = pirateIndex(memID);
        
        if (pirateIdx == -1)
                return false;

        return pirateArray[pirateIdx].friendList->addAtBack(friendID);
}

/**********************************************************************/
/*                      Private member functions                      */
/*                                                                    */
/* Feel free to add more.                                             */
/* Just remember to add them to the .h file, too.                     */
/**********************************************************************/

/*
 * friendList is a pointer to a dynamically allocated array.
 * If it is null the pirate has no friends.
 */
void PirateList::initializePirate(int    pirateCount,
                                  int    memberID,
                                  string memberName)
{
        pirateArray[pirateCount].memberID   = memberID;
        pirateArray[pirateCount].name       = memberName;
        pirateArray[pirateCount].friendList = new IntList();
}

/*
 * Return index of pirate with given member ID
 * Return -1 if the pirate is not found (i. e., memID is invalid)
 */
int PirateList::pirateIndex(int memID)
{
        int index = -1;
        for (int i = 0; i < pirateCount; i++) {
                if (pirateArray[i].memberID == memID) {
                        index = i;
                }
        }
        return index;
}