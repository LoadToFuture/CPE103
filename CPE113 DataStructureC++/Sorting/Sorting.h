#ifndef _SORTING_H
#define _SORTING_H
#include "../ArrayList/ArrayList.h"

class Sorting :public ArrayList
{
private:
int *L;
    int maxSize;
public:
     Sorting(int MaxSize);
    // ~Sorting();
    void swap(int *data,int i , int j);
    int findMaxIndex(int *data,int n);

    void SelectionSort(int *data, int n);
    void InsertSort();
    void BubbleSort();



};




#endif // _SORTING_H