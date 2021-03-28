#include "MatchAdd.h"

MatchAdd::MatchAdd()
{

}

MatchAdd::~MatchAdd()
{

}

WORD MatchAdd::execute()
{
    UpdateTestCase();
    result = twoSum(nums, target);
    return VerifyResult();
}

std::vector<int> MatchAdd::twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> tmp;
    for(BYTE i = 0; i < nums.size(); i++) {
        for(BYTE j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                tmp.push_back(i);
                tmp.push_back(j);
                return tmp;
            }
        }
    }
    return tmp;
}

void MatchAdd::UpdateTestCase()
{
    nums = {3,3,4};
    target = 6;
    hopeResult = {0, 1};
}

WORD MatchAdd::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}