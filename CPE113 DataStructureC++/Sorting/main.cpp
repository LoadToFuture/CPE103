#include <iostream>
#include "Sorting.h"
#include <ctime>
using namespace std;
int main()
{
    int SetMaxSize = 20;
    Sorting s1(SetMaxSize);
     s1.display();
    srand(time(0));
    for (int i = 0; i < SetMaxSize; ++i)
    {
        s1.add(i, (rand() % 10) + 1);
    }

    
    s1.display();
    return 0;
}
