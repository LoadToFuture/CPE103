#ifndef _GRANDMA_H
#define _GRANDMA_H
#include <iostream>

class GrandMa
{
protected:
    std::string fname;
    std::string blood_type;
    float thai_percent;
public:
    // GrandMa(/* args */);
    // ~GrandMa();
 void set_info();
 void get_info();

};

#endif //_GRANDMA_H