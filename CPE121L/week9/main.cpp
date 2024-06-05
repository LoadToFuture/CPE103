#include <iostream>
using namespace std;
#include "../week9-1/Area.h"
#include "../week9-1/Squre.h"
#include "../week9-1/Circle.h"
#include <ctime>
#include <math.h>
#include <iomanip>
#define N 10

void displayCircles(Circle ObjectsA[], int count);
void displaySquares(Square ObjectsB[], int count2);
void waitForEnter();
int main()
{
    cout << "+--------------------------------------------------------------------+\n";
    cout << "CPE 122 Lab Week 9 66044768 Saranphat Treepien\n";
    Circle ObjectsA[N];
    Square ObjectsB[N];
    float radius, width;
    char choice;
    int count = 0;
    int count2 = 0;
    cout << " \n\n\n !! Do you want start here...  !!\n\n";
    waitForEnter();
    srand(time(0));
    cout << "+--------------------------------------------------------------------+\n";
    cout << "\n1 . Class Circle \n\n";
    // cout << " \n\n !! Do you want Enter radius here...  !! \n\n";
    for (int i = 0; i < N; i++)
    {
        // do
        // {
        //     cout << "Class Circle " << i + 1 << ": ";
        //     cin >> radius;
        //     if (radius <= 0 || cin.fail())
        //     {
        //         cin.clear();  // ล้างสถานะของ cin
        //         cin.ignore(); // ล้างค่าที่เหลือใน buffer
        //         cout << "Invalid input!!. Please enter a radius circle again :" << endl;
        //     }
        // } while (radius <= 0 || cin.fail());
        // ObjectsA[i].set_radius(radius);
        radius = (rand() % 100) + 1;
        cout << "Class Circle " << i + 1 << ": " << radius << endl;
        ObjectsA[i].set_radius(radius);
        ObjectsA[i].cal_area();
        count++;
        if (i == N - 2)
            cout << "\n\nLast input \n\n";
        if (i != N - 1)
        {
            while (true)
            {
                cout << "Enter another Circle (y/n) ? : ";
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
    }
    cout << "+--------------------------------------------------------------------+\n";
    cout << "\n2 . Class Square \n\n";
    cout << " \n\n !! Do you want Enter Width here...  !! \n\n";
    waitForEnter();
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
        width = (rand() % 100) + 1;
        cout << "Class Square " << i + 1 << ": " << width << endl;
        ObjectsB[i].cal_area(width);
        count2++;
        if (i == N - 2)
            cout << "\n\nLast input \n\n";
        if (i != N - 1)
        {
            while (true)
            {
                cout << "Enter another Circle (y/n) ? : ";
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
    }
    cout << "+--------------------------------------------------------------------+\n";
    displayCircles(ObjectsA, count);
    displaySquares(ObjectsB, count2);
    return 0;
}
void displayCircles(Circle ObjectsA[], int count)
{
    cout << "\n\nNumber of Circles: " << count << endl
         << endl;
    for (int i = 0; i < count; i++)
        cout << left << std::setw(5) << "Circle " << std::setw(3) << i + 1 << ": Radius = " << std::setw(10) << ObjectsA[i].get_radius() << ", Area = " << std::setw(3) << std::fixed << std::setprecision(2) << ObjectsA[i].get_area() << std::endl;
}
void displaySquares(Square ObjectsB[], int count2)
{
    cout << "\n\nNumber of Squares: " << count2 << endl
         << endl;
    for (int i = 0; i < count2; i++)
        cout << left << std::setw(5) << "Square " << std::setw(3) << i + 1 << ": Width = " << std::setw(10) << ObjectsB[i].get_width() << ", Area = " << std::setw(3) << std::fixed << std::setprecision(2) << ObjectsB[i].get_area() << std::endl;
    cout << endl;
}
void waitForEnter()
{
    cout << "Please enter to continue...";
    cin.ignore();
    cin.get();
    cout << "\x1B[2J\x1B[H";
}