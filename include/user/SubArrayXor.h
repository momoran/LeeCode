#ifndef _SUBARRAYXOR_H
#define _SUBARRAYXOR_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class SubArrayXor : public StdLibBase
{
public:
    SubArrayXor() = default;
    virtual ~SubArrayXor() override= default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries);
    int GetXorResult(std::vector<int>& arr, std::vector<int> &subArray);
    void HandleXorResult();
    std::vector<std::vector<int>> m_queries;
    std::vector<int> m_array;
    std::vector<int> m_xorLib{0};
    std::vector<int> result;
    std::vector<int> hopeResult;
};

#endif