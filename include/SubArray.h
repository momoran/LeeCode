#ifndef _SUBARRAY_H
#define _SUBARRAY_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class SubArray : public StdLibBase
{
public:
    SubArray();
    virtual ~SubArray();
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int maxSubArray(std::vector<int>& n);
    std::vector<int> nums;
    int result;
    int hopeResult;
};

#endif