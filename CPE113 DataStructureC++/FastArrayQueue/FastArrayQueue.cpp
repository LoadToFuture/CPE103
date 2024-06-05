#include "FastArrayQueue.h"
#include <iostream>
using namespace std;
#include <iomanip> // สำหรับ setw
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
    in = 0;
    out = 0;
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
    cout << "\n+---------------------------------------------------------+\n\n";
    if (curSize == 0)
    {
        for (int i = 0; i < 1; i++)
        {
            cout << " [" << i << ": ].........[" << maxSize << ": ] ";
        }

        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << " "
                 << "in"
                 << ":";
            if (i == in)
                cout << "\033[1;32m " << i << " \033[0m";
            else
                cout << " ";
        }
        cout << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << " "
                 << "out"
                 << ":";
            if (i == out)
                cout << "\033[1;31m " << i << " \033[0m";
            else
                cout << " ";
        }
        cout << "\n+---------------------------------------------------------+\n";
        return;
    }

    int numline = 5;
    int currentIndex = 0;

    while (currentIndex < maxSize)
    {

        for (int line = 0; line < numline && currentIndex < maxSize; ++line)
        {
            cout << " [" << currentIndex << ":" << L[currentIndex] << "] ";
            currentIndex++;
        }
        cout << "\033[1;32m\n\033[0m";
        for (int i = 0; i < in; ++i)
        {
            if (i == 0)
                cout << " ";
            else if (i >= 1)
                cout << setw(8) << "   ";   
            if ((i + 1) % 6 == 0)   
                cout << endl;
        }
        cout << "\033[1;32m" << setw(4) << "In :" << in << "\033[0m" << endl;
        for (int i = 0; i < out; i++)
        {
            if (i == 0)
                cout << setw(10) << "    ";
            else if (i >= 1)
                cout << setw(8) << "   ";
            if ((i + 1) % 6 == 0)
                cout << endl;
        }
        cout << "\033[1;31m" << setw(3) << "Out:" << out << "\033[0m\n";
        cout << "\033[0m\n";
        if (currentIndex % (maxSize * numline) == 0)
            numline += 1;
    }
    cout << "\n+---------------------------------------------------------+\n";
    cout << "\033[1;32m In : \033[0m" << setw(3) << in << "\033[1;31m Out : \033[0m" << setw(3) << out << endl;
}
void FastArrayQueue::UpdateMaxSize(int ModifyMaxSize)
{
    this->maxSize = ModifyMaxSize;
}
