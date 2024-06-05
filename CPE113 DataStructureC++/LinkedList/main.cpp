#include <iostream>
#include "LinkedList.h"
#include <ctime>
using namespace std;
double getValueInvalid()
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
    // fn => dummy => [0:10] => [1:20] => [2:20] => [3:30] => NULL
    cout << "== CPE113 Lab5 66044768 Saranphat Treepien == \n";
    int choice, SetMaxSize;
    SetMaxSize = getValueInvalid();
    LinkedList list(SetMaxSize); // constructor
    do
    {
        cout << "Max size in array :" << SetMaxSize << endl;
        cout << "-----------------------------------------------------\n";
        list.display();
        cout << "Current size of array : " << list.size() << " / " << SetMaxSize << endl;
        cout << "------------------------------------------ Menu \n"
             << " |  1.  | Add element with index          |\n"
             << " |  2.  | Auto Add element with index     |\n"
             << " |  3.  | Find index by element           |\n"
             << " |  4.  | Search element by index         |\n"
             << " |  5.  | Set element at index            |\n"
             << " |  6.  | Remove element by index         |\n"
             << " |  7.  | Display array size              |\n"
             << " |------------  Other Function -----------|\n"
             << " |  8.  | OddCount()                      |\n"
             << " |  9.  | EvenCout()                      |\n"
             << " |  10. | Sum ()                          |\n"
             << " |  11. | Average ()                      |\n"
             << " |  12. | SortHightvalue()                |\n"
             << " |  13. | Max size in array               |\n"
             << " |  14. | Min size in array               |\n"
             << " |  15. | Clear array data                |\n"
             << " |  16. | RemoveFirst element by index    |\n"
             << " |  17. | RemoveLast element by index     |\n"
             << " |  18. | RemoveValue element by index    |\n"
             << " |  19. | Modify Max size of array        |\n"
             << " |  0.  | Exit                            |\n"
             << "-----------------------------------------\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // fn => dummy => [0:10] => [1:20] => [2:20] => [3:30] => NULL
            int Index_add, Number_add;
            char chk_add;
            cout << "================= Add element with index ============================\n";
            cout << "Enter you number add with index : ";
            cin >> Index_add;
            cout << "Enter you number add with array : ";
            cin >> Number_add;
            list.add(Index_add, Number_add);
            waitForEnter();
            break;
        case 2:
            char autoAddChoice;
            cout << "================= Add elements automatically ============================" << endl;
            cout << "This will add elements automatically to the list. Continue? (Y/N): ";
            cin >> autoAddChoice;
            if (autoAddChoice == 'Y' || autoAddChoice == 'y')
            {
                srand(time(0));
                for (int i = 0; i < SetMaxSize; ++i)
                {
                    list.add(i, (rand() % 100) + 1);
                }
                cout << "Elements added successfully." << endl;
            }
            else
            {
                cout << "Auto add canceled." << endl;
            }
            waitForEnter();
            break;
        case 3:
            int to_element, value;
            cout << "================= . Find index by element ============================" << endl;
            cout << "Enter number is you get index with element : ";
            cin >> to_element;
            value = list.indexOf(to_element);
            if (value == -1)
                cout << "Is not found this value in element : " << to_element << " = index " << -1 << endl;
            else
                cout << "\n\nFound this value in element " << to_element << " at index of " << value << endl;
            cout << endl
                 << endl;
            waitForEnter();
            break;
        case 4:
            cout << "=================  Get element by index ============================" << endl; ///
            int to_index;
            cout << "Enter index with get element: ";
            cin >> to_index;
            cout << "\n\nElement at index " << to_index << ": " << list.get(to_index) << endl
                 << endl;
            waitForEnter();
            break;
        case 5:
            int index_set, element;
            cout << "================= Set element at index ============================" << endl;
            do
            {
                cout << "Set element of index is : ";
                cin >> index_set;
                if (index_set > list.size() - 1 || index_set < 0 || cin.fail())
                {
                    cin.clear();  // ล้างสถานะของ cin
                    cin.ignore(); // ล้างค่าที่เหลือใน buffer
                    cout << "Invalid input. Please enter a valid Index" << endl;
                }
            } while (SetMaxSize <= 0 || cin.fail());

            cout << "Enter number you want to set : ";
            cin >> element;
            list.set(index_set, element);
            waitForEnter();
            break;
        case 6:
            int index_remove, u;
            cout << "================= Remove element by index ============================" << endl;
            cout << "Enter index to remove : ";
            cin >> index_remove;
            u = list.remove(index_remove);
            cout << "\n\nis remove element to index: " << index_remove << endl;
            if (u == 0)
                cout << "\n\nFail!! is remove element : " << u << endl
                     << endl;
            else
                cout << "\n\nSuccess!! is remove element : " << u << endl
                     << endl;
            waitForEnter();
            break;
        case 7:
            cout << "================= Size of array ============================" << endl;
            cout << "Size of array is : ";
            list.display();
            break;
        case 8:
            int odd;
            cout << "================= OddCount ============================" << endl;
            odd = list.oddCount();
            if (odd != 0)
                cout << "\nAmount Odd number in Linklist : " << odd << endl;
            else
                cout << "\nNot found!! odd number in Linklist \n";
            waitForEnter();
            break;
        case 9:
            int even;
            cout << "================= Even Count ============================" << endl;
            even = list.EvenCount();
            if (even != 0)
                cout << "\nAmount Even number in Linklist : " << even << endl;
            else
                cout << "\nNot found !! Even number in Linklist\n";
            waitForEnter();
            break;
        case 10:
            cout << "================= Sum  ============================" << endl;
            cout << "Sum in Linklist : " << list.sum() << endl;
            waitForEnter();
            break;
        case 11:
            double average;
            cout << "================= Average  ============================" << endl;
            average = list.Average();
            cout << "Average in Linklist : " << average << endl;
            waitForEnter();
            break;
        case 12:
            cout << "================= Sort  value in linklist  ============================" << endl;
            char choice;
            cout << "Hight: Y or Lower: N  : ";
            cin >> choice;
            cout << "Sort  in Linklist : ";
            list.sortvalue(choice);
            cout << endl;
            break;
        case 13:
            cout << "================= Maximum value in linklist ============================" << endl
                 << "Maximum value of linklist is : " << list.max() << endl;
            waitForEnter();
            break;
        case 14:
            cout << "================= Minimum value in linklist ============================" << endl
                 << "Minimum value of linklist is : " << list.min() << endl;
            waitForEnter();
            break;
        case 15:
            cout << "================= Clear array data  ============================" << endl;
            list.clearList();
            waitForEnter();
            break;
        case 16:
            cout << "================= Remove first element ============================" << endl;
            int removefirst;
            cout << "Enter index to remove First : ";
            cin >> removefirst;
            list.removeFirst(removefirst);
            waitForEnter();
            break;
        case 17:
            cout << "================= Remove Last element ============================" << endl;
            int removeLast;
            cout << "Enter index to remove Last : ";
            cin >> removeLast;
            list.removeLast(removeLast);
            waitForEnter();
            break;
        case 18:
            cout << "================= Remove Value in list ============================" << endl;
            int removeValue;
            cout << "Enter value to remove in List : ";
            cin >> removeValue;
            list.removeValue(removeValue);
            waitForEnter();
            break;
        case 19:
            int newMaxSize;
            cout << "Enter new Max size of array: ";
            cin >> newMaxSize;
            list.UpdateMaxSize(newMaxSize);
            SetMaxSize = newMaxSize;
            cout << "Max size updated to: " << newMaxSize << endl;
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
