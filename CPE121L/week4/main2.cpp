#include <iostream>
#include <math.h>
#include <iomanip>
#define N 5
using namespace std;

class Circle
{
private:
    float radius;
    float area;
public:
    void set_radius(float g_radius)
    {
        radius = g_radius;
        cal_area();
    }
    void cal_area()
    {
        area = M_PI * radius * radius;
    }
    float get_radius()
    {
        return radius;
    }
    float get_area()
    {
        return area;
    }
};

int main()
{
    Circle cir[N];
    float r;
    cout << "Class Circle \n";
    for (int i = 0; i < N; i++)
    {
        cout << "Enter Radius Circle " << static_cast<char>('A' + i) << ": ";
        cin >> r;
        cir[i].set_radius(r);
    }
    cout << "=================================================\n";
    for (int i = 0; i < N; i++)
    {
        cout << fixed << setprecision(2);
        cout << setw(5) << "Radius " << static_cast<char>('A' + i) << ": " << cir[i].get_radius()
             << setw(5) << " Area : " << cir[i].get_area() << "\n";
    }
    return 0;
}
