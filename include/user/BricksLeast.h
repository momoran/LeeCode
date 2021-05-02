#ifndef _BRICKLEAST_H
#define _BRICKLEAST_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class BricksLeast : public StdLibBase
{
public:
    BricksLeast() = default;
    virtual ~BricksLeast() override= default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int leastBricks(std::vector<std::vector<int>>& wall);
    void GenerateMap(std::vector<std::vector<int>>& wall, std::vector<std::vector<int>>& wallMap);
    std::vector<std::vector<int>> m_wall;
    int result;
    int hopeResult;
};

#endif