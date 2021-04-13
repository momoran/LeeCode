#include "UnglyNumberNo.h"
#include <iostream>
#include <set>

UnglyNumberNo::UnglyNumberNo()
{

}

UnglyNumberNo::~UnglyNumberNo()
{

}

WORD UnglyNumberNo::execute()
{
    UpdateTestCase();
    result = nthUglynumber(inputNum);
    return VerifyResult();
}

int UnglyNumberNo::nthUglynumber(int n)
{
    int index = 0;
    while (n > 0) {
        index++;
        if (isUgly(index)) {
            n--;
            std::cout << "number is:" << index << std::endl;
        }
    }
    std::cout << "next number is:" << index << std::endl;

    return index;
}

void UnglyNumberNo::UpdateTestCase()
{
    inputNum = 10;
    hopeResult = 12;
}

WORD UnglyNumberNo::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}