#include "student.h"

student::student() // constructor
{
}

student::~student() // destructor
{
}

void student::set_info(string get_name, float get_score)
{
    name = get_name;
    score = get_score;
    cal_grade();
}

void student::cal_grade()
{
    if (score >= 80)
        Grade = 'A';
    else if (score >= 70)
        Grade = 'B';
    else if (score >= 60)
        Grade = 'C';
    else if (score >=50)
        Grade = 'D' ;
    else 
        Grade = 'F';
}

void student::show_info()
{
    cout << " Name : " << name << " Score : " << score << " Grade : " << Grade << endl;
}
