#include "FaMa.h"
#include <iostream>
using namespace std;
void FaMa::thai_cal()
{
    thai_percent = (GrandFa::thai_percent + GrandMa ::thai_percent) / 2.00;
}
void FaMa::set_info()
{
    GrandFa ::set_info();
    cout << endl;
    GrandMa ::set_info();
    cout << endl;
    cout << "Enter Name : ";
    cin >> name;
    do
    {
        cout << "Enter Sex(\033[1;30mMale\033[0m/\033[1;30mFemale\033[0m) : ";
        cin >> sex;
        if (sex == "Male" || sex == "Female")
            break;
        else
            cout << "Invalid input SEX ! Please enter again." << endl;
    } while (true);
    thai_cal();
}
void FaMa::get_info()
{
    GrandFa::get_info();
    GrandMa::get_info();
    string chk_sex = (sex == "Male" || sex == "male") ? "Father" : ((sex == "Female" || sex == "female") ? "Mother" : "Invalid sex");
    cout << "\033[1;32m" << chk_sex << "\033[0m Name : " << name << " " << lname << endl;
    cout << "Sex : " << sex << endl;
    cout << "Blood type : " << blood_type << endl;
    cout << "Thai nationality : " << thai_percent << endl;
}