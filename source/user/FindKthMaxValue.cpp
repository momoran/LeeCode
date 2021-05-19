#include "FindKthMaxValue.h"
#include <iostream>
#include <set>
#include <algorithm>

WORD FindKthMaxValue::execute()
{
    UpdateTestCase();
    result = kthLargestValue(m_libMatrix, m_libK);
    return VerifyResult();
}

int FindKthMaxValue::kthLargestValue(std::vector<std::vector<int>>& matrix, int k)
{ 
    std::vector<std::vector<int>> tmpXorArray = matrix;
    for(int i = 0; i < matrix.size(); i++) {
        int sum = 0;
        for(int j = 0; j < matrix[i].size(); j++) {
            sum ^= matrix[i][j];
            tmpXorArray[i][j] = sum;
        }
    }

    std::vector<int> valueTmp(tmpXorArray[0].begin(),tmpXorArray[0].end());
    for(int i = 1; i < tmpXorArray.size(); i++) {
        for(int j = 0; j < tmpXorArray[i].size(); j++) {
            tmpXorArray[i][j] = tmpXorArray[i][j] ^ tmpXorArray[i-1][j];
            valueTmp.push_back(tmpXorArray[i][j]);
        }
    }
    std::sort(valueTmp.begin(), valueTmp.end(),[](int a, int b){return a > b;});

    return valueTmp[k-1];
}


void FindKthMaxValue::UpdateTestCase()
{
    m_libMatrix = {{10,9,5},{2,0,4},{1,0,9},{3,4,8}};
    m_libK = 10;
    hopeResult = 1;
}

WORD FindKthMaxValue::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}