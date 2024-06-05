#include "rectangle.h"
#include <iostream>
using namespace std;
rectangle::rectangle() : Width(0), Length(0)
{
}
rectangle::rectangle(float Width, float Length) : Width(Width), Length(Length)
{
    cal_ractangle();
}
void rectangle::set_wh(float g_Width, float g_Length)
{
    Width = g_Width;
    Length = g_Length;
    cal_ractangle();
}
void rectangle::cal_ractangle()
{
    area = Width * Length;
}

float rectangle::get_width()
{
    return Width;
}

float rectangle::get_height()
{
    return Length;
}

float rectangle::get_reaRec()
{
    return area;
}

void rectangle::cal_areaRec_obj(rectangle a, rectangle &c)
{
    // cout << "Width  : " << a.get_width() << " + " << c.Width << endl;
    // cout << "Length : " << a.get_height() << " + " << c.Length << endl;
    area = (c.Width + a.Width) * (c.Length + a.Length);
}

rectangle rectangle::ret_calareaObj(rectangle &c)
{
    rectangle Temp;
    Temp.Width = Width + c.Width;
    Temp.Length = Length + c.Length;
    Temp.area = Temp.Width * Temp.Length;
    return Temp;
}
