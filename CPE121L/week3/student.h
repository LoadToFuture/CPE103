// class header
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
using namespace std;
class student
{
private:
//data member
    string name;
    float score ;
    char Grade; // 'A' 'B'  x "B+"
    /* data */
public:
    student(/* args */);
    ~student();
    //fuction member
    void set_info(string get_name,float score); //method1
    void cal_grade(); 
    void show_info();
};



#endif //_STUDENT_H_