#ifndef _BRICKLEAST2_H
#define _BRICKLEAST2_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>
#include <map>

class BricksLeast2 : public StdLibBase
{
public:
    BricksLeast2() = default;
    virtual ~BricksLeast2() override= default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int leastBricks(std::vector<std::vector<int>>& wall);
    std::map<int, int> hashMap;
    std::vector<std::vector<int>> m_wall;
    int result;
    int hopeResult;
};

#endif