#include <iostream>
using namespace std;

int main()
{                                                    // printf("");
    cout << "Integer number 1-9 Summation " << endl; // endl end+line
    int number, i=0,sum = 0;
    for (;;)   
    {
        cout << "Enter you number " << i + 1 << ": ";
        i++;
        cin >> number;
        if (number >= 1 && number <= 9)
            sum += number;
        else
            break;
    }
    cout << "Summation result is : " << sum << endl
         << "Exit!!" << endl;

    return 0;
}
/*int number, i = 0, sum = 0;
   cout << "Interger number 1-9 Summation" << endl;
   // for (;;)
   // {
   //     cout << "Enter you number" << i + 1 << ": ";
   //     cin >> number;
   //     i++;
   //     if (number >= 1 && number <= 9)
   //         sum += number;
   //     else
   //         break;
   // }
   for (int i = 0;cout << "Enter you number " << i + 1 << ": ",cin >> number,number >= 1 && number <= 9; i++)
           sum += number;
   cout << "Summation result is : " << sum << endl;
   return 0;*/