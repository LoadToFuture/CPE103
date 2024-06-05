#ifndef _HASHTABLECHK_H
#define _HASHTABLECHK_H

#include "Node/Node.h"
#include "Linked/Linked.h"
#include "../ChainNode/ChainNode.h"

class hashtablechk
{
private:
    Linked *L;
    int tableSize;

public:
    hashtablechk(int _tableSize) ;
    ~hashtablechk();
    
    void add(string value);
    void display();
};

#endif //_HASHTABLECHK_H