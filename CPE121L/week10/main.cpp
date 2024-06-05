#include <iostream>
using namespace std;
#include "Area/Area.h"
#include "Square/Square.h"
#include "Circle2/Circle2.h"
#include <ctime>
#include <math.h>
#include <iomanip>
#include <random>
#define N 10

void waitForEnter();
int main()

{
    cout << endl;
    cout << "\033[1;33mCPE 122 Lab Week 11 66044768 Saranphat Treepien\033[0m\n";
    Circle2 ObjectsA[N];
    Square ObjectsB[N];
    float radius, width;
    char choice;
    int count = 0;
    int count2 = 0;
    cout << " \n\n\n \033[1;33m !! Do you want start here...  !!\033[0m\n\n";
    waitForEnter();
    srand(time(0));
    cout << "\033[1;33m +-----------------------------------------------------------------------+\n";
    cout << "                               1.Class Circle\033[0m\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << "Class Circle " << i + 1 << ": ";
        cin >> radius;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!! Radius not a number." << endl;
            i--;
            continue;
        }
        ObjectsA[i].set_radius(radius);
        ObjectsA[i].cal_area();
        count++;
        if (i == N - 2)
            cout << "\n\n\033[1;31mLast input \033[0m\n\n";
        if (i != N - 1)
        {
            while (true)
            {
                cout << "Enter another Circle (\033[1;32my\033[0m/\033[1;31mn\033[0m) ? : ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                    break;
                else if (choice == 'N' || choice == 'n')
                    break;
                else
                    cout << "Please enter 'y' or 'n'." << endl;
            }
        }
        if (choice == 'N' || choice == 'n')
        {
            cout << "\nCircle OBJ = " << count << endl;
            break; // ออกจากลูป for
        }
        cout << endl;
    }
    waitForEnter();
    cout << "\033[1;33m+----------------------------------------------------------------------+\n\n";
    cout << "                                  2 . Class Square \033[0m\n";
    random_device rd;
    mt19937 gen(rd());
    auto dis = uniform_real_distribution<>(1, 100);
    for (int i = 0; i < N; i++)
    {
        // do
        // {
        //     cout << "Class Square " << i + 1 << ": ";
        //     cin >> width;
        //     if (width <= 0 || cin.fail())
        //     {
        //         cin.clear();  // ล้างสถานะของ cin
        //         cin.ignore(); // ล้างค่าที่เหลือใน buffer
        //         cout << "Invalid input!!. Please enter a width Square again :" << endl;
        //     }
        // } while (width <= 0 || cin.fail());
        width = dis(gen);
        cout << "Class Square " << i + 1 << ": " << width << endl;
        ObjectsB[i].cal_area(width);
        count2++;
        if (i == N - 2)
            cout << "\n\n\033[1;31mLast input \033[0m\n\n";
        if (i != N - 1)
        {
            while (true)
            {
                cout << "Enter another Squre (\033[1;32my\033[0m/\033[1;31mn\033[0m) ? : ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                    break;
                else if (choice == 'N' || choice == 'n')
                    break; // ออกจากลูป for
                else
                    cout << "Please enter 'y' or 'n'." << endl;
            }
        }
        if (choice == 'N' || choice == 'n')
        {
            cout << "\nSquere OBJ = " << count2 << endl;
            break; // ออกจากลูป for
        }
        cout << endl;
    }
    cout << "\033[1;33m+--------------------------------------------------------------------+\n";
    cout << "                              Display    \033[0m\n";
    cout << "\033[1;33m\n\n-------------------           CIRCLE2           ----------------------------\033[0m\n";
    cout << "\n\nNumber of Circles: " << count << endl
         << endl;
    //!----------------------------------------------- CIRCLE2
    for (int i = 0; i < count; i++)
        cout << left << setw(5) << "Circle is :" << setw(3) << i + 1 << fixed << setprecision(2) << "Radius is : " << setw(10)
             << ObjectsA[i].get_radius() << "  Area is : " << setw(3) << fixed << setprecision(2) << ObjectsA[i].get_area()
             << endl;
    //!----------------------------------------------- SQUARE
    cout << "\033[1;33m\n\n-------------------           SQUARE           ----------------------------\033[0m\n";
    cout << "\n\nNumber of Squares: " << count2 << endl
         << endl;
    for (int i = 0; i < count2; i++)
    {
        //  cout << left << setw(5) << "Square is :" << setw(3) << i + 1 << "Width is : " << setw(10)
        //      << ObjectsB[i].get_width() << "  Area is : " << setw(3) << fixed << setprecision(2)
        //  <<    ObjectsB[i].get_width()* ObjectsB[i].get_width() ;
        // cout << endl;

        cout << left << setw(5) << "Square is :" << setw(3) << i + 1 << "Width is : " << setw(10)
             << ObjectsB[i].get_width() << "  Area is : " << setw(3) << fixed << setprecision(2);
        ObjectsB[i].cal_area(ObjectsB[i].get_width());
    }
    cout << "\033[1;33m\n\n------------------- Good bye ----------------------------\033[0m\n\n";
    return 0;
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
    cout << "\x1B[2J\x1B[H";
}

//    for (int i = 0; i < count2; i++)
//     {
//         cout << left << setw(5) << "Square is :" << setw(3) << i + 1 << "Width is : " << setw(10)
//              << ObjectsB[i].get_width() << "  Area is : " << setw(3) << fixed << setprecision(2);
//              ObjectsB[i].cal_area(ObjectsB[i].get_width());
//     }