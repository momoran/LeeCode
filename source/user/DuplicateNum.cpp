#include "DuplicateNum.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits.h>

WORD DuplicateNum::execute()
{
    UpdateTestCase();
    result = containsNearbyAlmostDuplicate(inputNum, m_k, m_t);
    return VerifyResult();
}

bool DuplicateNum::containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
{
    std::set<long> tmpLib;
    for (size_t i = 0; i < nums.size(); i++) {
        auto it = tmpLib.lower_bound(std::max(nums[i], INT_MIN + t) - t); // 返回大于等于相应数的指针
        if (it != tmpLib.end() && *it <= (std::min(nums[i], INT_MAX - t) + t)) {
            return true;
        }
        tmpLib.insert(nums[i]);
        if (i >= k) {
            tmpLib.erase(nums[i - k]);
        }
    }
    return false;
}

void DuplicateNum::UpdateTestCase()
{
    inputNum = {1,2,3,1};
    m_t = 3;
    m_k = 0;
    hopeResult = false;
}

WORD DuplicateNum::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}