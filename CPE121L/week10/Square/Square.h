#ifndef _SQURE_H
#define _SQURE_H
#include "../Area/Area.h"

class Square : private AreaClss // if not public in headAreaClss is no use method fuction AreaClss
{                                  
private:
    float width;
public:
    float get_width();
    void cal_area(float get_width);
};

#endif //_SQURE_H