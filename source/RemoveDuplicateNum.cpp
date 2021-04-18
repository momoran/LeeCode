#include "RemoveDuplicateNum.h"
#include <iostream>
#include <algorithm>

WORD RemoveDuplicateNum::execute()
{
    UpdateTestCase();
    result = removeDuplicates(inputNum);
    return VerifyResult();
}

int RemoveDuplicateNum::removeDuplicates(std::vector<int>& nums)
{
    auto fisrt = nums.begin();
    auto last = nums.end();
    while(fisrt != last) {
        auto it = std::find_if(fisrt, nums.end(), [&](int value) ->bool{
            return (value != *fisrt);
        });
        if (fisrt + 1 != it) {
            fisrt = nums.erase(fisrt + 1, it);
        } else {
            fisrt++;
        }
        
        last = nums.end();
    }
    return nums.size();
}

void RemoveDuplicateNum::UpdateTestCase()
{
    inputNum = {1,1,1,1};
    hopArray = {1};
    hopeResult = 1;
}

WORD RemoveDuplicateNum::VerifyResult()
{
    if (hopeResult == result && hopArray == inputNum) {
        return SUCESS;
    }
    return FAILURE;
}