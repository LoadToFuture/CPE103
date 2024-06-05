#include "GrandFa.h"
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;
void waitForEnter();
string randomFirstname();
string randomLastname();
void GrandFa::set_info()
{
    // fname = randomFirstname();
    cout << "Enter Grandfater first name : "; //<< fname;
    cin >> fname;
    cout << endl;
    waitForEnter();
    cout << endl;
    // lname = randomLastname();
    cout << "Enter Grandfater last name :  "; //<< lname;
    cin >> lname;
    cout << endl;
    waitForEnter();

    do
    {
        cout << "Enter Percentage of Thai nationality (25, 50, 75, 100 %): ";
        cin >> thai_percent;
        if (thai_percent == 25 || thai_percent == 50 || thai_percent == 75 || thai_percent == 100)
            break;
        else
            cout << "Invalid input! Please enter again." << endl;
    } while (true);
}

void GrandFa::get_info()
{
    cout << "Grandfather name : " << fname << " " << lname << endl;
    cout << "Thai nationality : " << thai_percent << endl
         << endl;
}
void waitForEnter()
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
    // cout << "\x1B[2J\x1B[H";
}
string randomFirstname()
{
    // List of possible first names
    vector<string> firstNames = {"Bob", "Charlie", "David", "Frank", "Ian"};
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));
    // Randomly select first and last names
    string firstName = firstNames[rand() % firstNames.size()];
    // Concatenate first name and last name with a space in between
    return firstName;
}
string randomLastname()
{
    // List of possible last names
    vector<string> lastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor"};
    string lastName = lastNames[rand() % lastNames.size()];
    return lastName;
}