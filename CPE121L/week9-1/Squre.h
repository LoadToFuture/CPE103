#ifndef _SQURE_H
#define _SQURE_H
#include "Area.h"
class Square : public AreaClss  // if not public in headAreaClss is no use method fuction AreaClss
{
private:
    float width;

public:
   // void set_width(float get_width);
    float get_width();
    void cal_area(float get_width);
};

#endif //_SQURE_H