#ifndef _PREFIX_H
#define _PREFIX_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class Prefix : public StdLibBase
{
public:
    Prefix() = default;
    virtual ~Prefix() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int findMaxLength(std::vector<int>& nums);
    std::vector<int> m_numsLib;
    int result;
    int hopeResult;
};

#endif