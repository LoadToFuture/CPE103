#include "ArrayStack.h"
#include <iostream>
#include <cctype>
using namespace std;
void waitForEnter()
{
    cout << endl;
    cout << "Please enter to continue...";
    cin.ignore();
    cin.get();
    cout << "\x1B[2J\x1B[H";
}
// int getValueInvalid()
// {
//     int SetMaxSize;
//     do
//     {
//         cout << "Enter Max size of array : ";
//         cin >> SetMaxSize;
//         if (SetMaxSize <= 0 || cin.fail())
//         {
//             cin.clear();  // ล้างสถานะของ cin
//             cin.ignore(); // ล้างค่าที่เหลือใน buffer
//             cout << "Invalid input. Please enter a valid Maxsize" << endl;
//         }
//     } while (SetMaxSize <= 0 || cin.fail());
//     return SetMaxSize;
// }

int main()
{
    int SetMaxSize, choice;
    string inputCal, infix, postfix, prefix;
    cout << "\n\n\033[1;33m == CPE113 ArrayStackApplication 66044768 Saranphat Treepien ==  \033[0m\n";
    //   SetMaxSize = getValueInvalid();
    ArrayStack stack(SetMaxSize = 100); // constuctor

    do
    {
        cout << "\n\n\033[1;33m+---------------------------------------------- ARRAY STACK --------------------------------------------------+ \033[0m\n\n";
        cout << "\033[1;33m                                           ----- APPLICATION -----                          \033[0m\n\n";
        stack.Stackdisplay();
        cout << "Max size in array :" << SetMaxSize << endl;
        cout << "\n\nCurrent size of array : " << stack.size() << " / " << SetMaxSize << endl;
        cout << "---------------------------------------- Menu \n"
             << "|  1.  |Push Stack                      |\n"
             << "|  2.  |Auto Push Stack                 |\n"
             << "|  3.  |Pop Stack                       |\n"
             << "|  4.  |Top and Peek Stark              |\n"
             << "|  5.  |Update MaxSize by user          |\n"
             << "|  6.  |Is Empty                        |\n"
             << "|  7.  |Is Full                         |\n"
             << "|  8.  |Clear Data                      |\n"
             << "|  9.  |Stack Application               |\n"
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
            stack.push((rand() % 100) + 1);
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
                    stack.push((rand() % 100) + 1);
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
            Pop_element = stack.pop();
            cout << "Pop element is : " << Pop_element << endl;
            waitForEnter();
            break;
        case 4:
            cout << "================= Top Stack elements automatically ============================" << endl;
            int Top_element;
            Top_element = stack.top();
            cout << "Top element is : " << Top_element << endl;
            waitForEnter();
            break;
        case 5:
            int newMaxSize;
            cout << "Enter new Max size of array: ";
            cin >> newMaxSize;
            stack.UpdateMaxSize(newMaxSize);
            SetMaxSize = newMaxSize;
            cout << "Max size updated to: " << newMaxSize << endl;
            break;
            waitForEnter();
        case 6:
            cout << "================= Check Empty Stack ============================" << endl;
            if (stack.isEmpty() == true)
                cout << " List is empty!!";
            else
                cout << "List is Not Empty !! ";
            break;
        case 7:
            cout << "================= Check list full Stack ============================" << endl;
            if (stack.isFull() == true)
                cout << " List is FULL!!";
            else
                cout << "List is Not FULL !! ";
            break;
        case 8:
            cout << "================= Clear Data ============================" << endl;
            stack.clearArray();
            break;
        case 9:
            cout << "================= Stack Application ============================" << endl;
            // cout << "Input calculater : ";
            // cin >> inputCal;
            // infix = "5+3";
            infix = "3+4*2"; // Example infix expression
                                   //   infix = inputCal;
            postfix = stack.infixToPostfix(infix);
            prefix = stack.infixToPrefix(infix);
            cout << "Infix : " << infix << endl;
            stack.displayConversionSteps(infix);
            stack.displayPostfixVertical(postfix);
            stack.displayPrefixVertical(prefix);
            cout << "Result: " << stack.postfixCalcutation(postfix) << endl
                 << endl;
            waitForEnter();

            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
    } while (choice != 0);

    return 0; // destructor
}
