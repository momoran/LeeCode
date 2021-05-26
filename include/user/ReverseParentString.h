#ifndef _REVERSEOARENTSTRING_H
#define _REVERSEOARENTSTRING_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>
#include <string>

class ReverseParentString : public StdLibBase
{
public:
    ReverseParentString() = default;
    virtual ~ReverseParentString() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    std::string reverseParentheses(std::string s);
    std::string reverseSting(std::string &s, int first, int end);
    std::string m_inputStr;
    std::string result;
    std::string hopeResult;
};

#endif