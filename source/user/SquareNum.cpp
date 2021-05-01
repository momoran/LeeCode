#include "SquareNum.h"
#include <iostream>
#include <cmath>
WORD SquareNum::execute()
{
    UpdateTestCase();
    result = judgeSquareSum(num);
    return VerifyResult();
}

bool SquareNum::judgeSquareSum(int c)
{ 
    for (int i = 0; i <= sqrt(c); i++) {
        int a = static_cast<int>(sqrt(c-pow(i,2)));
        if ((a*a + i*i) == c) {
            return true;
        }
    }
    return false;
}

void SquareNum::UpdateTestCase()
{
    num = 4;
    hopeResult = true;
}

WORD SquareNum::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}