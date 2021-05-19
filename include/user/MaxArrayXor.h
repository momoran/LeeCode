#ifndef _MAXARRAYXOR_H
#define _MAXARRAYXOR_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>
#include <map>

namespace {
    const int MAX_BIT_CNT = 30;
}
class MaxArrayXor : public StdLibBase
{
public:
    MaxArrayXor() = default;
    virtual ~MaxArrayXor() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int findMaximumXOR(std::vector<int>& nums);
    bool isSatifiykbit1(int num, int k);
    std::vector<int> m_numsArray;
    std::map<int, std::vector<int>> m_bitLib;
    int result;
    int hopeResult;
};

#endif