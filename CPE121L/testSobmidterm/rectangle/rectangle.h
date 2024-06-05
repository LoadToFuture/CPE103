#ifndef _RACTANGLE_H
#define _RACTANGLE_H

class rectangle
{
private:
 float Width ;
 float Length;
 float area;
public:
    rectangle(/* args */);
    rectangle(float g_Widht,float g_Length);
   // ~rectangle();
    void set_wh(float Width,float Length);
    void cal_ractangle();
    float get_width();
    float get_height();
    float get_reaRec();
    void cal_areaRec_obj(rectangle a, rectangle &c);
    rectangle ret_calareaObj(rectangle &c);

};

 

#endif  //_RACTANGLE_H