#ifndef _LINKED_H
#define _LINKED_H
#include "../Node/Node.h"
#include "../../ChainNode/ChainNode.h"
class Linked
{
private:
    Node *head;
    ChainNode *firstNode;
 
public:
    // Constructor
    Linked() : head(nullptr) {}
    ~Linked();

    void add(string value);
    bool search(string value);
    void display();
};

#endif ///_LINKED_H