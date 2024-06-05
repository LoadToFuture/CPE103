#ifndef _FASTLINKEDQUEUE_H_
#define _FASTLINKEDQUEUE_H_
#include "../ChainNode/ChainNode.h"
class FastLinkedQueue
{
private:
    int curSize;
    int maxSize;
    ChainNode *firstNode;
    ChainNode *lastNode;

public:
    FastLinkedQueue(int MaxSize);
    ~FastLinkedQueue();

    void enQueue(int e);
    void append(int e) { return enQueue(e); }
    int dequeue();
    int remove() { return dequeue(); }
    int front();
    int head() { return front(); }
    int rear();
    int back() { return rear(); }

    //! aux function
    int size();
    void display();
};

#endif //_FASTLINKEDQUEUE_H_