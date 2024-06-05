#include "Triangle.h"
#include <iostream>
using namespace std;
void Triangle::set_baseHeight(float get_base, float get_height)
{
    base = get_base;
    height = get_base;
    cal_Triarea();
}

void Triangle::cal_Triarea()
{
    area = 0.5 * base * height;
}
float Triangle::get_Triarea()
{
    return area;
}

void Triangle::get_baseandheight()
{
    cout << " Base is : " << base << " Height is : " << height;
}

float Triangle::get_base()
{
    return base;
}

float Triangle::get_height()
{
    return height;
}

void Triangle::cal_TriareObj(Triangle a, Triangle c)
{
    area = 0.5 * (a.base + c.base) * (a.height + c.height);
}

Triangle Triangle::ret_Triarea_Obj(Triangle &c)
{
    Triangle temp;
    temp.base = base + c.base;
    temp.height = height + c.height;
    temp.area = 0.5 * temp.base * temp.height;
    return temp;
}
