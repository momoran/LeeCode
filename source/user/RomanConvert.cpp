#include "RomanConvert.h"
#include <iostream>

WORD RomanConvert::execute()
{
    UpdateTestCase();
    result = intToRoman(m_num);
    return VerifyResult();
}

std::string RomanConvert::intToRoman(int num)
{ 
    std::string tmp;
    auto last = LOOK_TABLE.rbegin();
    while(last != LOOK_TABLE.rend()) {
        int countStr = num / last->first;
        tmp += GetSameString(last->second, countStr);
        num = num % last->first;
        last++;
    }
    return tmp;
}

std::string RomanConvert::GetSameString(std::string str, int cnt)
{
    std::string tmpStr;
    for(int i = 0; i < cnt; i++) {
        tmpStr += str;
    }
    return tmpStr;
}

void RomanConvert::UpdateTestCase()
{
    m_num = 3;
    hopeResult = "III";
}

WORD RomanConvert::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}