#include "DynamicProgram.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <memory>

WORD DynamicProgram::execute()
{
    UpdateTestCase();
    result = longestPalindrome(m_inputStr);
    return VerifyResult();
}

int DynamicProgram::MaxChildArrayOrder(std::vector<int> arr)
{

}

std::string DynamicProgram::longestPalindrome(std::string s)
{ 
    // 直观方法，暴力法
    // std::vector<int> tmp(s.size(),1);
    // int index = 0;
    // for(auto it = s.begin(); it < s.end(); it++) {
    //     for(auto iter = it + 1; iter <= s.end(); iter++) {
    //        if(IsPalindrome(std::string(it, iter))) {
    //            tmp[index] = iter - it;
    //        }
    //     }
    //     index++;
    // }
    // int max = 1;
    // auto it = tmp.begin();
    // int lowIndex = 0;;
    // while(it != tmp.end()) {
    //     if(*it > max) {
    //         max = *it;
    //         lowIndex = it - tmp.begin();
    //     }
    //     it++;
    // }
    // return std::string(s.begin() + lowIndex, s.begin()+ lowIndex + max);
    // 动态规划
    // std::vector<std::vector<bool>> dpArray;

    // 初始化数组，由于需要不停的从堆中获取vector对象因此耗时
    // for(int i = 0; i < s.size(); i++) {
    //     std::vector<bool> tmp;
    //     for(int j = 0; j < s.size(); j++) {
    //         if(i == j) {
    //             tmp.push_back(true);
    //         } else {
    //             tmp.push_back(false);
    //         }
    //     }
    //     dpArray.push_back(tmp);
    // }

    int n = s.size();
    std::vector<std::vector<bool>> dpArray(n, std::vector<bool>(n));
    int maxBegin = 0;
    int maxLen = 1;
    for(int i = 0; i < s.size();i++) {
        for(int j = 0; j <= i; j++) {
            if (i != j && s[i] == s[j]) {
                dpArray[j][i] = (i - j == 1) ? true : dpArray[j+1][i-1];
                if(dpArray[j][i] && ((i - j + 1) > maxLen)) {
                    maxLen = i - j + 1;
                    maxBegin = j;
                }
            } else {
                dpArray[j][i] = (i == j);
            }
        }
    }
    return s.substr(maxBegin, maxLen);
}

bool DynamicProgram::IsPalindrome(std::string s)
{
    //std::cout << s << std::endl;
    for(int left = 0, right = s.size() - 1; left < right; left++, right--) {
        if(s[left] != s[right]) {
            return false;
        }
    }
    return true;
}

void DynamicProgram::UpdateTestCase()
{
    m_inputStr = "cbbd";
    hopeResult = "bb";
}

WORD DynamicProgram::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}