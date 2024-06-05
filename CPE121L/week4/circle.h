// class header
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include <iostream>
using namespace std;
#include <math.h>
class CIRCLE
{
private:
    int *L;
    double radius;
    double area;
    double volume;

public:
    CIRCLE(/* args */);
    ~CIRCLE();

    void set_radius(double get_radius);
    double get_radius();
    void cal_area();
    double cal_volume_circle();
    double get_area();
    double MassWater();
    double pressure();
};

#endif //_CIRCLE_H_
