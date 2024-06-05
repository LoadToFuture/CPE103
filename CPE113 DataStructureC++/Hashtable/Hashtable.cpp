#include "Hashtable.h"
#include <iostream>
using namespace std;

Hashtable::Hashtable(int _tableSize)
{
    this->tableSize = _tableSize;
    curSize = 0;
    L = new int[this->tableSize];
}
Hashtable::~Hashtable()
{
    delete[] L;
}
void Hashtable::clear()
{
    for (int i = 0; i < tableSize; i++)
        L[i] = 0; //! clear element in ListHash
    curSize = 0;  // set size
}
void Hashtable::loadFacterConfig(float loadFac)
{
    this->loadFacter = loadFac;
}

void Hashtable::UpdateMaxSize(int UpdateMaxSize)
{
    this->tableSize = UpdateMaxSize;
    for (int i = 0; i < tableSize; i++)
        L[i] = 0; //! clear element in ListHash
    curSize = 0;  // set size
}

void Hashtable::hashfunction(int key)
{
    hash_key = key % tableSize;
    // private
}
void Hashtable::insert(int value)
{
    hashfunction(value);

    // Linear probing function
    for (int i = 0; i < tableSize; i++)
    {
        int index = (hash_key + i) % tableSize; //! Probing function
        if (L[index] == 0)
        {
            L[index] = value;
            curSize++;
            // Check load factor
            float loadFactor = (float)curSize / tableSize; //! Calculate 80% with table size
            if (loadFactor >= loadFacter)                  //! 0.8 = 80% , 0.75 = 75%
                rehasting();
            return; // Return after successful insertion
        }
    }
    // If the table is full after probing, rehash and insert the value again
    rehasting();
    // After rehashing, re-calculate the hash value and find its new index
    hashfunction(value);
    int index = hash_key % tableSize; // Find new index after rehashing
    L[index] = value;                 // Insert value at the new index
    curSize++;                        // Update current size
    return;                           // Return after successful insertion
}

void Hashtable::rehasting()
{
    int oldSize = tableSize; // Store the old size of the table
    tableSize *= 2;          // Increase the size of the table to twice its original size
    int *oldL = L;           // Store the position of the old table
    L = new int[tableSize];  // Create a new table with the new size

    // Rehash all elements
    for (int i = 0; i < oldSize; ++i)
    {
        if (oldL[i] != 0) // If there is data in the old position
        {
            int value = oldL[i];                // Store the old data value
            hashfunction(value);                // Find a new index for the old value
            for (int j = 0; j < tableSize; j++) // Loop to find a suitable position in the new table
            {
                int index = (hash_key + j) % tableSize; // Calculate the new index
                if (L[index] == 0)                      // If the position in the new table is empty
                {
                    L[index] = value; // Insert the data
                    break;            // Exit the loop
                }
            }
        }
    }
    delete[] oldL; // Delete the old table since the data has been moved to the new table
}
int Hashtable::getData(int key)
{
  if (key >= 0 && key < tableSize) { // ตรวจสอบว่า index อยู่ในขอบเขตของตารางแฮชหรือไม่
        if (L[key] != 0) { // ตรวจสอบว่ามีข้อมูลในตำแหน่ง index หรือไม่
            return L[key]; // คืนค่า Element ที่ตำแหน่ง index
        } else {
            cout << "No element at index " << key << endl;
            return -1; // หรือค่าอื่น ๆ ที่เหมาะสมตามสถานการณ์
        }
    } else {
        cout << "Invalid index" << endl;
        return -1; // หรือค่าอื่น ๆ ที่เหมาะสมตามสถานการณ์
    }
}
void Hashtable::deleteByIndex(int index) {
    if (index >= 0 && index < tableSize) { // ตรวจสอบว่า index อยู่ในขอบเขตของตารางแฮชหรือไม่
        if (L[index] != 0) { // ตรวจสอบว่ามีข้อมูลในตำแหน่ง index หรือไม่
            L[index] = 0; // ลบข้อมูลที่ตำแหน่ง index โดยการกำหนดให้มีค่าเป็น 0
            curSize--; // ลดขนาดปัจจุบันของตารางแฮชลง 1
            cout << "Element at index " << index << " has been deleted." << endl;
        } else {
            cout << "No element at index " << index << endl;
        }
    } else {
        cout << "Invalid index" << endl;
    }
}
void Hashtable::display()
{
    cout << "+----------------------------------+" << endl;
    for (int i = 0; i < tableSize; ++i)
    {
        cout << "| " << i << ": ";
        if (L[i] != 0)
            cout << L[i];
        cout << endl;
    }
    cout << "+----------------------------------+" << endl
         << endl;
    cout << "Element in Hash Table: " << curSize << " / " << tableSize << endl;
}
