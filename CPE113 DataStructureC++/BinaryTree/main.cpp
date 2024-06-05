#include <iostream>
using namespace std;
#include "BinaryTreeSearch/BinaryTreeSearch.h"
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
  BinaryTreeSearch tree;
  // สร้างโหนดรากของต้นไม้
  int choice;
  do
  {
    tree.displayBNT();
    cout << "---------------------- Menu ----------------------"  << endl;
    cout << "|  1. Insert in tree                              |" << endl;
    cout << "|  2. Remove in tree                              |" << endl;
    cout << "|  3.                                             |" << endl;
    cout << "|  4.                                             |" << endl;
    cout << "|  0. Exit                                        |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << " Insert in Tree \n";
      tree.insert(tree.root, 20); //! root
      tree.insert(tree.root, 20); //! root
      tree.insert(tree.root, 40); //! right
      tree.insert(tree.root, 10);  //! right
      tree.insert(tree.root, 6);
      tree.insert(tree.root, 15);
      tree.insert(tree.root, 2);
      tree.insert(tree.root, 8);
      tree.insert(tree.root, 30);
      tree.insert(tree.root, 25);
      cout << "\n\n";
      break;
    case 2:
      cout << " Remove in Tree \n";
      int number;
      cout << "Enter number Delete :  ";
      cin >> number;
      tree.remove(number);
      waitForEnter();
      break;
    case 3:
      cout << " Get in Tree \n";
      waitForEnter();
      break;
    case 4:

      waitForEnter();
      break;
    case 0:
      cout << "Exiting program. Goodbye!" << endl;
      break;
    default:
      cout << "Invalid choice. Please enter a valid option." << endl;
    }
  } while (choice != 0);
  // tree.insert(tree.root, 20); //! root
  // tree.insert(tree.root, 40); //! right
  // tree.insert(tree.root, 10); //! right
  // tree.insert(tree.root, 6);
  // tree.insert(tree.root, 15);
  // tree.insert(tree.root, 2);
  // tree.insert(tree.root, 8);
  // tree.insert(tree.root, 30);
  // tree.insert(tree.root, 25);
  // tree.displayBNT();
  // เรียกใช้งานฟังก์ชัน remove เพื่อลบโหนดที่มีค่าเท่ากับ 20 ออกจากต้นไม้
  // tree.remove(20);
  // cout << "After remove : \n";
  // แสดงผลข้อมูลในต้นไม้ BST ด้วย In-order traversal
  // tree.displayBNT();
  //   // เรียกใช้งานฟังก์ชัน deleteDegree เพื่อลบโหนดที่มีค่าเท่ากับ 20 ออกจากต้นไม้
  //   // แสดงผลข้อมูลในต้นไม้ BST ด้วย In-order traversal
  //   // tree.displayBNT();
  //   cout << endl; // เพิ่มบรรทัดใหม่หลังจากที่แสดงผลลัพธ์เสร็จสิ้น
  return 0;
}
