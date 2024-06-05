#include "student.h" // iostream , using namespace
const int N = 2;
int main()
{
    student students[N];
    string name;
    float score;
    puts("Class Student");
    for (int i = 0; i < N; i++)
    {
        cout << "Enter name : ";
        cin >> name;
        do
        {
            cout << "Enter Score : ";
            cin >> score;
            if (score < 0 || score >= 100)
                cout << "Score input : " << score << " : Is invalid" << '\n';
            else if (cin.fail())
            {
                cout << "Don't Enter is Character\n";
            }
            students[i].set_info(name, score);
        } while (score < 0 || score >= 100);
    }
    for (int i = 0; i < N; i++)
    {
        cout << "Student (" << static_cast<char>('A' + i) << "): ";
        students[i].show_info();
    } 
    return 0;
}
