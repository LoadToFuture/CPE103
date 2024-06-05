
#include "student.h" // iostream , using namespace
int main()
{
    student s1, s2;
    string name;
    float score;
    puts("Class Student");

    cout << "Enter name A: ";
    cin >> name;
    cout << "Enter Score A: ";
    cin >> score;
    s1.set_info(name, score);

    cout << "Enter name B: ";
    cin >> name;
    cout << "Enter Score B: ";
    cin >> score;
    s2.set_info(name, score);

    cout << "Student A : ";
    s1.show_info();

    cout << "Student B : ";
    s2.show_info();
    
    return 0;
}
