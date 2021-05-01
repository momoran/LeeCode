#ifndef _DUPLICATENUM_H
#define _DUPLICATENUM_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class DuplicateNum : public StdLibBase
{
public:
    DuplicateNum() = default;
    virtual ~DuplicateNum() = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t);
    std::vector<int> inputNum;
    int m_k;
    int m_t;
    bool result;
    bool hopeResult;
};

#endif