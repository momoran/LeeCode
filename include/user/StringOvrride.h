#ifndef _STRINGOVRRIDE_H
#define _STRINGOVRRIDE_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>
#include <string>

class StringOvrride : public StdLibBase
{
public:
    StringOvrride() = default;
    virtual ~StringOvrride() = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int strStr(std::string haystack, std::string needle);
    std::string haystack;
    std::string needle;
    int result;
    int hopeResult;
};

#endif