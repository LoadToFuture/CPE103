#include <iostream>
#include "Arraylist.h"
using namespace std;

ArrayList::ArrayList(int maxSize)
{
    this->maxSize = maxSize;
    curSize = 0;
    L = new int[this->maxSize];
}

ArrayList::~ArrayList()
{
    delete[] L;
}

void ArrayList::setMaxsize(int i)
{
    if (i < 0){
        cerr << "Cannot enter negative values.";
        return;
    }
    maxSize = i;
}

int ArrayList::CheckSize(int i)
{
    if (i < CurSize)
    {
        return -1;
    }
    return 0;
}
int ArrayList::size()
{
    return curSize;
}

void ArrayList::add(int i, int e)
{
    if (i < 0)
    {
        //cout << "" << endl;
        i = 0;
    }
    else if (i > curSize)
    {
        i = curSize;
    }
    else if (curSize == maxSize)
    {
        cout << endl;
        cerr << "List is full." << endl;
        return;
    }
    for (int x = curSize - 1; x >= i; x--)
    {
        //cout << "x is "<< x << endl;
        L[x + 1] = L[x];
    }

    L[i] = e;
    curSize++;
}
int ArrayList::remove(int i)
{

    if (curSize == 0)
    {
        //cerr << "list is empty" << endl;
        return 0;
    }
    else if (i > curSize && i < maxSize)
    {
        //cerr << "Index is empty" << endl;
        return 0;
    }
    else if (i > curSize)
    {
        return -1;
    }
    for (int x = i; x < curSize - 1; x++) 
    {
        L[x] = L[x + 1]; 
    }
    curSize--; 

    return L[i]; 
}

int ArrayList::indexOf(int e)
{
    if (curSize == 0)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < maxSize; ++i)
        {
            if (e == L[i])
            {
                return i;
            }
        }
    }
    return -1;

}

int ArrayList::get(int i)
{
    if (curSize == 0)
    {
        //cerr << "list is empty" << endl;
        return 0;
    }
    else if (i > curSize && i < maxSize)
    {
        //cerr << "Index is empty" << endl;
        return 0;
    }
    else if (i > curSize)
    {
        return -1;
    }
    else if (i > maxSize - 1 || i < 0)
    {
        //cerr << i << " is out of index Arraylist " << endl;
        return -1;
    }
    return L[i];
}

void ArrayList::set(int i,int e)
{
    if (curSize == 0)
    {
        cerr << "list is empty" << endl;
        return;
    }
    else if (i > curSize && i < maxSize)
    {
        cerr << "Index is empty" << endl;
        return;
    }
    else if (i > maxSize - 1 || i < 0)
    {
        cerr << i << " is out of index Arraylist " << endl;
        return;
    }
    L[i] = e;
}

void ArrayList::display()
{
    CurSize = curSize ;
    
    cout << "Max size of array : " << maxSize << endl;
    cout << "Current size of array : " << curSize << endl;
    cout << "Array : [ ";

    for (int i = 0; i < curSize; i++)
    {
        cout << L[i];
        if (i < curSize - 1) 
        {
            cout << ",";
        }
    }
    cout << " ]" << endl;  
    cout << endl;
    cout << "66012975 Thanawat Payungwong" << endl;
}

int ArrayList::maxVal()
{
    if (curSize == 0)
    {
        return -1;
    }
    else
    {
        int maxVal = L[0];
        for(int i = 1; i < curSize; ++i)
        {
            if(L[i] > maxVal)
            {
                maxVal = L[i];
            }
        }
        return maxVal;
    }
}

int ArrayList::minVal()
{
    if (curSize == 0)
    {
        return -1;
    }
    else
    {
        int minVal = L[0];
        for(int i = 1; i < curSize; ++i)
        {
            if(minVal > L[i])
            {
                minVal = L[i];
            }
        }
        return minVal;
    }
}

void ArrayList::clear()
{
    if (curSize == 0)
    {
        cerr << "List is empty" << endl;
        return;
    }
    else
    {
        cout << "succeed" << endl;
        curSize = 0;
    }
    
}

bool ArrayList::isEmpty()
{
    if (curSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ArrayList::removefirst(int limit)
{
    if (curSize == 0)
    {
        cerr << "List is empty" << endl;
        return;
    }
    else if (limit > curSize)
    {
        cerr << "Limit is out of index" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < limit; i++)
        {
            for (int j = 0; j < curSize; j++)
            {
                //cout << "j is " << j << endl;
                L[j] = L[j + 1]; 
            }
            curSize--;
        }
    }
}

void ArrayList::removelast(int limit)
{
    if (curSize == 0)
    {
        cerr << "List is empty" << endl;
        return;
    }
    else if (limit > curSize)
    {
        cerr << "Limit is out of index" << endl;
        return;
    }
    else
    {
        curSize -= limit;
    }
}