#include <iostream>
#include "BinarySearchTree/BinarySearchTree.h"
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
    BinarySearchTree bst;
    int Choice, Element;

    do
    {
        cout << "\x1B[2J\x1B[H";
        cout << endl;
        bst.display();
        cout << endl;
        cout << "================= Menu =================" << endl;
        cout << endl;
        cout << "[1] Insert" << endl;
        cout << "[2] Remove" << endl;
        cout << "[0] Exit" << endl;
        cout << endl;
        cout << "=======================================" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> Choice;
        cout << endl;
        switch (Choice)
        {
        case 1:
            cout << "\x1B[2J\x1B[H";
            cout << "> Insert" << endl;
            cout << endl;
            cout << "Enter element to insert: ";
            cin >> Element;
            bst.add(Element);
            cout << endl;
            cout << "================ result ================" << endl;
            cout << endl;
            cout << "Success" << endl;
            cout << endl;
            cout << "=======================================" << endl;
            waitForEnter();
            break;
        case 2:
            cout << "\x1B[2J\x1B[H";
            cout << "> remove" << endl;
            cout << endl;
            cout << "Enter element to remove: ";
            cin >> Element;
            bst.remove(Element);
            cout << endl;
            cout << "================ result ================" << endl;
            cout << endl;
            cout << "Success" << endl;
            cout << endl;
            cout << "=======================================" << endl;
            waitForEnter();
            break;
        case 0:cout << "\x1B[2J\x1B[H";
            cout << "================ result ================" << endl;
            cout << endl;
            cout << "Goodbye!" << endl;
            cout << endl;
            cout << "=======================================" << endl;
        default:
            break;
        }
    } while (Choice != 0);

    return 0;
}