#ifndef _DYNAMICPROGRAM_H
#define _DYNAMICPROGRAM_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>
#include <map>
#include <string>

class DynamicProgram : public StdLibBase
{
public:
    DynamicProgram() = default;
    virtual ~DynamicProgram() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    bool IsPalindrome(std::string s);
    int MaxChildArrayOrder(std::vector<int> arr);
    std::string longestPalindrome(std::string s);
    std::string m_inputStr;
    std::string result;
    std::string hopeResult;
};

#endif