// DoubleStack.h, Homework 3, Comp 15

// Annamira O'Toole 9/23/16

// header file for RPNCalc's stack which is implemented using doublly linked lists

#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H

class DoubleStack {

 public:

    DoubleStack();
    DoubleStack(double input[], int size);
    ~DoubleStack();

    bool isEmpty();
    void clear();
    int size();
    double top();
    double pop();
    void push(double d);

 private:

    struct DoubleNode { double aDouble; DoubleNode *next; DoubleNode *prev; };
    struct DoubleNode *start;
    struct DoubleNode *tail;

};

#endif
