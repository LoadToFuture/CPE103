#include "GrandMa.h"
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;
// Function to generate a random name
 
string randomName();
void GrandMa::set_info()
{
    // fname = randomName();
    cout << "Enter Grandmother name : " ;
    cin >> fname;
    cout << endl;
    cout << endl;
    do
    {
        cout << "Enter Blood Type (A) (B) (AB) (O) : ";
        cin >> blood_type;
        cin.clear();
        cin.ignore();
        if (blood_type == "A" || blood_type == "B" || blood_type == "AB" || blood_type == "O")
        {
            break; // จบการทำงานของลูป do-while เมื่อได้ข้อมูลที่ถูกต้อง
        }
        else
            cout << "Invalid input BLOOD TYPE !! Please enter again." << endl;
    } while (blood_type != "A" || blood_type != "B" || blood_type != "AB" || blood_type != "O");
    do
    {
        cout << "Enter Percentage of Thai nationality (20, 50, 75, 100 %): ";
        cin >> thai_percent;
        if (thai_percent == 20 || thai_percent == 50 || thai_percent == 75 || thai_percent == 100)
        {
            break;
        }
        else
        {
            cout << "Invalid input! Please enter again." << endl;
        }
    } while (true);
    cout << endl;
}

void GrandMa::get_info()
{
    cout << "Grandfather name : " << fname << endl;
    cout << "Blood type : " << blood_type << endl;
    cout << "Thai nationality : " << thai_percent << endl<<endl;
}
string randomName()
{
    // List of possible first names
    vector<string> firstNames = {"Alice", "Emma", "Grace", "Hannah", "Julia"};
    // Seed the random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));
    // Randomly select first and last names
    string firstName = firstNames[rand() % firstNames.size()];

    // Concatenate first name and last name with a space in between
    return firstName;
}