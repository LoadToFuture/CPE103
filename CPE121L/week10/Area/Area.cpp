#include "Area.h"

AreaClss::AreaClss() : area(0.0)
{
}
void AreaClss::set_area(float get_area)
{
    area = get_area;
}

float AreaClss::get_area()
{
    return area;
}

