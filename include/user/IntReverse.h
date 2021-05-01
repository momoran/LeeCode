#ifndef _INTREVERSE_H
#define _INTREVERSE_H
#include "std_lib.h"
#include "operateLib.h"

class IntReverse : public StdLibBase
{
public:
    IntReverse();
    virtual ~IntReverse();
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int reverse(int x);
    int nums;
    int result;
    int hopeResult;
};

#endif