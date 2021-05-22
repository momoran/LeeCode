#include "DynamicProgram.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <memory>

WORD DynamicProgram::execute()
{
    UpdateTestCase();
    // result = uniquePaths(m_mAxies,m_nAxies);
    // result = uniquePathsWithObstacles(m_obstacleGrid);
    result = minPathSum(m_Grid);
    return VerifyResult();
}

int DynamicProgram::uniquePaths(int m, int n)
{
    std::vector<std::vector<int>> dpArray(m, std::vector<int>(n));
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dpArray[i][j] = (i == 0 || j == 0) ? 1 : dpArray[i][j-1] + dpArray[i-1][j];
        }
    }
    std::cout << dpArray[m-1][n-1] << std::endl;
    return dpArray[m-1][n-1];
}

int DynamicProgram::uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
    std::vector<std::vector<int>> dpArray = obstacleGrid;
    int width = obstacleGrid.size();
    int length = obstacleGrid[0].size();
    dpArray[0][0] = 1;
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (obstacleGrid[i][j] == 1) {
                dpArray[i][j] = 0;
            } else {
                if ((i == 0 || j == 0) && i != j) {
                    // 由于有障碍无的存在，因此沿墙壁方向的路径数与前一个坐标保持一致
                    dpArray[i][j] = (i == 0) ? dpArray[i][j-1] : dpArray[i-1][j];
                } else {
                    if (i == 0) {
                        //(i == 0 || j == 0) && i != j 该条件将坐标00进行了过滤，因此需要单独处理
                        continue;
                    }
                    dpArray[i][j] = dpArray[i][j-1] + dpArray[i-1][j];
                }
                
            }
        }
    }
    return dpArray[width-1][length-1];
}

int DynamicProgram::minPathSum(std::vector<std::vector<int>>& grid)
{
    std::vector<std::vector<int>> dpArray = grid;
    int width = grid.size();
    int length = grid[0].size();
    for(int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if((i == 0 || j == 0) && (i != j)) {
                dpArray[i][j] += (i == 0) ? dpArray[i][j-1] : dpArray[i-1][j];
            } else {
                if (i == 0) {
                    continue;
                }
                dpArray[i][j] += dpArray[i-1][j] > dpArray[i][j-1] ? dpArray[i][j-1] : dpArray[i-1][j];
            }
        }
    }
    return dpArray[width-1][length-1];
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

void DynamicProgram::UpdateTestCase()
{
    // 无障碍路径数
    // m_mAxies = 3;
    // m_nAxies = 7;
    m_Grid = {{1,2,3},{4,5,6}};
    hopeResult = 12;
}

WORD DynamicProgram::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}