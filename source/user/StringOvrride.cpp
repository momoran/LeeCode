#include "StringOvrride.h"

WORD StringOvrride::execute()
{
    UpdateTestCase();
    result = strStr(haystack, needle);
    return VerifyResult();
}

int StringOvrride::strStr(std::string source, std::string substr)
{ 
    if (source == substr) {
        return 0;
    }
    for(size_t i = 0; i < source.size(); i++) {
        size_t tmp = i;
        for(size_t j = 0; j < substr.size(); j++) {
            if (source[tmp] != substr[j]) {
                break;
            }
            tmp++;
        }
        if (tmp >= (i+substr.size())) {
            return i;
        }
    }
    return -1;
    
}

void StringOvrride::UpdateTestCase()
{
    haystack ="hello";
    needle = "ll";
    hopeResult = -1;
}

WORD StringOvrride::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}