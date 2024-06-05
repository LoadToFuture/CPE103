#include "ractan.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "Class Rectan_66044768 \n";
    Ractan_66044768 A, B, C, D, E;
    float width, length;
    cout << "Enter Width  Rectangle A : ";
    cin >> width;
    cout << "Enter Height Rectagle  A : ";
    cin >> length;
    A.set_width_length(width, length);
    float Awidht = A.get_widht();
    float Alength = A.get_length();
    float Aarea = A.get_area();
    B = A;
    float Bwidht = B.get_widht();
    float Blength = B.get_length();
    float Barea = B.get_area();
    C = Ractan_66044768(68, 68);
    float Cwidht = C.get_widht();
    float Clength = C.get_length();
    float Carea = C.get_area();
    // D A*C
    D.cal_area_obj(A, C);
    float Dwidht = A.get_widht() + C.get_widht();
    float Dlength = A.get_length() + C.get_length();
    float Darea = D.get_area();
    // E = B*C;
    E = B.ret_cal_area(C);
    float Ewidht = B.get_widht() + C.get_widht();
    float Elength = B.get_length() + C.get_length();
    float Earea = E.get_area();

    cout << "Ractangle A : Width : " << Awidht << " Lenght : " << Alength << " Area : " << Aarea << endl
         << "Ractangle B : Width : " << Bwidht << " Lenght : " << Blength << " Area : " << Barea << endl
         << "Ractangle C : Width : " << Cwidht << " Lenght : " << Clength << " Area : " << Carea << endl
         << "Ractangle D : Width : " << Dwidht << " Lenght : " << Dlength << " Area : " << Darea << endl
         << "Ractangle E : Width : " << Ewidht << " Lenght : " << Elength << " Area : " << Earea << endl;
         
    return 0;
}