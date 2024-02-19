#include "ArrayList.h"
#include <iostream>
using namespace std;
ArrayList::ArrayList(int maxSize) // default 5
{
    // cout << "Constructor" << endl;
    // keep maximum size
    this->maxSize = maxSize; // this->
                             // set current size to zero
    curSize = 0;
    // allocate list array
    L = new int[this->maxSize];
}
ArrayList::~ArrayList()
{
    // release list
    //  L = new int ; // Single
    delete[] L; // array
    // cout << "Destructor" << endl;
}
int ArrayList::size()
{
    // return current size
    return curSize;
}
int ArrayList::indexOf(int e)
{
    for (int i = 0; i < curSize; ++i) // search value all in Arraylist
    {
        if (e == L[i]) // if e = element is have in Arraylist is >> OK it HAVE!! and return i = element you search
                       // cout << "Found this value in element " << e << " at index of " << i << endl;
            return i;  // is found return value is have in List
    }
    // cout << "Is not found this value in element : " << e << " = index " << -1 << endl;
    return -1; // if e = element is not have in Arraylist is >> OK It not HAVE !! and return -1
}
int ArrayList::get(int i)
{
    // check empty
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return 0;
    }
    // check i if lower index
    if (i < 0)
    {
        cout << "----------------------------------------------\n";
        cerr << "Warning!! lower bound index : " << i << endl;
        cout << "Message: index " << i << " Change to 0" << endl;
        i = 0;
    } // check i if upper bound
    else if (i > curSize - 1)
    {
        cout << "----------------------------------------------\n";
        cerr << "Warning !! upper bound index " << i << endl;
        cout << "Message: index " << i << " Change to " << curSize - 1 << endl;
        i = curSize - 1;
    }
    // i is correct inde
    // return element of i (index) L=[i]
    return L[i]; // L[3] ;
}

int ArrayList::remove(int i)
{
    // check empty
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return 0;
    }
    // check bound is data
    else if (i < 0 || i >= curSize)
    {
        cerr << "** Error !! :" << i << " is out of index Arraylist **" << endl;
        return 0;
    }
    //  save element to delete
    int remove_element = L[i]; // I=3  == L[3] ;
    // shifright
    for (int j = i; j < curSize - 1; j++)
        L[j] = L[j + 1]; // sheft left // search after remove and shift  Left L[3] > L[4]
    curSize--;           // reduce length curSize Ex. 5 - 1

    return remove_element; // sent to main and show c out
}

void ArrayList::removefirst(int index)
{
    // check empty
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return;
    }
    else if (index >= curSize)
    {
        cerr << "** Error !!: Index out of range : **" << endl;
        return;
    }
    for (int i = 0; i < curSize; i++)
        L[i] = L[i + index];
    curSize -= index;
    cout << "The index of the first element to be removed is:  " << index
         << " \nSuccess !! \n\n"
         << endl;
}

void ArrayList::removelast(int index)
{
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return;
    }
    else if (index >= curSize)
    {
        cerr << "** Error !!: Index out of range : **" << endl;
        return;
    }                 //   5         5       4
    curSize -= index; // curSize = curSize - index ;
    cout << "The index of the Last element to be removed is : " << index
         << " \nSuccess !! \n\n"
         << endl;
}

void ArrayList::removeValue(int value)
{
    // check epmty
    // ตรวจสอบว่าลิสต์ว่างหรือไม่
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return;
    }
    int removed = 0; // จำนวนสมาชิกที่ถูกลบไป
    for (int i = 0; i < curSize; i++)
    {
        if (L[i] == value)
        {
            removed++;
        }
        else if (removed > 0)
        {
            L[i - removed] = L[i];
        }
    }
    curSize -= removed;
    // if (curSize == 0)
    // {
    //     cerr << "** Error !!: list is empty : **" << endl;
    //     return;
    // }

    // for (int i = 0; i < curSize; i++)
    // {
    //     if (L[i] == value)
    //     {
    //         for (int j = i; j < curSize - 1; j++)
    //         {
    //             L[j] = L[j + 1];
    //         }
    //         curSize--;
    //     }
    // }
    cout << "Remove element in index by Value : " << value
         << " \nSuccess !! \n\n";
}
void ArrayList::set(int i, int e)
{
    // check empty

    if (curSize == 0)
    {
        cerr << "** Error : list is empty : **" << endl;
        return;
    }
    // check range i in index Arraylist
    //         lower       upper
    else if (i < 0 || i >= curSize)
    {
        cerr << "** Error !! :" << i << " is out of index Arraylist **" << endl;
        return;
    }
    // set element
    cout << "Success!! Set is element [ " << i << " ] =  " << e << endl;
    L[i] = e;
}
void ArrayList::add(int i, int e)
{
    // check full
    if (curSize >= maxSize)
    {
        cerr << "** Error !! : list is full **" << endl;
        return;
    }
    // has any room
    // check lower
    if (i < 0) // 0 = index[0]
    {
        cout << "----------------------------------------------\n";
        cerr << "Warning!! lower bound index : " << i << endl;
        cout << "Message: index " << i << " Change to 0" << endl;
        i = 0;
    }
    // check upper
    else if (i > curSize) //
    {
        cout << "----------------------------------------------\n";
        cerr << "Warning!! upper bound index : " << i << endl;
        cout << "Message: index " << i << " Change to " << curSize << endl;
        i = curSize;
    }
    // shift right (from index cursize-1 to i)
    for (int j = curSize - 1; j >= i; j--)
    {
        L[j + 1] = L[j]; // shift right
    }
    // add e to L[i]
    L[i] = e;
    // increment cursize
    curSize++;
    cout << "\n\n\nCorrect !! Add value in array \n";
}
int ArrayList::maximum()
{
    if (curSize == 0)
    {
        cerr << "** Error : list is empty : **" << endl;
        return 0;
    }
    int max = L[0];
    int i = 0;
    // for (int i = 0; i < curSize; i++)
    //  if (L[i] > max)
    //      max = L[i];
    while (i < curSize)
    {
        if (L[i] > max)
            max = L[i];
        i++;
    }

    return max;
}

int ArrayList::minimum()
{
    if (curSize == 0)
    {
        cerr << "** Error : list is empty : **" << endl;
        return 0;
    }
    int min = L[0];
    for (int i = 0; i < curSize; i++)
        if (L[i] < min)
            min = L[i];
    return min;
}
void ArrayList::clearArray()
{
    for (int i = 0; i < curSize; i++)
        L[i] = 0; // set L[i] == 0
    curSize = 0;  // set size = 0 หรือ curSize =0;
    cout << "Array list CLEAR!! \n";
}

void ArrayList::dataIsEmpty()
{
    for (int i = 0; i < curSize; i++)
        L[i] = 0;
    cout << "Data is empty!! \n";
}

void ArrayList::display()
{
    // L : {1,2,3,4,5}  size : cur_size / max_size
    cout << "Array is : ";
    if (curSize == 0)
    {
        cout << "[ ]" << endl;
        return;
    }
    cout << "[0:" << L[0] << "]"; // แสดงข้อมูลตำแหน่งแรกทันที
    for (int i = 1; i < curSize; i++)
        cout << " [" << i << ":" << L[i] << "] ";
    cout << endl;
    // cout << " Size : " << curSize << "/" << maxSize << endl;
}
