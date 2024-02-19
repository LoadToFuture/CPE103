#ifndef _ARRAYLIST_H_ //
#define _ARRAYLIST_H_

 

class ArrayList
{
    // private date
private: // data
    int *L;       // point to list or list Array
    int maxSize;  //maximum size
    int curSize;  //current size
public:           // methods
    ArrayList(int maxSize);  // constuctor //
    ~ArrayList(); // destructor
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
} ;
#endif //_ARRAYLIST_H
