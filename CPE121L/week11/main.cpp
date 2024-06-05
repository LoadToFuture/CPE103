#include <iostream>
using namespace std;
#include "class/FaMa/FaMa.h"
#include <iomanip>
#define N 10
void waitForEnter2();
int main()
{
    cout << "\n\n\033[1;33mCPE 122 Lab Week 12 66044768 Saranphat Treepien\033[0m\n";
    cout << "---------------------------------------------------------------------------\n";
    FaMa baby[N];
    int count = 0;
    char choice;
    cout << "**** Enter Information ****\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << "              Person : " << i + 1 << endl;
        baby[i].set_info();
        count++;
        while (true)
        {
            cout << "Enter another (\033[1;32mFather\033[0m/ or \033[1;31mMoter\033[0m) (Y/N)? : ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
                break;
            else if (choice == 'N' || choice == 'n')
                break; // ออกจากลูป for
            else
                cout << "Please enter 'y' or 'n'." << endl;
        }
        waitForEnter2();
        if (choice == 'N' || choice == 'n')
        {
            cout << "\nPerson = " << count << endl;
            cout << "----------------------------------------------------------------------- \n";
            break; // ออกจากลูป for
        }
    }
    cout << "\033[1;33m                                              **** Display Information ****  \033[0m\n";
    for (int i = 0; i < count; i++)
    {
        cout << "Person : " << i + 1 << endl;
        baby[i].get_info();
        cout << endl;
        cout << "----------------------------------------------------------------------- \n";
    }

    return 0;
}
void waitForEnter2()
{
    cout << "Please press Enter to continue...";
    // ใช้ตัวแปรชั่วคราวเพื่ออ่านค่าตัวอักษรจากผู้ใช้
    char ch;
    // วนรอให้ผู้ใช้กดปุ่ม Enter
    while (cin.get(ch))
    {
        if (ch == '\n')
        {          // ถ้าผู้ใช้กดปุ่ม Enter
            break; // ออกจากลูป
        }
    }
    // ล้างหน้าจอ
    cout << "\x1B[2J\x1B[H";
}