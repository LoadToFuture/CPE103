#include <iostream>
#include "ChainNode.h"
using namespace std;

int main ()
{
    ChainNode p1; // instrant
    ChainNode p2(10); 
    ChainNode p3(20,&p2);

    
    return 0;
}


