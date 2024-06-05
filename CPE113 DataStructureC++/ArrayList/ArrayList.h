#ifndef _ARRAYLIST_H_ //
#define _ARRAYLIST_H_

class ArrayList
{
    // private date
private:                    // data
    int *L;                 // point to list or list Array
    int maxSize;            // maximum size
    int curSize;            // current size
public:                     // methods
    ArrayList(int maxSize); // constuctor //
    ~ArrayList();
    void updateMaxSie(int UpdateMaxSize);
    int getMaxSize() const { return maxSize; } // destructor
    int size();
    int indexOf(int e); // element
    int get(int i);
    int remove(int i);
    void removefirst(int index);
    void removelast(int index);
    void removeValue(int value);
    void set(int i, int e);
    void add(int i, int e);
    int maximum();
    int minimum();
    void clearArray();
    void dataIsEmpty();
    void display();

    void shuffle();

    //! sortfunction
    //! aux Sort
    //! Selact------------------------------------------------
    void swap(int *data, int i, int j);
    int findMaxIndex(int *data, int n);
    void SelectionSort();
    //! Insert------------------------------------------------
    void insert(int *data, int n);
    void InsertSort();
    //! Bubble------------------------------------------------
    void bubble_(int n);
    void BubbleSort();
    //! Shell------------------------------------------------
    void shellSort();
    void selectk(int *data, int n, int k);
    int findMinIndexK(int *data, int n, int iStart, int k);
    //! merge------------------------------------------------
    void merge();
    void copyArray(int *src, int *dest, int begin, int end);
    void merge_(int *data, int *result, int begin, int end);
    //! quick------------------------------------------------
    void quick();
    void quick_(int *data, int begin, int end);
    int pickPivotIndex(int *data, int begin, int end);
};
#endif //_ARRAYLIST_H
