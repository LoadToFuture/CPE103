#include <iostream>

#include "LinkedList.h"
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
    LinkedList list; // constructor
    // fn => dummy => [0:10] => [1:20] => [2:20] => [3:30] => NULL
    cout << "== CPE113 Lab5 66044768 Saranphat Treepien == \n";
    int choice;
    do
    {
        cout << "-----------------------------------------------------\n";
        list.display();
        cout << "Current size of array : " << list.size() << endl;
        cout << "------------------------------------------ Menu \n"
             << " |  1.  | Add element with index          |\n"
             << "-----------------------------------------\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // fn => dummy => [0:10] => [1:20] => [2:20] => [3:30] => NULL
            int Index_add, Number_add;
            cout << "================= Add element with index ============================\n";
            // cout << "Enter you number add with index : ";
            // cin >> Index_add;
            // cout << "Enter you number add with array : ";
            // cin >> Number_add;
            // list.add(Index_add, Number_add);
            list.add(0, 7);
            list.add(1, 5);
            list.add(2, 7);
            list.add(3, 40);
            list.add(4, 7);
            list.add(3, 40);
            list.add(4, 7);
            list.add(3, 40);
            list.add(4, 100);
            cout << "Add success!! \n";
            waitForEnter();
            break;
       
        case 0:
            cout << "Exiting program. Goodbye!" << endl;

            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
        // list.display();
    } while (choice != 0);

    return 0; // destructor
}
