#include <iostream>
using namespace std;
#include "LinkedStack.h"
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
}
int main()
{
    int SetMaxSize;
    int choice;

    SetMaxSize = getValueInvalid();
    LinkedStack list(SetMaxSize);
    do
    {
        cout << "\033[1;33m \n\n== CPE113 LinkedStack 66044768 Saranphat Treepien ==  \033[0m\n\n\n";
        cout << "\n\n\033[1;33m+---------------------------------------------- Linked STACK --------------------------------------------------+ \033[0m\n\n";
        cout << "\033[1;33m                                           ----- List is -----                          \033[0m\n\n";
        list.StackDisplay();
        cout << "\n\nMax size in list :" << SetMaxSize << endl;
        cout << "\n\nCurrent size of List : " << list.size() << " / " << SetMaxSize << endl;
        cout << "---------------------------------------- Menu \n"
             << "|  1.  |Push Stack                      |\n"
             << "|  2.  |Auto Push Stack                 |\n"
             << "|  3.  |Pop Stack                       |\n"
             << "|  4.  |Top or Peek Stack               |\n"
             << "|  5.  |Update MaxSize by user          |\n"
             << "|  6.  |Is Empty                        |\n"
             << "|  7.  |Is Full                         |\n"
             << "|  8.  |Clear Data                      |\n"
             << "|  9.  |Swab Last And BeforLast         |\n"
             << "|  10. |Swap First And Last             |\n"
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
            cout << " PUSH Stack\n";
            // int Push_element;
            // cout << "================= PUSH Stack element ============================\n";
            // cout << "Enter you number add with array : ";
            // cin >> Push_element;
            srand(time(0));
            list.push((rand() % 100) + 1);
            waitForEnter();
            break;
        case 2:
            char AutoPush_element;
            cout << "================= Push Stack elements automatically ============================" << endl;
            cout << "This will add elements automatically to the list. Continue? (Y/N): ";
            cin >> AutoPush_element;
            if (AutoPush_element == 'Y' || AutoPush_element == 'y')
            {
                srand(time(0));
                for (int i = 0; i < SetMaxSize; ++i)
                {
                    list.push((rand() % 100) + 1);
                }
                cout << "Push element successfully." << endl;
            }
            else
            {
                cout << "Push element is canceled." << endl;
            }
            waitForEnter();
            break;
        case 3:
            cout << "================= Pop Stack elements automatically ============================" << endl;
            int Pop_element;
            Pop_element = list.pop();
            cout << "Pop element is : " << Pop_element << endl;
            waitForEnter();
            break;
        case 4:
            cout << "================= Top Stack elements automatically ============================" << endl;
            int Top_element;
            Top_element = list.top();
            cout << "Top element is : " << Top_element << endl;
            waitForEnter();
            break;
        case 5:
            int newMaxSize;
            cout << "Enter new Max size of array: ";
            cin >> newMaxSize;
            list.UpdateMaxSize(newMaxSize);
            SetMaxSize = newMaxSize;
            cout << "Max size updated to: " << newMaxSize << endl;
            break;
            waitForEnter();
        case 6:
            cout << "================= Check Empty Stack ============================" << endl;

            if (list.isEmpty() == true)
                cout << " List is empty!!";
            else
                cout << "List is Not Empty !! ";
            waitForEnter();
            break;
        case 7:
            cout << "================= Check list full Stack ============================" << endl;
            if (list.isFull() == true)
                cout << " List is FULL!!";
            else
                cout << "List is Not FULL !! ";
            waitForEnter();
            break;
        case 8:
            cout << "================= Clear Data ============================" << endl;
            list.clearList();
            waitForEnter();
            break;
        case 9:
            cout << "================= Swap Last and BeforLast Data ============================" << endl;
            list.swap01();
            waitForEnter();
            break;
          case 10:
            cout << "================= Swap Fists and Last Data ============================" << endl;
            list.swap02();
            waitForEnter();
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            break;
        }
    } while (choice != 0);
    //! test System
    // list.display();
    // list.push(1);
    // list.push(8);
    // list.push(5);
    // list.push(9);
    // cout << "TOP : " << list.top() << endl; //! 9

    // list.display();
    // int A = list.pop();
    // int B = list.pop();
    // list.display();
    // cout << "TOP : " << list.top() << endl; //! 8
    // cout << "Pop 1 : " << A << endl;
    // cout << "Pop 2 : " << B << endl;
    // list.display();
    // list.push(A);
    // list.display();
    // list.push(B);
    // list.display();
    // cout << "TOP : " << list.top() << endl; //! 9

    return 0;
}