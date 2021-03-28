#ifndef _STDLIBOWN_H
#define _STDLIBOWN_H
#include "operateLib.h"
class StdLibBase
{
public:
    StdLibBase() {}
    virtual ~StdLibBase() {}
    virtual int execute() = 0;
};


#endif
