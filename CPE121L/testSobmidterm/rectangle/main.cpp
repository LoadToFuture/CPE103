#include <iostream>
#include "rectangle.h"
using namespace std;

int main()
{
    rectangle recA, recB, recC, recD, recE;
    float width, Length;
    cout << "Rectangle Area Class Obj \n";
    cout << "Enter Widht M : ";
    cin >> width;
    cout << "Enter Height M : ";
    cin >> Length;

    recA.set_wh(width, Length);
    cout << "Class (A) Width is : " << recA.get_width()
         << " (M) Lenght is : " << recA.get_height() << " (M) Area rec is : " << recA.get_reaRec() << " (Square meter )\n";

    recB = recA;
    cout << "Class (B) Width is : " << recB.get_width()
         << " (M)  Lenght is : " << recB.get_height() << " (M) Area rec is : " << recB.get_reaRec() << " (Square meter ) \n";

    recC = rectangle(9, 19);
    cout << "Class (C) Width is : " << recC.get_width()
         << " (M)  Lenght is : " << recC.get_height() << " (M) Area rec is : " << recC.get_reaRec() << " (Square meter ) \n";

    // recD.cal_areaRec_obj(&recA, recC);
    recD.cal_areaRec_obj(recA, recC);
    float D_width = recA.get_width() + recC.get_width();
    float D_Length = recA.get_height() + recC.get_height();
    cout << "Class (D) Width is : " << D_width
         << " (M) Lenght is : " << D_Length << " (M) Area rec is : " << recD.get_reaRec() << " (Square meter ) \n";

    recE = recB.ret_calareaObj(recC);
    float E_width = recB.get_width() + recC.get_width();
    float E_Length = recB.get_height() + recC.get_height();
    cout << "Class (D) Width is : " << E_width
         << " (M) Lenght is : " << E_Length << " (M) Area rec is : " << recE.get_reaRec() << " (Square meter ) \n";

    return 0;
}
