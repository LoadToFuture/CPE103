#ifndef _GRANDFA_
#define _GRANDFA_
#include <iostream>

class GrandFa
{
protected:
    std::string fname;
    std::string lname;
    float thai_percent;
public:
    // GrandFa(/* args */);
    // ~GrandFa();
    void set_info();
    void get_info();
};

#endif