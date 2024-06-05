#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "../Area/Area.h"

class Circle : public AreaClss
{
private:
    float radius;

public:
    void set_radius(float get_radius);
    float get_radius();
    void cal_area();
};

#endif // _CIRCLE_H