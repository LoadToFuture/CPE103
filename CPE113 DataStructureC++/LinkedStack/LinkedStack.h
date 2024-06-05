#ifndef _LINKEDSTACK_H
#define _LINKDESTACK_H
#include "../LinkedList/LinkedList.h"
#include "../ChainNode/ChainNode.h"
class LinkedStack : public LinkedList
{
private:
    int maxSize;
    ChainNode *firstNode;

public:
    LinkedStack(int MaxSize);

    void UpdateMaxSize(int newMaxSize);
    void push(int e);            //! done
    int pop();                   //! done
    int top();                   //! done
    int peek() { return top(); } //! done
    bool isEmpty();              //! done
    bool isFull();               //! done
    void StackDisplay();         //! done
    void swap01();
    void swap02();
};

#endif //_LINKDESTACK_H