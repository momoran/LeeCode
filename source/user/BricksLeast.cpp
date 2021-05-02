#include "BricksLeast.h"
#include <iostream>
#include <cmath>

WORD BricksLeast::execute()
{
    UpdateTestCase();
    result = leastBricks(m_wall);
    return VerifyResult();
}

int BricksLeast::leastBricks(std::vector<std::vector<int>>& wall)
{ 
    std::vector<std::vector<int>> wallMap;
    GenerateMap(wall, wallMap);
    int sumMin = 20000;
    for (auto i = 0; i < wallMap[0].size(); i++) {
        int sum = 0;
        for(auto j = 0; j < wallMap.size(); j++) {
            sum += wallMap[j][i];
        }
        if (sum < sumMin) {
            sumMin = sum;
        }
    }
    std::cout << "summin:" << sumMin << std::endl;
    return sumMin;
}

void BricksLeast::GenerateMap(std::vector<std::vector<int>>& wall, std::vector<std::vector<int>>& wallMap)
{
    if (wall.empty()) {
        return;
    }
    auto it = wall.begin();
    int wallNum = 0;
    for(auto i = 0; i < wall[0].size(); i++) {
        wallNum += wall[0][i];
    }
    std::cout << "wallNum:" << wallNum << std::endl;

    int mapNum = 0;
    while(it != wall.end()) {
        if (it->size() > mapNum) {
            mapNum = it->size();
        }
        it++;
    }
    std::cout << "mapNum:" << mapNum << std::endl;

    std::vector<int> tmp;
    it = wall.begin();
    while(it != wall.end()) {
        for (auto i = 0; i < it->size(); i++) {
            auto index = (*it)[i];
            int tmpInt = 0;
            while(index > 0) {
                tmpInt = 1;
                tmp.push_back(tmpInt);
                std::cout << tmpInt << " ";
                index--;
            }
            if (tmp.size() < (mapNum + wallNum - 1)) {
               tmpInt = 0;
               tmp.push_back(tmpInt);
               std::cout << tmpInt << " ";
            }
        }
        it++;
        int sizeNum = tmp.size();
        while(sizeNum < (mapNum + wallNum - 1)) {
            int tmpInt = 0;
            tmp.push_back(tmpInt);
            std::cout << tmpInt << " ";
            sizeNum = tmp.size();
        }
        wallMap.push_back(tmp);
        tmp.clear();
        std::cout << std::endl;
    }
}

void BricksLeast::UpdateTestCase()
{
    /*std::vector<std::vector<int>> wall = {
        {1},
        {1},
        {1},
    };*/
    std::vector<std::vector<int>> wall = {
        {1, 2, 2, 1},
        {3, 1, 2},
        {1, 3, 2},
        {2, 4},
        {3, 1, 2},
        {1, 3, 1, 1}
    };
    m_wall = wall;
    hopeResult = 3;
}

WORD BricksLeast::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}