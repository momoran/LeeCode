#include "UnglyNumber.h"
#include <iostream>

UnglyNumber::UnglyNumber()
{

}

UnglyNumber::~UnglyNumber()
{

}

WORD UnglyNumber::execute()
{
    UpdateTestCase();
    result = isUgly(inputNum);
    return VerifyResult();
}

bool UnglyNumber::isUgly(int n)
{
    if (n == 0) {
        return false;
    }
    constexpr int uglyLen = 3;
    constexpr int div1[uglyLen] = {2, 3, 5};
    int temp = n;
    int index = 0;
    while(temp != 1) {
        if (temp % div1[index] == 0) {
            temp = temp / div1[index];
        } else {
            index++;
            if (index >= uglyLen) {
                return false;
            }
        }
    }
    return true;
}

void UnglyNumber::UpdateTestCase()
{
    inputNum = 7;
    hopeResult = false;
}

WORD UnglyNumber::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}