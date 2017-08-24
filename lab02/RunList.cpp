/*
 *  RunList.cpp
 *  PeanutOlympics
 *
 *  Lab created by Chris Gregg on 1/31/14.
 *  Interface altered by Mark A. Sheldon, Fall 2015
 *  to make node structure and associated operations private.
 *  Also did some cleaning up.
 * 
 *  Solution by Mark A. Sheldon, Tufts University, Fall 2015
 */

#include <iostream>
#include "assert.h"

#include "RunList.h"
#include "Runner.h"

using namespace std;

// Want to do this, but can't:  using RunList::RunnerNode;

RunList::RunList()
{
        front = nullptr;
}

RunList::~RunList()
{
        while (not isEmpty())
                deleteFront();
}

/* 
 * Clear out a node.  If there's a bug, a node that
 * looks like was supposed to have been deleted.
 */
void RunList::clearNodeData(RunList::RunnerNode *aNode)
{
        aNode->aRunner.setName("");
        aNode->aRunner.setTime(-1);
        aNode->next = nullptr;
}

/* 
 * Delete the first node in the list.
 * Note:  Assumes list is non-empty.
 */
void RunList::deleteFront()
{
        // TODO
        front = front -> next;

}

/*
 * empty list has a null front
 */
bool RunList::isEmpty()
{
        return front == nullptr;
}

RunList::RunnerNode *RunList::getFront()
{
        return front;
}

RunList::RunnerNode *RunList::getBack()
{
        RunList::RunnerNode *current = front;
        RunList::RunnerNode *prev = NULL;

        while (current != NULL) { // while not yet at end of list
                prev = current;
                current = current->next;
        }

        return prev;
}

Runner RunList::getFirst()
{
        return getFront()->aRunner;
}

Runner RunList::getLast()
{
        return getBack()->aRunner;
}

void RunList::insertIntoEmpty(RunnerNode *newNode)
{
        front = newNode;
}


/*
 * Allocate a new RunnerNode on the heap, initialize it, 
 * and return pointer to it.
 *
 * This doesn't really need to be a member function, but it would 
 * have to be a friend otherwise.  Feel free to read up on 'friends'
 * in C++.
 */
RunList::RunnerNode *RunList::newRunnerNode(string name, int time)
{
        RunnerNode *newNode = new RunList::RunnerNode();
        Runner      newRunner(name, time);
        newNode->aRunner    = newRunner;
        newNode->next       = nullptr;
        return newNode;
}

void RunList::insertInOrder(string runnerName, int runnerTime)
{
        RunnerNode *newNode  = newRunnerNode(runnerName, runnerTime);

        if (isEmpty()) 
                insertIntoEmpty(newNode);
        else {
                // find first runner with slower time than new runner
                RunnerNode *nodeAfter = front;

                while (nodeAfter != nullptr
                       and nodeAfter->aRunner.isFasterThan(newNode->aRunner))

                        nodeAfter = nodeAfter->next;

                if (nodeAfter != nullptr)                 // If slower runner,
                        insertBefore(nodeAfter, newNode); // put new one before
                else                                      // otherwise, new one
                        insertAfter(getBack(), newNode);  // is slowest, goes
        }                                                 // at back
                
}

/*
 *  Note:  Assume list is non-empty
 */
void RunList::insertBefore(RunList::RunnerNode *aNode,
                           RunList::RunnerNode *newNode)
{
        // TODO
    Runner temp = newNode->aRunner;
    newNode->aRunner = aNode->aRunner;
    aNode->aRunner = temp;
    newNode->next = aNode->next;
    aNode->next = newNode;                                                                

}

  /*
 *  Note:  Assume list is non-empty
 */
void RunList::insertAfter(RunList::RunnerNode *aNode,
                          RunList::RunnerNode *newNode)
{
        // TODO
    newNode->next = aNode->next;
    aNode->next = newNode;

}

void RunList::printList()
{
        RunList::RunnerNode *iterator = front;

        while (iterator != nullptr) {
                cout << iterator->aRunner.getName() << ": ";
                cout << iterator->aRunner.getTime() << "\n";

                iterator = iterator->next;
        }
}
