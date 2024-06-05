#include <iostream>
using namespace std;
#include "Hashtable.h"
#include <ctime>
#include <chrono>
void waitForEnter()
{
    cout << endl;
    cout << "Please enter to continue...";
    cin.ignore();
    cin.get();
    cout << "\x1B[2J\x1B[H";
}
int getValueInvalid()
{
    int SetMaxSize;
    do
    {
        cout << "Enter Max size of array : ";
        cin >> SetMaxSize;
        if (SetMaxSize <= 0 || cin.fail())
        {
            cin.clear();  // ล้างสถานะของ cin
            cin.ignore(); // ล้างค่าที่เหลือใน buffer
            cout << "Invalid input. Please enter a valid Maxsize" << endl;
        }
    } while (SetMaxSize <= 0 || cin.fail());
    return SetMaxSize;
} // Function to check the execution time of a sorting algorithm
int main()
{
    int SetMaxSize, choice, updateMaxSize;
    SetMaxSize = getValueInvalid();
    Hashtable list(SetMaxSize);
    float loadFacter;

    cout << "Enter config loadFacter in rehasting (%): ";
    cin >> loadFacter;
    cout << " (%)";
   
    list.loadFacterConfig(loadFacter / 100.00);
    double elapsedTime;
    int random;
int deleteIndex;
    // Define variables outside the loop
    chrono::high_resolution_clock::time_point start, end;
    do
    {
        cout << "\033[1;33m \n\n== CPE113 HASH TABLE 66044768 Saranphat Treepien ==  \033[0m\n\n\n";
        cout << "\n\n\033[1;33m+---------------------------------------------- HASH TABLE --------------------------------------------------+ \033[0m\n\n";
        cout << "\nLoadFacter is : " << loadFacter << " (%)" << endl
             << endl;
        list.display();
        // cout << "\n\nCurrent size of List : " << list.size() << " / " << SetMaxSize << endl;
        cout << "---------------------------------------- Menu \n"
             << "|  1.  |Insert Element In HashTable     |\n"
             << "|  2.  |Get Element in HashTable        |\n"
             << "|  3.  |Clear Data in Hashtable         |\n"
             << "|  4.  |Update MaxSize                  |\n"
             << "|  5.  |Delete element in Hashtable     |\n"
             << "|  6.  |Update MaxSize                  |\n"
             << "|  0.  |Exit                            |\n"
             << "-----------------------------------------\n";
        do
        {
            cout << "Enter choice : ";
            cin >> choice;
            if (choice <= 0 || cin.fail())
            {
                cin.clear();  // ล้างสถานะของ cin
                cin.ignore(); // ล้างค่าที่เหลือใน buffer
                cout << "Invalid input. Please enter a valid choice" << endl;
            }
        } while (choice <= 0 || cin.fail());
        switch (choice)
        {
        case 1:
            cout << "================= Inserting an element ============================\n";
            // เริ่มต้นจับเวลา
            start = chrono::high_resolution_clock::now();
            // โค้ดเพิ่มข้อมูลลงใน Hashtable ไปที่นี่
            random = ((rand() % 100)); // สุ่มเลขในช่วง 1 ถึง 999
            list.insert(random);
            cout << "Insert element in Hash Table is : " << random << endl;
            // หยุดจับเวลา
            end = chrono::high_resolution_clock::now();
            // คำนวณเวลาที่ใช้ (หน่วยเป็นมิลลิวินาที)
            elapsedTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            cout << "Time taken to insert: " << elapsedTime << " milliseconds" << endl;
            //! test correct!!
            // list.insert(3);
            // list.insert(22);
            // list.insert(27);
            // list.insert(40);
            // list.insert(80);
            // list.insert(100);
            waitForEnter();
            break;
        case 2:
            int getIndex;
            cout << "Get Element in HashTable by Index : ";
            cin >> getIndex ;
            cout << "Element in : " << getIndex  << " is : " << list.getData(getIndex);
            waitForEnter();
            break;
        case 3:
            cout << "Clear Data in HastTable : \n";
            list.clear();
            waitForEnter();
            break;
        case 4:
            cout << "Update maxSize : ";
            cin >> updateMaxSize;
            list.UpdateMaxSize(updateMaxSize);
            waitForEnter();
            break;
  case 5:
            cout << "Enter index to delete :  ";
            cin >> deleteIndex;
            list.deleteByIndex(deleteIndex);
            waitForEnter();
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            break;
        }
    } while (choice != 0);
    // List.insert(20);
    // List.insert(70);
    // List.insert(80);
    // List.insert(4);
    // List.insert(12);
    // List.insert(14);
    // List.insert(17);
    // List.insert(13);
    // List.insert(37);
    // List.display();
    return 0;
}
