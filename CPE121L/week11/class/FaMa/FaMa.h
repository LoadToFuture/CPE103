#ifndef _FAMA_H
#define _FAMA_H
#include <iostream>
#include "../GrandFa/GrandFa.h"
#include "../GrandMa/GrandMa.h"
class FaMa : public GrandFa , public GrandMa
{
private:
    std::string name;
    std::string sex;
    float thai_percent;
public:
    // FaMa(/* args */);
    // ~FaMa();
    void thai_cal();
    void set_info();
    void get_info();
};

#endif //_FAMA_H