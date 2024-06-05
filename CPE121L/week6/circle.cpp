#include "circle.h"
#include <math.h>

CIRCLE::CIRCLE() : radius(0.0), area(0.0) {}

CIRCLE::CIRCLE(double get_radius) : radius(get_radius)
{
    cal_area();
}
void CIRCLE::set_radius(double get_radius)
{
    radius = get_radius;
    cal_area();
}
double CIRCLE::get_radius()
{
    return radius;
}
void CIRCLE::cal_area()
{
    area = M_PI * radius * radius;
}

double CIRCLE::get_area() // display area
{
    return area;
}
double CIRCLE::cal_area_obj(CIRCLE circle1, CIRCLE circle2)
{
    return M_PI * pow(circle1.radius + circle2.radius, 2);
}

CIRCLE CIRCLE::ret_area_obj(CIRCLE &circleB)
{
    CIRCLE temp;
    temp.area = M_PI * pow(radius + circleB.radius, 2);
    return temp;
}
