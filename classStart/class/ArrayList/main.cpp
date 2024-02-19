#include <iostream>
#include <iomanip>
#include "ArrayList.h" //include array list
using namespace std;   // add for standard library
int main()
{
  // defalut 5
  // cout << "Size : "  << list.size() << endl;
  int SetMaxSize;
  cout << "== CPE113 Lab4 66044768 Saranphat Treepien == \n";
  cout << "Enter Max size of array : ";
  cin >> SetMaxSize;
  if (SetMaxSize < 0)
  {
    SetMaxSize = -SetMaxSize;
  }
  else if (cin.fail())
  {
    cout << "Invalid value maxSize\n";
    return 0;
  }
  ArrayList list(SetMaxSize);
  cout << "Max size in array :" << SetMaxSize << endl;
  int choice;
  do
  {
    cout << "-----------------------------------------------------\n";
    list.display();
    cout << "Current size of array : " << list.size() << " / " << SetMaxSize << endl
         << endl;
    cout << "---------------------------------------- Menu \n"
         << "|  1.  |Add element with index          |\n"
         << "|  2.  |Find index by element           |\n"
         << "|  3.  |Search element by index         |\n"
         << "|  4.  |Set element at index            |\n"
         << "|  5.  |Remove element by index         |\n"
         << "|  6.  |Display array size              |\n"
         << "|  7.  |Find maximum value in array     |\n"
         << "|  8.  |Find minimum value in array     |\n"
         << "|  9.  |Clear array data                |\n"
         << "|  10. |Data is empty                   |\n"
         << "|  11. |Remove First index              |\n"
         << "|  12. |Remove Last index               |\n"
         << "|  13. |Remove value in array           |\n"
         << "|  0.  |Exit                            |\n"
         << "-----------------------------------------\n"
         << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      int Index_add, Number_add;
      cout << "================= Add element with index ============================\n";
      // cout << "Enter you number add with index : ";
      // cin >> Index_add;
      // cout << "Enter you number add with array : ";
      // cin >> Number_add;
      //   list.add(Index_add, Number_add);
      list.add(0, 10);
      list.add(1, 20);
      list.add(2, 30);
      list.add(3, 40);
      list.add(4, 50);

      break;
    case 2:
      int to_element, value;
      cout << "================= . Find index by element ============================" << endl;
      cout << "Enter number is you get index with element : ";
      cin >> to_element;
      value = list.indexOf(to_element);
      if (value == -1)
        cout << "Is not found this value in element : " << to_element << " = index " << -1 << endl;
      else
        cout << "Found this value in element " << to_element << " at index of " << value << endl;
      break;
    case 3:
      cout << "=================  Retrieve element by index ============================" << endl; ///
      int to_index;
      cout << "Enter index with get element: ";
      cin >> to_index;
      cout << "Element at index " << to_index << ": " << list.get(to_index) << endl;
      break;
    case 4:
      int index_set, element;
      cout << "================= Set element at index ============================" << endl;
      cout << "Set element of index is : ";
      cin >> index_set;
      cout << "Enter number you want to set : ";
      cin >> element;
      list.set(index_set, element);

      break;
    case 5:
      int index_remove, u;
      cout << "================= Remove element by index ============================" << endl;
      cout << "Enter index to remove : ";
      cin >> index_remove;
      u = list.remove(index_remove);
      cout << "is remove element : " << index_remove << endl;
      cout << "Success!! is remove element : " << u << endl;

      break;
    case 6:
      cout << "================= Size of array ============================" << endl;
      cout << "Size of array is : ";
      list.display();
      break;
    case 7:
      cout << "================= Maximum value in array ============================" << endl
           << "Maximum value of array is : " << list.maximum() << endl;
      break;
    case 8:
      cout << "================= Minimum value in array ============================" << endl
           << "Minimum value of array is : " << list.minimum() << endl;
      break;
    case 9:
      cout << "================= Clear data in array ============================" << endl;
      list.clearArray();
      // list.display();
      break;

    case 10:
      cout << "================= Data is empty ============================" << endl;
      list.dataIsEmpty();
      break;
    case 11:
      int removefirst;
      cout << "================= Remove First index ============================" << endl;
      cout << "Enter index to remove arrayfirst : ";
      cin >> removefirst;
      list.removefirst(removefirst);
      break;
    case 12:
      cout << "================= Remove Last indexy ============================" << endl;
      int removeLast;
      cout << "Enter index to remove last index: ";
      cin >> removeLast;
      list.removelast(removeLast);
      break;
    case 13:
      cout << "================= Remove value in array ============================" << endl;
      int removeValue;
      cout << "Enter index to remove value in array: ";
      cin >> removeValue;
      list.removeValue(removeValue);
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
