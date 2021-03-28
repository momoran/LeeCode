#ifndef _MATCHADD_H
#define _MATCHADD_H
#include "std_lib.h"
#include "operateLib.h"

class MatchAdd : public StdLibBase
{
public:
    MatchAdd();
    virtual ~MatchAdd();
    virtual int execute() override;

private:
    int a{2};
    int b{1};
};

#endif