#ifndef _MATCHADD_H
#define _MATCHADD_H
#include "std_lib.h"
#include "operateLib.h"
#include <iostream>

class MatchAdd : public StdLibBase
{
public:
    MatchAdd();
    ~MatchAdd();
    void execute() override;
    
private:
    BYTE a{0};
    BYTE b{0};
};

#endif