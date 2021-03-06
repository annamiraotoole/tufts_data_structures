// Orderqueue.h, Project 1b, Comp 15

// Annamira O'Toole 10/10/16

// My queues are implemented using doubly linked lists of OrderNodes. To 
// construct a Queue, you can give
// the constructor an array of Orders and a size.  Note: using method names 
// push and pop NOT dequeue and inqueue.

#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H
#include "Order.h"

class Orderqueue {

 public:

    Orderqueue();
    Orderqueue(Order input[], int size);
    ~Orderqueue();

    bool isEmpty();
    void clear();
    int size();
    Order top();
    Order pop();
    void push(Order d);

 private:

    Orderqueue(const Orderqueue &source); // declared but undefined, I do not 
    //need Orderqueues to be copyable
    Orderqueue &operator= (const Orderqueue &source); // declared but undefined
    // I do not need Orderqueues to be copyable

    struct OrderNode { OrderNode *prev; Order anOrder; OrderNode *next; };
    struct OrderNode *start;
    struct OrderNode *tail;

};

#endif
