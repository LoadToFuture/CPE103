#include "circle.h"
#include<iomanip>
const int N = 2;
int main()
{
    CIRCLE circle[N];
    double r;
    cout << "Class Circle \n";
    for (int i = 0; i < N; i++)
    {
        cout << "Enter Radius Circle " << static_cast<char>('A' + i) << " : ";
        cin >> r;
        if (!(cin.good()))
        {
            cout << "Invalid input. Please enter a numeric value.\n";
            return 1;
        }
        circle[i].set_radius(abs(r));
    }
     cout << fixed << setprecision(3);
    for (int i = 0; i < N; i++)
        cout << "Circle ( " << static_cast<char>('A' + i) << " ): "
             << "Radius is : "<<circle[i].get_radius()
             << " Area is : " << circle[i].get_area()
             << " Volume is : "  << circle[i].cal_volume_circle()
             << " Mass is :  "  << circle[i].MassWater()
             << " Pressure is : " << circle[i].pressure() << endl;
}