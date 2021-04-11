#ifndef _UNGLYNUMBER_H
#define _UNGLYNUMBER_H
#include "std_lib.h"
#include "operateLib.h"
#include <stdint.h>

class UnglyNumber : public StdLibBase
{
public:
    UnglyNumber();
    virtual ~UnglyNumber();
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    bool isUgly(int n);
    
private:
    int inputNum;
    bool result;
    bool hopeResult;
};

#endif