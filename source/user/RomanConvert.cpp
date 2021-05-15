#include "RomanConvert.h"
#include <iostream>
#include <cstring>
WORD RomanConvert::execute()
{
    UpdateTestCase();
    result = romanToInt2(m_str);
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

int RomanConvert::romanToInt(std::string s)
{ 
    int tmp = 0;
    std::string tmpStr = s;
    auto last = LOOK_TABLE.rbegin();
    while(last != LOOK_TABLE.rend()) {
        while(!tmpStr.empty()) {
            if(strncmp(tmpStr.c_str(), last->second.c_str(), last->second.size()) != 0) {
                break;
            }
            tmp += last->first;
            tmpStr.erase(0, last->second.size());
            std::cout << last->first << " " << tmp << std::endl;
        }
        last++;
    }
    std::cout << tmp << std::endl;
    return tmp;
}

int RomanConvert::romanToInt2(std::string s)
{
    int tmp = 0;
    int strLen = s.size();
    for(auto i = 0; i < strLen; i++) {
        if (i < (strLen - 1) && OTHER_TABLE.at(s[i]) < OTHER_TABLE.at(s[i+1])) {
            tmp -= OTHER_TABLE.at(s[i]);
        } else {
            tmp += OTHER_TABLE.at(s[i]);
        }
    }
    return tmp;
}

void RomanConvert::UpdateTestCase()
{
    m_str = "LVIII";
    hopeResult = 58;
}

WORD RomanConvert::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}