#ifndef _STDLIBOWN_H
#define _STDLIBOWN_H
#include "operateLib.h"

class StdLibBase
{
public:
    StdLibBase() {}
    virtual ~StdLibBase() {}
    virtual WORD execute() = 0;
    virtual void UpdateTestCase() = 0;
    virtual WORD VerifyResult() = 0;
};


#endif
