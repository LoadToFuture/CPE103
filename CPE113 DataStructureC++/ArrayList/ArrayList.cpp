#include "ArrayList.h"
#include <iostream>
#include <iomanip>
#include <ctime>

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
void ArrayList::updateMaxSie(int UpdateMaxSize)
{
     curSize = 0;
      delete[] L; 
    this->maxSize = UpdateMaxSize;
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
    if (curSize == maxSize)
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
    // cout << "\n\n\nCorrect !! Add value in array \n";
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
    for (int i = 0; i < curSize - 1; i++)
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
    if (curSize == 0)
    {
        cout << "[ ]" << endl;
        return;
    }

    for (int i = 0; i < curSize; i++)
    {
        cout << " [" << setw(3) << i << ":" << setw(3) << L[i] << "] "; // กำหนดความกว้างของคอลัมน์
        if ((i + 1) % 10 == 0) // เปลี่ยนบรรทัดทุกรายการที่ i เป็นตัวเลขที่หารด้วย 10 ลงตัว
            cout << endl;
    }
    // cout << " Size : " << curSize << "/" << maxSize << endl;
}
    
void ArrayList::shuffle()
{
    srand(time(0)); // Initialize random seed based on current time

    int n = curSize;
    // Loop through the list and swap each element with a randomly selected element
    for (int i = 0; i < n; ++i)
    {
        // Generate a random index to swap with (from i to n-1)
        int randomIndex = i + rand() % (n - i);

        // Swap the elements at indices i and randomIndex
        int temp = get(i);
        set(i, get(randomIndex));
        set(randomIndex, temp);
    }
}
void ArrayList::swap(int *data, int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int ArrayList::findMaxIndex(int *data, int n)
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

void ArrayList::SelectionSort()
{
    for (int nElement = curSize; nElement > 1; nElement--)
    {
        int maxIndex = findMaxIndex(L, nElement);
        swap(L, maxIndex, nElement - 1);
    }
}
void ArrayList::InsertSort()
{
    //! set number of element [2,3, .... . , n]
    for (int nData = 2; nData <= curSize; nData++)
        //!  do insertion only for nData elements
        insert(L, nData);
}
void ArrayList::insert(int *data, int n)
{
    // pick insert data at index n-1
    int insertData = data[n - 1];
    // set insert index to n-2
    int insertPos = n - 2;
    // check insertion condition     ///   ปรับมากไปน้อย < น้อยไปมาก
    while (insertPos >= 0 && data[insertPos] > insertData)
    {
        swap(data, insertPos, insertPos + 1);
        insertPos--;
    }
}

void ArrayList::bubble_(int n)
{
    // do bubble for n elements
    for (int i = 0; i < n - 1; i++)
        // check condition for swapping
        if (L[i] > L[i + 1])
            swap(L, i, i + 1);
}
void ArrayList::BubbleSort()
{
    // set number of element [n,n-1]
    for (int nData = curSize; nData > 1; nData--)
        // do double only for ndata elements
        bubble_(nData);
}

void ArrayList::shellSort()
{
    //! do shell for k = [n/2,n/4,....,1]
    for (int k = curSize / 2; k >= 1; k = k / 2)
        selectk(L, curSize, k);
}

void ArrayList::selectk(int *data, int n, int k)
{
    for (int i = 0; i < k; i++)
        for (int j = i; j < n; j = j + k)
        {
            int iMin = findMinIndexK(data, n, j, k);
            swap(data, j, iMin);
        }
}

int ArrayList::findMinIndexK(int *data, int n, int iStart, int k)
{
    //! first set min index at first index
    int minIndex = iStart;

    //! scan for index pf minimum value
    for (int i = iStart + k; i < n; i = i + k)
        if (data[i] < data[minIndex])
            minIndex = i;

    //! return index of minumum value
    return minIndex;
}
void ArrayList::merge()
{
    //! allocate and copy data
    int *temp = new int[curSize];
    copyArray(L, temp, 0, curSize - 1);
    //! merg sort for temp input and data output
    merge_(temp, L, 0, curSize - 1);

    //! destroy temp
    delete(temp);
}

void ArrayList::copyArray(int *src, int *dest, int begin, int end)
{
    for (int i = begin; i <= end; i++)
        dest[i] = src[i];
}

void ArrayList::merge_(int *data, int *result, int begin, int end)
{
    //! check number of data
    if (end - begin <= 0)
        return;
    //! continue divide data
    merge_(data, result, begin, (begin + end) / 2);
    merge_(data, result, (begin + end) / 2 + 1, end);
    //! merge sort
    int i = begin, j = (begin + end) / 2 + 1;
    for (int k = begin; k <= end; k++)
    {
        if (i > (begin + end) / 2)
            result[k] = data[j++];
        else if (j > end)
            result[k] = data[i++];
        else if (data[i] > data[j])
            result[k] = data[j++];
        else
            result[k] = data[i++];
    }
    //! update result to data before return
    copyArray(result, data, begin, end);
}

void ArrayList::quick()
{
    //! perform reucrsive quick sort
    quick_(L, 0, curSize - 1);
}
void ArrayList::quick_(int *data, int begin, int end)
{

    //! check index
    if (end - begin <= 0) return;
    //! pick pivot index
    int iPivot = pickPivotIndex(data, begin, end);
    //! swap between index of pivot and last data
    swap(data, iPivot, end);
    //! partition to two data sets
    int i = begin, j = end - 1;
    while (i <= j)
    {
        while (i <= j && data[i] < data[end])
            i++;
        while (i <= j && data[j] >= data[end])
            j--;
        if (i < j)
            swap(data, i, j);
    }
    //! swap i and end (pivot)
    swap(data, i, end);
    //! perform quick sort in two data sets, recursively
    quick_(data, begin, i - 1);
    quick_(data, i + 1, end);
}

int ArrayList::pickPivotIndex(int *data, int begin, int end)
{
    //! culculate middle position
    int mid = (begin + end) / 2;
    //! re-assign variable (easy to call),like a,b and c
    int a = data[begin], b = data[mid], c = data[end];
    //! check for middle coniditions
    if ((a >= b && b >= c) || (a <= b && b <= c))
        return mid;
    else if ((b >= c && c >= a) || (b <= c && c <= a))
        return end;
    else if ((c >= a && a >= b) || (c <= a & a <= b))
        return begin;
    //!un-reachale code, just for warning avoidance
    return mid;
}
