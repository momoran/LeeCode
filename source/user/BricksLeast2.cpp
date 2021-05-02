#include "BricksLeast2.h"
#include <iostream>
#include <cmath>

WORD BricksLeast2::execute()
{
    UpdateTestCase();
    result = leastBricks(m_wall);
    return VerifyResult();
}

int BricksLeast2::leastBricks(std::vector<std::vector<int>>& wall)
{ 
    int mapNum = 0;
    int sumMin = 0;
    auto it = wall.begin();
    while(it != wall.end()) {
        int sum = 0;
        for (auto i = 0; i < it->size();i++) {
            sum += (*it)[i];
            auto iter = hashMap.find(sum);
            if (iter != hashMap.end()) {
                iter->second += 1;
            } else {
                hashMap[sum] = 1;
            }
        }
        mapNum = sum;
        it++;
    }

    auto iter = hashMap.begin();
    int maxNum = 0;
    while(iter != hashMap.end()) {
        std::cout << "first:" << iter->first << " is:" << iter->second << std::endl;
        if (iter->second > maxNum && iter->first != mapNum) {
            maxNum = iter->second;
        }
        iter++;
    }
    
    sumMin = wall.size() - maxNum;
    std::cout << "summin:" << sumMin << std::endl;
    return sumMin;
}

void BricksLeast2::UpdateTestCase()
{
    std::vector<std::vector<int>> wall = {
        {1, 1},
        {2},
        {1, 1},
    };
    // std::vector<std::vector<int>> wall = {
    //     {1, 2, 2, 1},
    //     {3, 1, 2},
    //     {1, 3, 2},
    //     {2, 4},
    //     {3, 1, 2},
    //     {1, 3, 1, 1}
    // };
    m_wall = wall;
    hopeResult = 3;
}

WORD BricksLeast2::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}