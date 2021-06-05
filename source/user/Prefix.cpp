#include "Prefix.h"
#include <iostream>
#include <map>

WORD Prefix::execute()
{
    UpdateTestCase();
    result = findMaxLength(m_numsLib);
    return VerifyResult();
}
int Prefix::findMaxLength(std::vector<int>& nums)
{
    std::map<int, int> tmpLib;
    tmpLib[0] = -1;
    int maxSubLen = 0;
    int sumArray = 0;
    for(int i = 0; i < nums.size(); i++) {
        sumArray = (nums[i] == 1) ? sumArray + 1 : sumArray - 1;
        auto it = tmpLib.find(sumArray);
        if(it != tmpLib.end()) {
            int subLen = i - it->second;
            maxSubLen = subLen > maxSubLen ? subLen : maxSubLen;
        } else {
            tmpLib[sumArray] = i;
        }
    }
    return maxSubLen;
}

void Prefix::UpdateTestCase()
{
    m_numsLib = {0,1,1,0};
    hopeResult = 4;
}

WORD Prefix::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}