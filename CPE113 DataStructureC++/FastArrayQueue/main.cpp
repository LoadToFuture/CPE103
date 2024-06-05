#include <iostream>
#include "FastArrayQueue.h"
using namespace std;
void waitForEnter()
{
    cout << endl;
    cout << "Please enter to continue...";
    cin.ignore();
    cin.get();
    cout << "\x1B[2J\x1B[H";
}
int main()
{

    int SetMaxSize, choice;
    cout << " = CPE113 LAB FASTARRAYQUEUE =  \n 66044768 Saranphat Treepien\n\n";
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
    FastArrayQueue list(SetMaxSize);
    waitForEnter();
    do
    {

        cout << "Max size in array :" << SetMaxSize << endl;
        list.display();
        cout << "Current size of array : " << list.size() << " / " << SetMaxSize << endl;
        cout << "------------------------------------------- Menu\n"
             << " |  1.  | En Queue or append                   |\n"
             << " |  2.  | De QueueFront or removeFront         |\n"
             << " |  3.  | De QueueRear or removeRear           |\n"
             << " |  4.  | Front Queue or head                  |\n"
             << " |  5.  | Rear Queue or back                   |\n"
             << " |  6.  | Check Empty                          |\n"
             << " |  7.  | Clear Element                        |\n"
             << " |  8.  | Modify MaxSize                       |\n"
             << "----------------------------------------------\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // fn => dummy => [0:10] => [1:20] => [2:20] => [3:30] => NULL
            // int Index_add, Number_add;
            cout << "================= En QUEUE ============================\n";
            cout << "Enter you number add with index : ";
            // cin >> Index_add;
            // cout << "Enter you number add with array : ";
            // cin >> Number_add;
            // list.add(Index_add, Number_add);
            // srand(time(0));
            //   for (int i = 0; i < SetMaxSize; i++)
            list.enQueue((rand() % 100) + 1);
            cout << "Add success!! \n";
            waitForEnter();
            break;
        case 2:
            //  char response;
            cout << "================= De QUEUE ============================\n";
            cout << "DeQueue is " << list.deQueueFront() << endl;
            waitForEnter();
            break;
        case 3:
            cout << "================= Front Queue or head ============================\n";
            cout << "Rear Front is : " << list.deQueueRear() << endl;
            waitForEnter();
            break;
        case 4:
            cout << "================= Front Queue or head ============================\n";
            cout << "Rear Front is : " << list.front() << endl;
            waitForEnter();
            break;
        case 5:
            cout << "================= Rear Queue or head ============================\n";
            cout << "Rear queue is : " << list.rear() << endl;
            waitForEnter();
            break;
        case 6:
            cout << "================= Empty ============================\n";
            if (list.isEmpty() == 1)
                cout << " List is not Empty!! \n";
            else
                cout << " List is Empty!!\n";
            waitForEnter();
            break;
        case 7:
            cout << "================= Clear ============================\n";
            list.clear();
            waitForEnter();
            break;
        case 8:
              int newMaxSize;
            cout << "Enter new Max size of array: ";
            cin >> newMaxSize;
            list.UpdateMaxSize(newMaxSize);
            SetMaxSize = newMaxSize;
            cout << "Max size updated to: " << newMaxSize << endl;
               list.clear();
            waitForEnter();
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;

            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}