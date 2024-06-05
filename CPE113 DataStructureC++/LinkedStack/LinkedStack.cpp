#include "LinkedStack.h"
#include <iostream>
#include <iomanip> //
using namespace std;
LinkedStack::LinkedStack(int MaxSize) : LinkedList(MaxSize)
{
    firstNode = new ChainNode;
    this->maxSize = MaxSize;
}

void LinkedStack::UpdateMaxSize(int newMaxSize)
{
    clearList();
    this->maxSize = newMaxSize;
}

void LinkedStack::push(int e)
{
    if (size() == maxSize)
    {
        cerr << "Error List Full !! \n";
        return;
    }
    add(size(), e);
}

int LinkedStack::pop()
{
    if (isEmpty())
    {
        cerr << "Stack is empty." << endl;
        return -1;
    }
    return remove(size() - 1);
}

int LinkedStack::top()
{
    return get(size() - 1);
}

bool LinkedStack::isEmpty()
{
    cout << "Remaining free space : " << maxSize - size() << endl;
    return size() == 0;
}
bool LinkedStack::isFull()
{
    cout << "Remaining free space : " << maxSize - size() << endl;
    return size() == maxSize;
}

void LinkedStack::StackDisplay()
{
    // ChainNode *p = firstNode->next;
    // cout << "[DM]->[FN]->\n";
    if (size() == 0)
    {
        for (int i = 0; i < 5; i++)
            cout << "[" << i << ":0]->";
        cout << "  .........->[" << maxSize << ":0]";
        cout << "\033[1;33m\n\n+-------------------------------------------------------------------------------------------------------------+\n\033[0m\n";
        return;
    }

    for (int i = 0; i < size(); i++)
    {
        cout << "[" << setw(2) << i << ":" << setw(2) << get(i) << "]";
        if (i < size() - 1)
        {
            cout << " -> ";
            if ((i + 1) % 10 == 0)
            {                 // เมื่อครบ 10 โหนด
                cout << endl; // เว้นบรรทัด
            }
        }
        else if (i == size() - 1)
            cout << "\033[1;33m -> NULL\033[0m";
    }
    cout << "\033[1;33m\n\n\n+-------------------------------------------------------------------------------------------------------------+\n\033[0m\n";
}

void LinkedStack::swap01()
{
    if (size() >= 2)
    {
        int temp = get(size() - 1);
        set(size() - 1, get(size() - 2));
        set(size() - 2, temp);
        cout << "Swap Success!! \n";
    }
}

void LinkedStack::swap02()
{
    if (size() >= 2)
    {
        int temp = get(maxSize - size());
        set(maxSize - size(), get(size() - 1));
        set(size() - 1, temp);
        cout << "Swap Success!! \n";
    }
    cout << "First " << get(maxSize - size()) << endl;
    cout << "Last " << get(size() - 1) << endl;
}
