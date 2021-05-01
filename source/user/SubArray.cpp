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
    int max = num[0];      // 最大值为第一个数
    for (int i = 0; i < num.size(); i++) {
        if (sum <= 0) {    // 连续相加和小于0，则表示不管怎样前面的字符串都是拖后面字符串的后腿，因此重新确定起点
            sum = 0;
        }
        sum += num[i];     // 确认后起点后在继续相加
        if (sum > max) {   // 更新和之后再确认更新最大值
            max = sum;
        }
    }
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