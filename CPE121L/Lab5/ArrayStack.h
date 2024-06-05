#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_

#include "Arraylist.h"

#define DEFAULT_MAX_SIZE 5
class ArrayStack : public ArrayList // Inherit from ArrayList
{
private:

    int maxSize;

public: // add , remove , get , set , display , size , isEmpty , isFull
    ArrayStack(int maxSize = DEFAULT_MAX_SIZE);


    void setMaxSize(int MS); 
    void push(int e);
    int pop();
    int top();
    int peek() { return top();}

    bool isEmpty();
    bool isFull();

    void swapTop();

    void display();

};

#endif // _ARRAYSTACK_H_