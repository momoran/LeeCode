#include "SubArray.h"
#include <iostream>
SubArray::SubArray()
{

}

SubArray::~SubArray()
{

}

WORD SubArray::execute()
{
    UpdateTestCase();
    result = maxSubArray(nums);
    return VerifyResult();
}

int SubArray::maxSubArray(std::vector<int>& num)
{
    int sum = 0;
    int max = num[0];
    for (int i = 0; i < num.size(); i++) {
        if (sum <= 0) {
            sum = 0;
        }
        sum += num[i];
        if (sum > max) {
            max = sum;
        }
    }
    std::cout << "max:" << max << std::endl;
    return max;
}

void SubArray::UpdateTestCase()
{
    nums = {-2,1,-3,4,-1,2,1,-5,4};
    hopeResult = 6;
}

WORD SubArray::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}