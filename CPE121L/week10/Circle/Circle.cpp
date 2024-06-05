#include "Circle.h"
#include <iostream>
#include <math.h>
void Circle::set_radius(float get_radius)
{
    radius = get_radius;
}

float Circle::get_radius()
{
    return radius;
}

void Circle::cal_area()
{
    set_area(M_PI * pow(radius, 2));
}