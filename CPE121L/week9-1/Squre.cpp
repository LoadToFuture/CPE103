#include "Squre.h"
#include <iostream>
#include <math.h>

float Square::get_width()
{
    return width;
}

void Square::cal_area(float get_width)
{
    width = 0.00;
    width = get_width;
    area = pow(width, 2);
}