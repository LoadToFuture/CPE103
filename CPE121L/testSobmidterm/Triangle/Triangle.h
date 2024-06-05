#ifndef _TRIANGLE_H
#define _TRIANGLE_H

class Triangle
{
private:
        float base;
        float height;
        float area;
public:
    Triangle():base(0.0),height(0.0),area(0.0){};
    Triangle(float get_base,float get_height):base(get_base),height(get_height){cal_Triarea();};
void set_baseHeight(float get_base ,float get_height);
void cal_Triarea();
float get_Triarea();
void get_baseandheight();
float get_base();
float get_height();
void cal_TriareObj(Triangle a, Triangle c);
Triangle Triangle::ret_Triarea_Obj(Triangle &c);


};


#endif //_TRIANGLE_H