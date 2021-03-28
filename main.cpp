#include <iostream>
#include "operateLib.h"
#include "std_lib.h"
#include "MatchAdd.h"


int main()
{
    StdLibBase* ptr = new MatchAdd;
    std::cout << "result :" << ptr->execute() << std::endl;
    return 0;
}