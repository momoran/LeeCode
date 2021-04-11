#ifndef _UNGLYNUMBERNO_H
#define _UNGLYNUMBERNO_H
#include "std_lib.h"
#include "operateLib.h"
#include <stdint.h>
#include "UnglyNumber.h"

class UnglyNumberNo : public UnglyNumber
{
public:
    UnglyNumberNo();
    virtual ~UnglyNumberNo();
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int nthUglynumber(int n);
    int inputNum;
    int result;
    int hopeResult;
};

#endif