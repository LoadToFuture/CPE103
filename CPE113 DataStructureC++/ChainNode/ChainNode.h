#ifndef _CHAINNODE_H
#define _CHAINNODE_H
#include <iostream> //NULL

class ChainNode
{
public:
    /* data */
    int element;
 
    ChainNode *next;

public: // method
    // ChainNode();
    // ChainNode(int e);
    // ChainNode(int e , ChainNode *p)
    ChainNode(int e = 0, ChainNode *p = NULL);
    //~ChainNode();
};

#endif // _CHAINNODE_H
