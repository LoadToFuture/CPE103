#include "circle.h"
#include <ctime>
#include <iomanip>
double getValueInvalid(); 

int main()
{
    CIRCLE circleA;
    double radius;
    cout << "CPE121L Lab6 Saranphat Treepien \n";
    cout << "Class Circle \n";
    radius = getValueInvalid();

    //! Generate random radius Circle C
    circleA.set_radius(radius / 100.00);
    srand(time(0));
    float randomCM = (rand() % 1000) + 1;
    CIRCLE circleB(circleA),circleC(randomCM / 100.00), circleD, circleE;
    circleE = circleC.ret_area_obj(circleB);
    //!Header 
    cout << "------------------------------------------------------------------------ \n"
         << "Change Centimeter TO Meter : " << radius << " (CM)  is : " << radius / 100.00 << " ( M )\n"
         << "Change Random Centimeter TO Meter : " << randomCM << " (CM)  is : " << randomCM / 100.00 << " ( M ) \n\n"


         << fixed << setprecision(2)
         << "Circle (A) Radius :                     " << circleA.get_radius() << "  (M) Area : " << circleA.get_area() << " Square meter\n"
         << "Circle (B) Radius :                     " << circleB.get_radius() << "  (M) Area : " << circleB.get_area() << " Square meter\n"
         << "Circle (C) Radius :                     " << circleC.get_radius() << "  (M) Area : " << circleC.get_area() << " Square meter\n"
         << "Circle (D) Radius : (A:" << circleA.get_radius() << " + C:" << circleC.get_radius() << ")   "
         << circleA.get_radius() + circleC.get_radius() << "  (M) Area : " << circleD.cal_area_obj(circleA, circleC) << " Square meter\n"
         << "Circle (E) Radius : (B:" << circleB.get_radius() << " + C:" << circleC.get_radius() << ")   "
         << circleB.get_radius() + circleC.get_radius() << "  (M) Area : " << circleE.get_area() << " Square meter\n";

    return 0;
}
double getValueInvalid()
{
    double radius;
    do
    {
        cout << "Enter radius A (CM): ";
        cin >> radius;
        if (radius <= 0 || cin.fail() || isalpha(radius))
        {
            cin.clear();                                         // ล้างสถานะของ cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ล้างค่าที่เหลือใน buffer
            cout << "Invalid input. Please enter a valid radius." << endl;
        }
    } while (radius <= 0 || cin.fail() || isalpha(radius));
    return radius;
}