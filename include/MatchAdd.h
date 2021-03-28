#ifndef _MATCHADD_H
#define _MATCHADD_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class MatchAdd : public StdLibBase
{
public:
    MatchAdd();
    virtual ~MatchAdd();
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> nums;
    std::vector<int> result;
    std::vector<int> hopeResult;
    int target;
};

#endif