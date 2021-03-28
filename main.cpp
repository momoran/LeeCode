#include <iostream>
#include "operateLib.h"
#include "std_lib.h"
#include "MatchAdd.h"


int main()
{
    StdLibBase *p = new MatchAdd;
    p.execute();
    return 0;
}