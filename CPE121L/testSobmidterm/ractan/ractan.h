#ifndef _RACTAN_H
#define _RACTAN_H

class Ractan_66044768

{
private:
    float width;
    float length;
    float area;
public:
    Ractan_66044768();
    Ractan_66044768(float g_width ,float g_length);
    void set_width_length(float g_widht , float g_length);
    float get_widht();
    float get_length();
    void cal_area();
    float get_area();
    void cal_area_obj(Ractan_66044768 A , Ractan_66044768 &C);
    Ractan_66044768 ret_cal_area(Ractan_66044768 &C);

};


#endif //_RACTAN_H

