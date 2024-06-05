#include <iostream>

#include "ArrayStack.h"
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
    ArrayStack Stack;
    int Choice,Element,MS;
    cout << "\x1B[2J\x1B[H";
    
    do
    {
        cout << "Enter max size of stack : ";
        cin >> MS;
        cout << endl;
        if (MS <= 0)
        {
            cout << "================ result ================" << endl;
            cout << endl;
            cout << "Invalid max size." << endl;
            cout << endl;
            cout << "======================================" << endl;
            waitForEnter();
        }
        else
        {
            Stack.setMaxSize(MS);
        }
    } while (MS <= 0);
    cout << "\x1B[2J\x1B[H";
    do
    {
        Stack.display();
        cout << endl;
        cout << "[1] Push" << endl;
        cout << "[2] Pop" << endl;
        cout << "[3] Top / Peek" << endl;
        cout << "[4] Swap Top" << endl;
        cout << "[5] Set Max Size" << endl;
        cout << "[0] Exit" << endl;

        cout << endl;
        cout << "Enter your choice : ";
        cin >> Choice;

        cout << endl;
        switch (Choice)
        {
            case 1:
            {
                
                if (Stack.isFull())
                {
                    cout << "================ result ================" << endl;
                    cout << endl;
                    cout << "Stack is full." << endl;
                    cout << endl;
                    cout << "======================================" << endl;
                    waitForEnter();
                    break;
                }
                cout << "======================================" << endl;
                cout << endl;
                
                cout << "Enter element : ";
                cin >> Element;

                Stack.push(Element);

                cout << endl;
                cout << "================ result ================" << endl;
                cout << endl;
                cout << "Pushed " << Element << " into stack." << endl;

                cout << endl;
                cout << "======================================" << endl;
                waitForEnter();
                break;
            }
            case 2:
            {

                if (Stack.isEmpty())
                {
                    cout << "================ result ================" << endl;
                    cout << endl;
                    cout << "Stack is empty." << endl;
                    cout << endl;
                    cout << "======================================" << endl;
                    waitForEnter();
                    break;
                }

                cout << "================ result ================" << endl;
                cout << endl;
                cout << "Popped " << Stack.pop() << " from stack." << endl;

                cout << endl;
                cout << "======================================" << endl;
                waitForEnter();
                break;
            }
            case 3:
            {
                if (Stack.isEmpty())
                {
                    cout << "================ result ================" << endl;
                    cout << endl;
                    cout << "Stack is empty." << endl;
                    cout << endl;
                    cout << "======================================" << endl;
                    waitForEnter();
                    break;
                }
                cout << "================ result ================" << endl;
                cout << endl;
                cout << "Top is " << Stack.top() << "." << endl;
                cout << "Peek is " << Stack.peek() << "." << endl;

                cout << endl;
                cout << "======================================" << endl;
                waitForEnter();
                break;
            }
            case 4:
            {
                if (Stack.isEmpty())
                {
                    cout << "================ result ================" << endl;
                    cout << endl;
                    cout << "Stack is empty." << endl;
                    cout << endl;
                    cout << "======================================" << endl;
                    waitForEnter();
                    break;
                }
                cout << "================ result ================" << endl;
                cout << endl;
                Stack.swapTop();
                cout << "Swapped top of stack." << endl;

                cout << endl;
                cout << "======================================" << endl;
                waitForEnter();
                break;
            }
            case 5:
            {
                cout << "======================================" << endl;
                cout << endl;
                cout << "Enter max size of stack : ";
                cin >> MS;
                cout << endl;
                if (MS <= 0 || MS < Stack.size())
                {
                    cout << "================ result ================" << endl;
                    cout << endl;
                    cout << "Invalid max size." << endl;
                    cout << endl;
                    cout << "======================================" << endl;
                    waitForEnter();
                }
                else
                {
                    cout << "================ result ================" << endl;
                    cout << endl;
                    cout << "Max size of stack is set to " << MS << "." << endl;
                    cout << endl;
                    cout << "======================================" << endl;
                    Stack.setMaxSize(MS);
                }
                cout << endl;
                waitForEnter();
                break;
            }
            case 0:
            {
                cout << "================ result ================" << endl;
                cout << endl;
                cout << "Exiting program." << endl;
                cout << endl;
                cout << "======================================" << endl;
                waitForEnter();
                break;
            }
            default:
            {
                if (Choice != 0)
                {
                    cout << "================ result ================" << endl;
                    cout << endl;
                    cout << "Invalid choice." << endl;
                    cout << endl;
                    cout << "======================================" << endl;
                    waitForEnter();
                }
                break;
            }

        }
    } while (Choice != 0);

    
    return 0;
}