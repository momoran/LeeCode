#ifndef _SQUARENUM_H
#define _SQUARENUM_H
#include "std_lib.h"
#include "operateLib.h"

class SquareNum : public StdLibBase
{
public:
    SquareNum() = default;
    virtual ~SquareNum() override= default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    bool judgeSquareSum(int c);
    int num;
    bool result;
    bool hopeResult;
};

#endif