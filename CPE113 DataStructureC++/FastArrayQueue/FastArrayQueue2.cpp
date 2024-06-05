#include "FastArrayQueue.h"
#include <iostream>
using namespace std;
void FastArrayQueue::clear()
{
    in = 0;
    out = 0;
    curSize = 0;
}
FastArrayQueue::FastArrayQueue(int maxSize)
{
    this->maxSize = maxSize; // save value maxsize
    curSize = 0;
    in = 0;
    out = 0;
    L = new int[this->maxSize];
}
FastArrayQueue::~FastArrayQueue()
{
    delete[] L;
}
void FastArrayQueue::enQueue(int e)
{
    // check full
    if (curSize == maxSize)
    {
        cerr << "\n\nError:!! Queue is full!!\n\n\n";
        return;
    }
    // add e at in index
    L[in] = e;
    // forward in by one
    in = (in + 1) % maxSize;
    // increment curSize by 1
    curSize++;
}

int FastArrayQueue::deQueueFront()
{
    if (curSize == 0)
    {
        // ถ้า Queue ว่างเราไม่สามารถ Dequeue ได้
        cout << "Queue is empty. Unable to Dequeue.\n";
        return -1; // ส่งค่า -1 แสดงถึงการล้มเหลวในการ Dequeue
    }
    int r = L[out];
    L[out] = 0;
    out = (out + 1) % maxSize;
    curSize--;
    return r;
}
int FastArrayQueue::deQueueRear()
{
    if (curSize == 0)
    {
        // ถ้า Queue ว่างเราไม่สามารถ Dequeue ได้
        cout << "Queue is empty. Unable to Dequeue.\n";
        return -1; // ส่งค่า -1 แสดงถึงการล้มเหลวในการ Dequeue
    }
    int last_index = (out + curSize - 1) % maxSize;
    int r = L[last_index];
    L[last_index] = 0;
    curSize--;
    return r;
}
int FastArrayQueue::front()
{
    if (curSize == 0)
    {
        cerr << "\n\nError (front): !! Queue is Empty \n\n\n";
        return 0;
    }
    // return element at out index
    return L[out];
}
int FastArrayQueue::rear()
{
    if (curSize == 0)
    {
        cerr << "\n\nError (rear): !! Queue is Empty \n\n\n\n";
        return 0;
    }
    // return element previos of in
    return L[(in - 1 + maxSize) % maxSize];
}
bool FastArrayQueue::isEmpty()
{
    if (curSize > 0)
    {
        return true;
    }
    return false;
}
int FastArrayQueue::size()
{
    return curSize;
}

void FastArrayQueue::display()
{
    // L : {1,2,3,4,5}  size : cur_size / max_size
    cout << "+---------------------------------------------------------+\n";
    cout << " Array is : ";
    if (curSize == 0)
    {
        for (int i = 0; i < maxSize; i++)
            cout << " [" << i << ": ] ";
        cout << endl;
        cout << "            ";
        for (int i = 0; i < maxSize; i++)
        {
            cout << "  "
                 << "in"
                 << ":";
            if (i == in)
            {
                cout << "\033[1;32m  ";
                cout << i << "";
                cout << "\033[0m";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
        cout << "            ";
        for (int i = 0; i < maxSize; i++)
        {
            cout << " "
                 << "out"
                 << ":";
            if (i == out)
            {
                cout << "\033[1;31m  ";
                cout << i << "";
                cout << "\033[0m";
            }
            else if (out == in)
            {
                in = 0;
                out = 0;
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n+---------------------------------------------------------+\n";
        return;
    }
    for (int i = 0; i < maxSize; i++)
    {
        cout << " [" << i << ":" << L[i] << "] ";
    }
    cout << endl;
    cout << "            ";
    for (int i = 0; i < maxSize; i++)
    {

        cout << "  "
             << "in"
             << ":";
        if (i == in)
        {
            cout << "\033[1;32m  ";
            cout << i << "";
            cout << "\033[0m";
        }
        else
        {
            cout << "  ";
        }
    }
    cout << endl;
    cout << "            ";
    for (int i = 0; i < maxSize; i++)
    {
        cout << " "
             << "out"
             << ":";
        if (i == out)
        {
            cout << "\033[1;31m  ";
            cout << i << "";
            cout << "\033[0m";
        }
        else
        {
            cout << "  ";
        }
    }
    cout << "\n+---------------------------------------------------------+\n";
    cout << "\033[1;32m In : \033[0m" << in << "\033[1;31m Out : \033[0m" << out << endl;
}void FastArrayQueue::UpdateMaxSize(int ModifyMaxSize)
{
    this->maxSize = ModifyMaxSize;

}
