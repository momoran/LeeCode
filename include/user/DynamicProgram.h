#ifndef _DYNAMICPROGRAM_H
#define _DYNAMICPROGRAM_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>
#include <map>
#include <string>

class DynamicProgram : public StdLibBase
{
public:
    DynamicProgram() = default;
    virtual ~DynamicProgram() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int uniquePaths(int m, int n);
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
    int minPathSum(std::vector<std::vector<int>>& grid);
    std::string longestPalindrome(std::string s);
    // std::vector<std::vector<int>> m_obstacleGrid;
    std::vector<std::vector<int>> m_Grid;
    int result;
    int hopeResult;
    int m_mAxies;
    int m_nAxies;

};

#endif