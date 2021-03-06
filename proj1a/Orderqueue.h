// Orderqueue.h, Project 1a, Comp 15

// Annamira O'Toole 10/4/16

// My queues are implemented using doubly (might change it to singly) linked lists of OrderNodes. To construct a Queue, you can give
// the constructor an array of Orders.  I have not yet decided if I will use the provided Parser class in the Queue class to initialize
// the to-be-fetched Queue, or if Nozama will use the Parser class to create an array to feed into a Queue constructor.  Currently my
// .h files are written to do the latter.

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

    struct OrderNode { OrderNode *prev; Order anOrder; OrderNode *next; };
    struct OrderNode *start;
    struct OrderNode *tail;

};

#endif
