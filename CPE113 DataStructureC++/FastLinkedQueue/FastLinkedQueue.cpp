#include "FastLinkedQueue.h"
#include <iostream>
using namespace std;
FastLinkedQueue::FastLinkedQueue(int MaxSize)
{

    //! first node to new dummy node
    firstNode = new ChainNode;
    this->maxSize = MaxSize;
    //! setcurSize to zero
    curSize = 0;
}

FastLinkedQueue::~FastLinkedQueue()
{
    ChainNode *p = firstNode;
    while (p != nullptr)
    {
        // n point to next of p
        ChainNode *n = p->next;
        // delete
        delete p;
        // p point to same pos of n
        p = n;
    }
}
void FastLinkedQueue::enQueue(int e)
{

    ChainNode *q = new ChainNode(e);
    if (curSize == maxSize)
    {

        cerr << "** Error !! : list is full **" << endl;
        return;
    }

    if (curSize == 0)
    {
        firstNode->next = q;
        lastNode = q;
    }
    else
    {
        lastNode->next = q;
        lastNode = q;
    }
    // Increase the current size
    curSize++;
}

int FastLinkedQueue::dequeue()
{
    // check empty

    if (curSize == 0)
    {
        cerr << "\n\n** Error !!: list is empty : **" << endl;
        return 0;
    }
    ChainNode *temp = firstNode->next;
    firstNode->next = temp->next;

    if (curSize == 1)
        lastNode = firstNode;
    curSize--;
    int data = temp->element;
    delete temp;
    return data;
}

int FastLinkedQueue::front()
{

    if (curSize == 0)
    {
        cerr << "\n\nError (front): !! Queue is Empty \n\n\n";
        return 0;
    }
    // p point to dummy to e0
    ChainNode *p = firstNode->next;

    return p->element;
}

int FastLinkedQueue::rear()
{
    //! create dummy

    if (curSize == 0)
    {
        cerr << "\n\nError (rear): !! Queue is Empty \n\n\n\n";
        return 0;
    }
    return lastNode->element;
}

int FastLinkedQueue::size()
{
    return curSize;
}

void FastLinkedQueue::display()
{
    cout << "+---------------------------------------------------------+\n";
    cout << "L ";
    ChainNode *p = firstNode->next;
    if (curSize == 0)
    {
        for (int i = 0; i < maxSize; i++)
            cout << " [" << i << ": ] ";
        cout << "\n+---------------------------------------------------------+\n";
        return;
    }
    for (int i = 0; i < maxSize; i++)
    {
        if (i < curSize)
        {                                                   //! ถ้าไม่ใส่จะขึ้น เกิน แล้ว Error Core
            cout << " [" << i << ":" << p->element << " ]"; // แสดงข้อมูลที่ตำแหน่งปัจจุบัน
            p = p->next;                                    // เลื่อนไปยัง Node ถัดไป
        }
        else
            cout << " [" << i << ": ] "; // แสดงช่องว่างถ้าขนาดปัจจุบันน้อยกว่า maxSize
    }
    cout << "\n+---------------------------------------------------------+\n";
    int index = -2;
    ChainNode *first = firstNode;
    while (first != nullptr)
    {
        first = first->next;
        index++;
    }
    cout << "FirstNode: " << 0;               //<< " Element: " << first->element  ;
    cout << "  LastNode : " << index << endl; //<< " Element: " << first->element  ;
}
