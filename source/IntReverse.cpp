#include "IntReverse.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <limits.h>
IntReverse::IntReverse()
{

}

IntReverse::~IntReverse()
{

}

WORD IntReverse::execute()
{
    UpdateTestCase();
    result = reverse(nums);
    return VerifyResult();
}

int IntReverse::reverse(int x)
{
    long long tmp = x;
    int sign = 1;
    if (x < 0) {
        tmp = -1 * tmp;
        sign = -1;
    }
    std::vector<int> lib;
    while(tmp != 0) {
        int num = tmp % 10;
        tmp = tmp / 10;
        lib.push_back(num);
    }

    auto first = lib.rbegin();
    long long result = 0;
    int index = 0;
    while(first != lib.rend()) {
        result += (*first) * ceil(pow(10, index));
        first++;
        index++;
    }
    result = result * sign;
    if (result > INT_MAX || result < INT_MIN) {
        result = 0;
    }

    return result;
}

void IntReverse::UpdateTestCase()
{
    nums = INT_MAX;
    hopeResult = 0;
}

WORD IntReverse::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}