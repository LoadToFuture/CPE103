#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "../ChainNode/ChainNode.h" //re-use

class LinkedList
{
private:
    /* data */
    int curSize;
    ChainNode *firstNode;

public:
    LinkedList(/* args */);
    ~LinkedList();
    void add(int i, int e);     //! done
    int size();                 //! done
  
    //! Aux .function
    void display();
   
};

#endif //  _LINKEDLIST_H_