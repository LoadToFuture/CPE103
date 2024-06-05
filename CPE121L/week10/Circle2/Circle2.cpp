#include "Circle2.h"
#include <iostream>
using namespace std;

void Circle2::set_radius(float get_radius2)
{

  if (get_radius2 < 0 || get_radius2 > 99 || cin.fail())
  {
    do
    {
      cin.clear();                                         // ล้างสถานะของ cin
      cin.ignore(); // ล้างค่าที่เหลือใน buffer
      cout << "Invalid input!!. Please enter a valid radius between 0 and 99." << endl;
      cout << "Class Circle again : ";
      cin >> get_radius2;
    } while (get_radius2 < 0 || get_radius2 > 99 || cin.fail());
  }
  Circle::set_radius(get_radius2);
}
