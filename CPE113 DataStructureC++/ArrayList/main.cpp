#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "ArrayList.h" //include array list
using namespace std;   // add for standard library
void waitForEnter()
{
  cout << endl;
  cout << "Please enter to continue...";
  cin.ignore();
  cin.get();
  cout << "\x1B[2J\x1B[H";
}
// Function to check the execution time of a sorting algorithm
template <typename SortFunc>
double checkSortTime(ArrayList &list, SortFunc sortingFunction)
{
  auto start = chrono::high_resolution_clock::now(); // Start the timer

  (list.*sortingFunction)(); // Execute the sorting function

  auto end = chrono::high_resolution_clock::now(); // End the timer

  // Calculate the elapsed time in milliseconds
  chrono::duration<double, milli> elapsed = end - start;
  return elapsed.count();
}

int main()
{
  // defalut 5
  // cout << "Size : "  << list.size() << endl;
  int SetMaxSize;
  double selectionSortTime, insertSortTime, bubbleSortTime, shellSortTime, mergeSortTime, quickSortTime;
  cout << "\n\n\033[1;33m == CPE113 Lab4 66044768 Saranphat Treepien ==  \033[0m\n";
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
    cout << "\n\n\033[1;33m+---------------------------------------------- ARRAY LIST --------------------------------------------------+ \033[0m\n\n";
    list.display();
    cout << "\n\n\033[1;33m+-----------------------------------------------------------------------------------------------------------+ \033[0m\n\n";
    cout << "Current size of array : " << list.size() << " / " << SetMaxSize << endl
         << endl;

    cout << "---------------------------------------- Menu \n"
         << "|  1.  |Add element with index              |\n"
         << "|  2.  |Find index by element               |\n"
         << "|  3.  |Search element by index             |\n"
         << "|  4.  |Set element at index                |\n"
         << "|  5.  |Remove element by index             |\n"
         << "|  6.  |Display array size                  |\n"
         << "|  7.  |Find maximum value in array         |\n"
         << "|  8.  |Find minimum value in array         |\n"
         << "|  9.  |Clear array data                    |\n"
         << "|  10. |Data is empty                       |\n"
         << "|  11. |Remove First index                  |\n"
         << "|  12. |Remove Last index                   |\n"
         << "|  13. |Remove Value index                  |\n"
         << "|  14. |Selection Sort   (1)                |\n"
         << "|  15. |Insert Sort      (2)                |\n"
         << "|  16. |Bubble Sort      (3)                |\n"
         << "|  17. |Shell  Sort      (4)                |\n"
         << "|  18. |Merge  Sort      (5)                |\n"
         << "|  19. |Quick  Sort      (6)                |\n"
         << "|  20. |Shuffle Sort    (AUX)               |\n"
         << "|  21. |Update MaxSize                      |\n"
         << "|  0.  |Exit                                |\n"
         << "-----------------------------------------\n"
         << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      int Index_add, Number_add, random;
      cout << "================= Add element with index ============================\n";
      // cout << "Enter you number add with index : ";
      // cin >> Index_add;
      // cout << "Enter you number add with array : ";
      // cin >> Number_add;
      //   list.add(Index_add, Number_add);
      srand(time(0));

      for (int i = 0; i < SetMaxSize; ++i)
      {
        int random = ((rand() % 999) + 1); // สุ่มเลขในช่วง 1 ถึง 999
        list.add(i, random);
      }
      waitForEnter();
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
    case 14:
      cout << "================= Selection Sort ============================" << endl;
      selectionSortTime = checkSortTime(list, &ArrayList::SelectionSort);
      cout << "Selection Sort Time: " << selectionSortTime << " milliseconds" << endl;
      waitForEnter();
      break;
    case 15:
      cout << "================= Insert Sort ============================" << endl;
      insertSortTime = checkSortTime(list, &ArrayList::InsertSort);
      cout << "Insert Sort Time: " << insertSortTime << " milliseconds" << endl;
      waitForEnter();
      break;
    case 16:
      cout << "================= Bubble Sort ============================" << endl;
      bubbleSortTime = checkSortTime(list, &ArrayList::BubbleSort);
      cout << "Bubble Sort Time: " << bubbleSortTime << " milliseconds" << endl;
      waitForEnter();
      break;
    case 17:
      cout << "================= Shell Sort ============================" << endl;
      shellSortTime = checkSortTime(list, &ArrayList::shellSort);
      cout << "Shell Sort Time: " << shellSortTime << " milliseconds" << endl;
      waitForEnter();
      break;
    case 18:
      cout << "================= Merge Sort ============================" << endl;
      mergeSortTime = checkSortTime(list, &ArrayList::merge);
      cout << "Merge Sort Time: " << mergeSortTime << " milliseconds" << endl;
      waitForEnter();
      break;
    case 19:
      cout << "================= Quick Sort ============================" << endl;
      quickSortTime = checkSortTime(list, &ArrayList::quick);
      cout << "Quick Sort Time: " << quickSortTime << " milliseconds" << endl;
      waitForEnter();
      break;
    case 20:
      cout << "================= shuffle Sort ============================" << endl;
      list.shuffle(); //! สุ่มกระจาย e ใน index เพื่อทดสอบการ sort
      waitForEnter();
      break;
    case 21:
      cout << "================= UPDATE MAXSIZE ============================" << endl;
      int newMaxSize;
      cout << "Enter new maxSize of Array ";
      cin >> newMaxSize;
      list.updateMaxSie(newMaxSize);
      SetMaxSize = newMaxSize;
      cout << "Max size updated to: " << newMaxSize << endl;
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

  return 0; // destructordfsf
}
