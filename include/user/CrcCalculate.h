#ifndef _CRCCALCULATE_H
#define _CRCCALCULATE_H
#include "std_lib.h"
#include "operateLib.h"
#include "CRC.h"
#include <vector>

class CrcCalculate : public StdLibBase
{
public:
    CrcCalculate() = default;
    virtual ~CrcCalculate() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:

    WORD CrcFunTest();

private:
    int result;
    int hopeResult;
};

#endif