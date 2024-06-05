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

public:
    CIRCLE();                  // : radius(0), area(0){};                  // constructor 1.1
    CIRCLE(double get_radius); // constructor 1.2
    void set_radius(double get_radius);
    double get_radius();
    void cal_area();
    double get_area();
    double cal_area_obj(CIRCLE circle1, CIRCLE circle2);
    CIRCLE ret_area_obj(CIRCLE &circle);
};

#endif //_CIRCLE_H_
