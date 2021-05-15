#ifndef _ROMANCONVERT_H
#define _ROMANCONVERT_H
#include "std_lib.h"
#include "operateLib.h"
#include <string>
#include <map>

namespace {
    std::map<int, std::string> LOOK_TABLE = {
        {1,    "I" },
        {4,    "IV"},
        {5,    "V" },
        {9,    "IX"},
        {10,   "X" },
        {40,   "XL"},
        {50,   "L" },
        {90,   "XC"},
        {100,  "C" },
        {400,  "CD"},
        {500,  "D" },
        {900,  "CM"},
        {1000, "M" },
    };

    std::map<char, int> OTHER_TABLE = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
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
    int romanToInt(std::string s);
    std::string GetSameString(std::string str, int cnt);
    int romanToInt2(std::string s);
    // int m_num;
    // std::string result;
    // std::string hopeResult;
    std::string m_str;
    int result;
    int hopeResult;
};

#endif