#include "ArrayXorEncode.h"
#include <iostream>

WORD ArrayXorEncode::execute()
{
    UpdateTestCase();
    result = decode(m_encodeArray);
    return VerifyResult();
}

std::vector<int> ArrayXorEncode::decode(std::vector<int>& encoded)
{ 
    int arryXorN = 0;
    int encodeLen = encoded.size();
    // 由于解密结果是前n个正整数的排列，同时异或操作和顺序无关，因此可以直接计算出所有正整数异或的结果
    for(int i = 1; i <= encodeLen + 1; i++) {
        arryXorN ^= i;
    }
    // 计算除首个数字外的异或值，奇数部分相或即可达到目的
    int subArrayXor = 0;
    for(int i = 1; i < encodeLen; i+=2) {
        subArrayXor ^= encoded[i];
    }
    std::vector<int> tmpResult = {arryXorN ^ subArrayXor};
    std::cout << arryXorN << " "<< subArrayXor << " " << tmpResult[0] << std::endl;
    for(int i = 0; i < encodeLen; i++) {
        int tmp = tmpResult[i] ^ encoded[i];
        tmpResult.push_back(tmp);
        std::cout << tmp << std::endl;
    }
    return tmpResult;
}

void ArrayXorEncode::UpdateTestCase()
{
    m_encodeArray = {3,1};
    hopeResult = {1,2,3};
}

WORD ArrayXorEncode::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}