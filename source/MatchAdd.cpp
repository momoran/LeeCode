#include "MatchAdd.h"
#include <iostream>
MatchAdd::MatchAdd()
{
    a = 1;
    b = 2;
}

MatchAdd::~MatchAdd()
{

}

int MatchAdd::execute()
{
    std::cout << "a:" << a << " b:" << b << std::endl;
    return a + b;
}
