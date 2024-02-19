#include "ChainNode.h"
#include<iostream>
using namespace std;

ChainNode::ChainNode(int e, ChainNode *p)
{
    element = e; // element -> e
    next = p;  //next -> p

    // cout << "this : ("<< this << "): ( e: " 
    //      << element << ", n: " << next <<" ) "<< endl;
}
