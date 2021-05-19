#include "MaxArrayXor.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>

WORD MaxArrayXor::execute()
{
    UpdateTestCase();
    result = findMaximumXOR(m_numsArray);
    return VerifyResult();
}

int MaxArrayXor::findMaximumXOR(std::vector<int>& nums)
{ 
    // int numsLen = nums.size();
    // std::sort(nums.begin(),nums.end(),[](int a, int b){return a > b;});
    // for(auto num : nums) {
    //     for(int j = MAX_BIT_CNT; j >= 0; j--) {
    //         if (isSatifiykbit1(num, j)) {
    //             m_bitLib[1 << j].push_back(num);
    //             std::cout << "index:" << (1 << j) << " result:" << num << std::endl;
    //         }
    //     }
    // }
    // std::vector<int> maxArray;
    // std::vector<int> nextArray;
    // int k = 0;
    // for(int j = MAX_BIT_CNT; j >= 0; j--) {
    //     if(k == 0 && isSatifiykbit1(nums[0], j)) {
    //         maxArray = m_bitLib[1<<j];
    //         k++;
    //     }
    //     if(!m_bitLib[1<<j].empty()) {
    //         nextArray = m_bitLib[1<<j];
    //         break;
    //     }
    // }
    // int maxResult = nums[0];
    // for(auto array1 : maxArray) {
    //     for(auto array2 : nextArray) {
    //         if ((array1 ^ array2) > maxResult) {
    //             maxResult = array1 ^ array2;
    //         }
    //     }
    // }
    // std::cout << maxResult << " " << maxArray.size() << " " << nextArray.size() << std::endl;
    // return maxResult;
    int x = 0;
        for (int k = 30; k >= 0; --k) {
            std::unordered_set<int> seen;
            for (int num: nums) {
                // 如果只想保留从最高位开始到第 k 个二进制位为止的部分
                // 只需将其右移 k 位
                seen.insert(num >> k);
                std::cout << (num>>k) << " ";
            }
            std::cout << std::endl;
            // 目前 x 包含从最高位开始到第 k+1 个二进制位为止的部分
            // 我们将 x 的第 k 个二进制位置为 1，即为 x = x*2+1
            int x_next = x * 2 + 1;
            bool found = false;
            
            // 枚举 i
            for (int num: nums) {
                std::cout << "compare:" << (x_next ^ (num >> k)) << " next:" << x_next << " num:" <<(num >> k) << std::endl;
                if (seen.count(x_next ^ (num >> k))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                x = x_next;
            }
            else {
                // 如果没有找到满足等式的 a_i 和 a_j，那么 x 的第 k 个二进制位只能为 0
                // 即为 x = x*2
                x = x_next - 1;
            }
        }
        return x;
}

bool MaxArrayXor::isSatifiykbit1(int num, int k)
{
    DWORD index = 0x1;
    return (num & (index << k)) != 0;
}

void MaxArrayXor::UpdateTestCase()
{
    m_numsArray = {11,10};
    hopeResult = 1;
}

WORD MaxArrayXor::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}