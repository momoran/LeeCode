#ifndef _REMOVEDUPLICATENUM_H
#define _REMOVEDUPLICATENUM_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class RemoveDuplicateNum : public StdLibBase
{
public:
    RemoveDuplicateNum() = default;
    virtual ~RemoveDuplicateNum() = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int removeDuplicates(std::vector<int>& nums);
    std::vector<int> inputNum;
    std::vector<int> hopArray;
    int result;
    int hopeResult;
};

#endif