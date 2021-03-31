#ifndef _HAMMINGWEIGHT_H
#define _HAMMINGWEIGHT_H
#include "std_lib.h"
#include "operateLib.h"
#include <stdint.h>

class HammingWeight : public StdLibBase
{
public:
    HammingWeight();
    virtual ~HammingWeight();
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int hammingWeightc(uint32_t n);
    uint32_t inputNum;
    int result;
    int hopeResult;
};

#endif