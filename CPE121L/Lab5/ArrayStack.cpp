#include <iostream>
#include "ArrayStack.h"
using namespace std;


ArrayStack::ArrayStack(int maxSize) : ArrayList(maxSize) // Call ArrayList constructor
{
    this->maxSize = maxSize;
}

void ArrayStack::setMaxSize(int MS)
{
    maxSize = MS;
}

void ArrayStack::push(int e)
{
    if (isFull())
    {
        //cerr << "Stack is full." << endl;
        return;
    }
    add(size(), e);
}

bool ArrayStack::isFull()
{
    //cout << size() << " " << maxSize << endl;
    return size() == maxSize;
}

bool ArrayStack::isEmpty()
{
    return size() == 0;
}

int ArrayStack::pop()
{
    if (isEmpty())
    {
        //cerr << "Stack is empty." << endl;
        return -1;
    }
    return remove(size() - 1);
}

void ArrayStack::display()
{
    cout << "Size : " << size() << " / " << maxSize <<  endl;
    cout << "Stack : [";
    for (int i = size() - 1; i >= 0; i--)
    {
        cout << get(i);
        if (i != 0)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
    cout << endl;
    cout << "66012975 Thanawat Payungwong" << endl;

}

int ArrayStack::top()
{
    if (isEmpty())
    {
        //cerr << "Stack is empty." << endl;
        return -1;
    }
    return get(size() - 1);
}

void ArrayStack::swapTop()
{
    if (size() < 2)
    {
        //cerr << "Stack has less than 2 elements." << endl;
        return;
    }
    int temp = get(size() - 1); // Get the top element
    set(size() - 1, get(size() - 2)); // Set the top element to the second top element
    set(size() - 2, temp);
}