#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
    Triangle triA, triB, triC,triD,triE;
    float base, height;
    cout << "Program Triangle Area calculator !! \n";
    cout << "Enter Base (M): ";
    cin >> base;
    cout << "Enter Height (M): ";
    cin >> height;

    triA.set_baseHeight(base, height);
    cout << "Triangle Class A ";
    triA.get_baseandheight();
    cout << " Area is : " << triA.get_Triarea() << endl;

    triB = triA;
    cout << "Triangle Class B ";
    triB.get_baseandheight();
    cout << " Area is : " << triB.get_Triarea() << endl;

    triC = Triangle(10, 8);
    cout << "Triangle Class C ";
    triC.get_baseandheight();
    cout << " Area is : " << triC.get_Triarea() << endl;

    float triDBase = triA.get_base() + triC.get_base();
    float triDHeight = triA.get_height() + triC.get_height();
    triD.cal_TriareObj(triA,triC);
    cout << "Triangle Class D  Base is : " << triDBase << " Height is: " << triDHeight ;
    cout << " Area is : " << triD.get_Triarea() << endl;

    triE = triB.ret_Triarea_Obj(triC);
    float triEBase = triB.get_base() + triC.get_base();
    float triEHeight = triB.get_height() + triC.get_height();
    cout << "Triangle Class E  Base is : " << triEBase << " Height is: " << triEHeight ;
    cout << " Area is : " << triE.get_Triarea() << endl;

    return 0;
}
