#include "LinkedList.h"
using namespace std;
#include <iostream>
LinkedList::LinkedList()
{ // constructor  // slide page
    //! p point to dummy (0,NULL)
    // ChainNode *p = NULL;
    // p = new ChainNode;
    //! // firstNode point to dummy
    // firstNode = p;
    //! firstNode to new dummy node
    firstNode = new ChainNode;
    //! set curSize to zero
    curSize = 0;
}
LinkedList::~LinkedList()
{ // destructor //slide
    // p  point to dummy
    ChainNode *p = firstNode;
    //! loop
    while (p != NULL)
    {
        // n point to next of p
        ChainNode *n = p->next;
        // delete
        delete p;
        // p point to same pos of n
        p = n;
    }
    //!
}
void LinkedList::add(int i, int e)
{
    // check full //!(memory)
    ChainNode *q = new ChainNode(e);
    if (q == NULL) //! memory full
    {
        cerr << "Error !! memory is fully !! \n";
        return;
    }
    // index (low) (upper)
    if (i < 0)
    {
        cerr << "Warning !! Lower bound \n";
        cout << "Message : " << i << " Change to 0\n";
        i = 0;
    }
    else if (i > curSize)
    {
        cerr << "Warning !! Upper bound \n";
        cout << "Message : " << i << " Change to  current size :" << curSize << endl;
        i = curSize;
    }
    // p point to dummy
    ChainNode *p = firstNode;
    // move p forword i times
    for (int j = 0; j < i; j++)
        p = p->next;
    // q point to new node (e. ?)
    q->next = p->next;
    // adjust link p q
    p->next = q;
    // increed cursize
    curSize++;
}
int LinkedList::size()
{
    return curSize;
}
 
 
void LinkedList::display()
{
    // L: [e1,e2,.......,en-1] , n : n
    cout << "L : [";
    //!  p point e0;    // firstNode = dummy
    ChainNode *p = firstNode->next;
    for (int i = 0; i < curSize; i++)
    {
        cout << i << ":" << p->element; // display ei
        if (i < curSize - 1)
            cout << ", ";
        p = p->next; //! move p to next node
    }
    cout << "] n: " << curSize << endl;
}
 

 
 

 

 
 
 
