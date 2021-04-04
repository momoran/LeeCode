#include "HammingWeight.h"
#include <iostream>
HammingWeight::HammingWeight()
{

}

HammingWeight::~HammingWeight()
{

}

WORD HammingWeight::execute()
{
    UpdateTestCase();
    result = hammingWeight(inputNum);
    return VerifyResult();
}

int HammingWeight::hammingWeight(uint32_t n)
{
    int cnt = 0;
    constexpr BYTE bitCnt = 32;
    uint32_t mask = 0x00000001;
    for (BYTE i = 0; i < 32; i++) {
        if (n & (mask << i)) {
            cnt++;
        }
    }
    std::cout << "cnt:" << cnt << std::endl;
    return cnt;
}

void HammingWeight::UpdateTestCase()
{
    inputNum = 00000000000000000000000000001011;
    hopeResult = 3;
}

WORD HammingWeight::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}