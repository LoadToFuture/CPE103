#include "Sorting.h"
#include <iostream>
using namespace std;

Sorting::Sorting(int MaxSize) : ArrayList(MaxSize)
{
    this->maxSize = MaxSize;
}



void Sorting::swap(int *data, int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int Sorting::findMaxIndex(int *data, int n)
{
    // first set max index at zero potition
    int maxIndex = 0;

    // scan for index of maximum value
    for (int i = 0; i < n; i++)
        if (data[maxIndex] < data[i])
            maxIndex = i;
    // return index of maximum value
    return maxIndex;
}

void Sorting::SelectionSort(int *data, int n)
{
 
    
}
