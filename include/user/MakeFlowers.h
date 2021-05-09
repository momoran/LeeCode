#ifndef _MAKEFLOWERS_H
#define _MAKEFLOWERS_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

class MakeFlowers : public StdLibBase
{
public:
    MakeFlowers() = default;
    virtual ~MakeFlowers() override= default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int minDays(std::vector<int>& bloomDay, int m, int k);
    bool IsLowLimitDay(std::vector<int>& bloomDay, int m, int k, int th);
    std::vector<int> m_bloomDay;
    int m_m;
    int m_k;
    int result;
    int hopeResult;
};

#endif