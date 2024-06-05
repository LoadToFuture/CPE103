#include "circle.h"
#include <math.h>
CIRCLE::CIRCLE()
{
    radius = 0;
    area = 0;
    volume = 0;
}


void CIRCLE::set_radius(double get_radius)
{
    radius = get_radius;
    cal_area();
    cal_volume_circle();
}
double CIRCLE::get_radius()
{
    return radius;
}
void CIRCLE::cal_area()
{
    area = M_PI * radius * radius;
}
double CIRCLE::cal_volume_circle() //! หา ปริมาตร
{
    return 4 * M_PI * (pow(radius, 3) / 3);
}
double CIRCLE::MassWater() //! หาน้ำหนักของน้ำ
{
    return cal_volume_circle() * 1000;   //! (ในหน่วยกิโลกรัมต่อลูกบาศก์เมตร) *1000
}
double CIRCLE::pressure()
{
    return MassWater() * 9.81 * (radius * 2);
}

double CIRCLE::get_area() // display area
{
    return area;
}


