#include <iostream>
#include "FastLinkedQueue.h"
using namespace std;

void waitForEnter()
{
    cout << endl;
    cout << "Please press enter to continue...";
    cin.ignore();
    cin.get();
    cout << "\x1B[2J\x1B[H";
}
int main()
{
    int maxSize, choice;
    cout << "Welcome to FastLinkedQueue" << endl;
    do
    {
        cout << "Enter the maximum size of the queue: ";
        cin >> maxSize;
        if (maxSize <= 0 || cin.fail())
        {
            cin.clear();  // ล้างสถานะของ cin
            cin.ignore(); // ล้างค่าที่เหลือใน buffer
            cout << "Invalid input. Please enter a valid Maxsize" << endl;
        }
    } while (maxSize <= 0 || cin.fail());
    FastLinkedQueue list(maxSize);
    do
    {
        cout << "Current size of queue: " << list.size() << " / " << maxSize << endl;
        list.display();
        cout << "---------------------- Menu ----------------------" << endl;
        cout << "|  1. Enqueue or append                           |" << endl;
        cout << "|  2. Dequeue or remove                           |" << endl;
        cout << "|  3. Front or head                               |" << endl;
        cout << "|  4. Rear or back                                |" << endl;
        cout << "|  0. Exit                                        |" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        //     // int value;
        //     //  cout << "Enter the value to enqueue: ";
        //     //  cin >> value;
        //     srand(time(0));
        //    // for (int i = 0; i < maxSize; i++)
        //         list.enQueue((rand() % 100) + 1);
        //     waitForEnter();
 list.enQueue(10);
 list.enQueue(20);
 list.enQueue(30);
 list.enQueue(40);
 list.enQueue(50);
 list.enQueue(list.remove( ));
            break;
        case 2:
          //  char response;
            cout << "Dequeued value: " << list.dequeue() << endl;
            cout << " Did you think it was a good idea to delete it? \n";
            // cout << " Please Y if you confirm and  N if you not delete :  ";
          //  cin >> response;
            // if (response == 'Y' || response == 'y')
            // {
            //     cout << "DeQueue is " << list.dequeue() << endl;
            // }
            // else
            // {
            //     cout << "DeQueue canceled.\n";
            // }
            waitForEnter();
            break;
        case 3:
            cout << "Front value: " << list.front() << endl;
            waitForEnter();
            break;
        case 4:
            cout << "Rear value: " << list.rear() << endl;
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
