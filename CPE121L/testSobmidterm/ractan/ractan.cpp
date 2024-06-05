#include "ractan.h"

Ractan_66044768::Ractan_66044768() : width(0.0), length(0.0), area(0.0)
{
}
Ractan_66044768::Ractan_66044768(float g_width, float g_length) : width(g_width), length(g_length)
{
    cal_area();
}
void Ractan_66044768::set_width_length(float g_widht, float g_length)
{
    width = g_widht;
    length = g_length;
    cal_area();
}
float Ractan_66044768::get_widht()
{
    return width;
}
float Ractan_66044768::get_length()
{
    return length;
}
void Ractan_66044768::cal_area()
{
    area = width * length;
}
float Ractan_66044768::get_area()
{
    return area;
}
void Ractan_66044768::cal_area_obj(Ractan_66044768 A, Ractan_66044768 &C)
{
    area = (A.width + C.width) * (A.length + C.length);
}

Ractan_66044768 Ractan_66044768::ret_cal_area(Ractan_66044768 &C)
{
    Ractan_66044768 temp;
    temp.width = width + C.width;
    temp.length = length + C.length;
    temp.area = temp.width * temp.length;
    return temp;
}
