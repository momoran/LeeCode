#ifndef _STDLIB_H
#define _STDLIB_H
#include "operateLib.h"

class StdLibBase
{
public:
    StdLibBase();
    virtual ~StdLibBase();
    virtual void execute() = 0;
};

#endif
