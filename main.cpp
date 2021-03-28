#include <iostream>
#include "operateLib.h"
#include "std_lib.h"
#include "MatchAdd.h"
#include <memory>

int main()
{
    std::unique_ptr<StdLibBase> ptr(new MatchAdd());
    if (ptr->execute() == SUCESS) {
        std::cout << "the result is ok" << std::endl;
    } else {
        std::cout << "the result is faiure" << std::endl;
    }
    return 0;
}