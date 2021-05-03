#include "CrcCalculate.h"
#include <iostream>

WORD CrcCalculate::execute()
{
    UpdateTestCase();
    result = CrcFunTest();
    return VerifyResult();
}

WORD CrcCalculate::CrcFunTest()
{
    CRC tmp;
    BYTE tmpString[] = {0x1};
    tmp.GenerateCRCTableNormal();
    tmp.PrintCRC32Table();
    tmp.SetOutFlag(true, false, false);
    tmp.PrintOutFlag();
    std::cout << std::hex << "result:" << tmp.CalculateCRC32Normal(tmpString, sizeof(tmpString))
        << std::endl;
    return SUCESS;
}

void CrcCalculate::UpdateTestCase()
{
    hopeResult = SUCESS;
}

WORD CrcCalculate::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}