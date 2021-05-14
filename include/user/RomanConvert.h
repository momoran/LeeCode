#ifndef _ROMANCONVERT_H
#define _ROMANCONVERT_H
#include "std_lib.h"
#include "operateLib.h"
#include <string>
#include <map>
namespace {
    std::map<int, std::string> LOOK_TABLE = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"},
    };
};

class RomanConvert : public StdLibBase
{
public:
    RomanConvert() = default;
    virtual ~RomanConvert() override = default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    std::string intToRoman(int num);
    std::string GetSameString(std::string str, int cnt);
    int m_num;
    std::string result;
    std::string hopeResult;
};

#endif