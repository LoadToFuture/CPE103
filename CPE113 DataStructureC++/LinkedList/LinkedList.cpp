#include "LinkedList.h"
using namespace std;
#include <iostream>

LinkedList::LinkedList(int maxSize)
{ // constructor  // slide page

    //! p point to dummy (0,NULL)
    // ChainNode *p = NULL;
    // p = new ChainNode;
    //! // firstNode point to dummy
    // firstNode = p;
    //! firstNode to new dummy node
    firstNode = new ChainNode;
    this->maxSize = maxSize;
    //! set curSize to zero
    curSize = 0;
}
LinkedList::~LinkedList()
{ // destructor //slide
    // p  point to dummy
    ChainNode *p = firstNode;
    //! loop
    while (p != NULL)
    {
        // n point to next of p
        ChainNode *n = p->next;
        // delete
        delete p;
        // p point to same pos of n
        p = n;
    }
    //!
}
void LinkedList::add(int i, int e)
{
    // check full //!(memory)
    ChainNode *q = new ChainNode(e);
    if (q == NULL) //! memory full
    {
        cerr << "Error !! memory is fully !! \n";
        return;
    }
    // if (curSize == maxSize)
    // {
    //     cerr << "** Error !! : list is full **" << endl;
    //     return;
    // }
    // index (low) (upper)
    if (i < 0)
    {
        cerr << "Warning !! Lower bound \n";
        cout << "Message : " << i << " Change to 0\n";
        i = 0;
    }
    else if (i > curSize)
    {
        cerr << "Warning !! Upper bound \n";
        cout << "Message : " << i << " Change to  current size :" << curSize << endl;
        i = curSize;
    }
    // p point to dummy
    ChainNode *p = firstNode;
    // move p forword i times
    for (int j = 0; j < i; j++)
        p = p->next;
    // q point to new node (e. ?)
    q->next = p->next;
    // adjust link p q
    p->next = q;
    // increed cursize
    curSize++;
}
void LinkedList::UpdateMaxSize(int UpdateMaxsize)
{
    while (curSize > UpdateMaxsize)
    {
        // ลบโหนดที่อยู่ต่อท้ายออกไปจนกว่าจะเท่ากับขนาดใหม่
        curSize = 0;
    }
    // ตรวจสอบว่ามีอยู่ในกรณีที่ขนาดใหม่เป็นใหญ่กว่าขนาดปัจจุบัน
    if (UpdateMaxsize > maxSize)
    {
        // สร้างโหนดแรก
        firstNode = new ChainNode;
        this->maxSize = UpdateMaxsize;
        //! set curSize to zero
        curSize = 0;
    }
}
int LinkedList::size()
{
    return curSize;
}
int LinkedList::indexOf(int e)
{
    ChainNode *p = firstNode->next; //! ตั้งตำแหน่งเริ่มต้น ต่อ จาก Dummy
    int countHaveE = 0;             // นับว่าเจอ Element ใน List กี่ตัว
    int indexHaveE = 0;             // นับว่ามี index อะไรบ้าง
    cout << "\n\nAmount index is found : ";
    cout << "index [ ";
    for (int i = 0; i < curSize; i++)
    {
        if (e == p->element)
        {
            countHaveE++;
            cout << indexHaveE << " ";
        }
        p = p->next; //! move p to next node
        indexHaveE++;
    }
    cout << "]\n";
    if (countHaveE > 0)
    {
        return countHaveE;
    }
    return -1;
}
int LinkedList::get(int i)
{
    // check empty
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return 0;
    }
    // check low upper
    if (i < 0)
    {
        cerr << "Warning !! Lower bound \n";
        cout << "Message : " << i << " Change to 0\n";
        i = 0;
    }
    else if (i > curSize - 1)
    {
        cerr << "Warning !! Upper bound \n";
        cout << "Message : " << i << " Change to   :" << curSize << endl;
        i = curSize - 1;
    }
    // p point to dummy to e0
    ChainNode *p = firstNode->next;
    for (int j = 0; j < i; ++j)
        p = p->next; //! move p to next node
   // cout << "\n\nSuccess!! Get element in address by index  : ";
    return p->element;
}
int LinkedList::remove(int i)
{
    // check empty
    if (curSize == 0)
    {
        cerr << "\n\n** Error !!: list is empty : **" << endl;
        return 0;
    }
    // check bound is data
    else if (i < 0 || i >= curSize)
    {
        cerr << "\n\n**Error !! :" << i << " is out of index Arraylist **" << endl;
        return 0;
    }
    // p point to dummy
    ChainNode *p = firstNode;
    // move p to bofore i times
    for (int j = 0; j < i; j++)
        p = p->next;
    // q point to i need delete
    ChainNode *q = p->next; // creat q pointer to save i to delete
    // get the element of the deleted node
    int removeElement = q->element;
    // r point to next node after delete
    ChainNode *r = q->next;

    // delete
    delete q;
    // adjust the link before and after the deleted node
    p->next = r;

    // reduce cursize
    curSize--;
    return removeElement;
}
void LinkedList::removeFirst(int index)
{
    ChainNode *p = firstNode; //! create dummy
    // check empty
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return;
    }
    // check index validity
    if (index < 0 || index > curSize)
    {
        cerr << "** Error !!: Index out of bounds **" << endl;
        return;
    }
    for (int i = 0; i < index; i++)
    {
        ChainNode *q = p->next;
        p->next = q->next;
        delete q;
    }
    curSize -= index;
    cout << "The index of the first element to be removed is:  " << index
         << " \nSuccess !! \n\n"
         << endl;
}
void LinkedList::removeValue(int Value)
{
    // ChainNode *dummy = new ChainNode(); // สร้างโหนดดัมมี่
    ChainNode *p = new ChainNode();
    p->next = firstNode;
    ChainNode *r = p;
    // check empty
    int countValue = 0;
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return;
    }
    //  ChainNode *q = firstNode;
    for (int i = 0; p->next != nullptr; i++)
    {
        if (p->next->element == Value)
        {
            ChainNode *temp = p->next; // เก็บค่าของโหนดที่จะลบ
            p->next = p->next->next;   // ปรับการเชื่อมต่อข้างหน้า
            delete temp;               // ลบโหนด
            countValue++;              // เพิ่มค่านับ
            curSize--;                 // ลดขนาดรายการ
        }
        else
        {
            p = p->next;
        }
    }
    delete r; // ลบโหนดดัมมี่
    if (countValue == 0)
        cerr << "** Error !!: Value not found in the list **" << endl;
    else
        cout << "Successfully removed " << countValue << " occurrences of value " << Value << " from the list" << endl;
}
void LinkedList::removeLast(int index)
{
    ChainNode *p = firstNode; //! create dummy
    // check empty
    if (curSize == 0)
    {
        cerr << "** Error !!: list is empty : **" << endl;
        return;
    }
    // check index validity
    if (index < 0 || index > curSize)
    {
        cerr << "** Error !!: Index out of bounds **" << endl;
        return;
    }
    for (int i = curSize - 1; i < index; i++)
    {
        ChainNode *q = p->next;
        p->next = q->next;
        cout << "before remove node " << p << endl;
        delete q;
        cout << "After remove node " << p << endl;
    }
    curSize -= index;
    cout << "The index of the Last element to be removed is : " << index
         << " \nSuccess !! \n\n"
         << endl;
}
void LinkedList::set(int i, int e)
{
    // ehcek empty
    if (curSize == 0)
    {
        cerr << "\n\nError !! : list is empty : " << endl;
        return;
    }
    else if (i < 0 || i >= curSize)
    {
        cerr << "\n\n** Error !! :" << i << " is out of index Arraylist **" << endl;
        return;
    }
    // p point to e0
    ChainNode *p = firstNode->next;
    for (int j = 0; j < i; j++)
        p = p->next; // move to next node e[0]
    cout << "\n\nSuccess!! Set is element [ " << i << " ] =  " << e << endl;
    p->element = e;
}

void LinkedList::display()
{
    // L: [e1,e2,.......,en-1] , n : n
    cout << "L : [";
    //!  p point e0;    // firstNode = dummy
    ChainNode *p = firstNode->next;
    for (int i = 0; i < curSize; i++)
    {
        cout << i << ":" << p->element; // display ei
        if (i < curSize - 1)
            cout << ", ";
        p = p->next; //! move p to next node
    }
    cout << "] n: " << curSize << endl;
}

int LinkedList::max()
{
    if (curSize == 0)
    {
        cerr << "** Error : list is empty : **" << endl;
        return 0;
    }
    int max_value = firstNode->element;
    ChainNode *p = firstNode->next;
    // Traverse the list
    while (p != nullptr)
    {
        // Update max_value if the current node's data is greater
        if (p->element > max_value)
            max_value = p->element;
        // Move to the next node
        p = p->next;
    }
    return max_value;
}

int LinkedList::min()
{
    // Check if the list is empty
    if (curSize == 0)
    {
        cerr << "** Error : list is empty : **" << endl;
        return 0;
    }
    // Start from the second node
    ChainNode *p = firstNode->next;
    // Initialize min_value with the value of the first node
    int min_value = firstNode->next->element;
    // Traverse the list
    while (p != nullptr)
    {
        // Update min_value if the current node's data is smaller
        if (p->element < min_value)
            min_value = p->element;
        // Move to the next node
        p = p->next;
    }
    // Return the minimum value found
    return min_value;
}

int LinkedList::oddCount()
{
    int OddCount = 0;
    int indexOdd = 0;
    ChainNode *p = firstNode->next;
    cout << "\n\nOdd number in list is : index | ";
    for (int i = 0; i < curSize; i++)
    {
        if (p->element % 2 != 0)
        {
            OddCount++;
            cout << "[" << indexOdd << "]:" << p->element;
            if (i < curSize - 1)
                cout << ", ";
        }
        p = p->next; //! move p to next node
        indexOdd++;
    }
    cout << " |\n";
    return OddCount;
}
int LinkedList::EvenCount()
{
    int EvenCount = 0;
    int indexEven = 0;
    ChainNode *p = firstNode->next;
    cout << "\n\nEven number in list is : index [ ";
    for (int i = 0; i < curSize; i++)
    {
        if (p->element % 2 == 0)
        {
            EvenCount++;
            cout << "[" << indexEven << "]: " << p->element;
            if (i < curSize - 1)
                cout << ", ";
        }
        p = p->next; //! move p to next node
        indexEven++;
    }
    cout << " ]\n";
    return EvenCount;
}

double LinkedList::sum()
{
    // Check if the list is empty
    if (curSize == 0)
    {
        cerr << "** Error : list is empty : **" << endl;
        return 0.0f;
    }
    float sum = 0.0f;
    ChainNode *p = firstNode->next;
    while (p != nullptr)
    {
        sum += p->element;
        p = p->next; //! Move to the next node
    }
    return sum;
}

double LinkedList::Average()
{
    // Check if the list is empty
    // if (curSize == 0)
    // {
    //     cerr << "** Error : list is empty : **" << endl;
    //     return 0.0f;
    // }
    // int count = 0;
    // ChainNode *p = firstNode->next; //!dummy
    // while (p != nullptr)
    // {
    //     count++;
    //     p = p->next; //! Move to the next node
    // }
    // //! calculater of value in linklist
    return sum() / curSize;
}
void LinkedList::sortvalue(char c)
{
    ChainNode *p = firstNode->next; //! point  p to dummy
    for (int i = 0; i < curSize; i++)
    {
        ChainNode *q = p->next; //! point q to dummy
        for (int j = 1 + i; j < curSize; j++)
        {
            if (c == 'y' || c == 'Y')
            {
                if (p->element < q->element)
                {
                    // cout << "swap" << endl;
                    int x = p->element;
                    p->element = q->element;
                    q->element = x;
                }
            }
            else if (c == 'n' || c == 'N')
            {
                if (p->element > q->element)
                {
                    // cout << "swap" << endl;
                    int x = p->element;
                    p->element = q->element;
                    q->element = x;
                }
            }
            // cout << "move q" << endl;
            q = q->next;
        }
        // cout << "move p" << endl;
        p = p->next;
    }
}
void LinkedList::clearList()
{
    // ใช้ลูป while เพื่อลบทุกโหนดในลิงก์ลิสต์
    while (firstNode->next != nullptr)
    {
        // เก็บตัวชี้ไปยังโหนดที่จะลบ
        ChainNode *temp = firstNode->next;
        // ย้ายตัวชี้ไปยังโหนดถัดไปของโหนดที่จะลบ
        firstNode->next = temp->next;
        // ลบโหนด
        delete temp;
        // ลดขนาดของลิงก์ลิสต์ลง 1
        curSize--;
    }
}


