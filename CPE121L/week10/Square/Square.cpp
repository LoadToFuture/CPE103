#include "Square.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

float Square::get_width()
{
    return width;
}

void Square::cal_area(float get_width)
{
 if (area > 0) cout << area << endl;
    width = get_width;
    area = (pow(width, 2));
}

















