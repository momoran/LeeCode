#ifndef _FINDKTHMAXVALUE_H
#define _FINDKTHMAXVALUE_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>
#include <map>

class FindKthMaxValue : public StdLibBase
{
public:
    FindKthMaxValue() = default;
    virtual ~FindKthMaxValue() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int kthLargestValue(std::vector<std::vector<int>>& matrix, int k);
    std::vector<std::vector<int>> m_libMatrix;
    int m_libK;
    int result;
    int hopeResult;
};

#endif