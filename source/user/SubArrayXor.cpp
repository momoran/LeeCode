#include "SubArrayXor.h"
#include <iostream>

WORD SubArrayXor::execute()
{
    UpdateTestCase();
    result = xorQueries(m_array, m_queries);
    return VerifyResult();
}

std::vector<int> SubArrayXor::xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries)
{ 
    HandleXorResult();
    std::vector<int> tmp;
    for(int i = 0; i < queries.size(); i++) {
        int tmpResult = GetXorResult(arr, queries[i]);
        tmp.push_back(tmpResult);
    }
    return tmp;
}

int SubArrayXor::GetXorResult(std::vector<int>& arr, std::vector<int> &subArray)
{
    return m_xorLib.at(subArray[0]) ^ m_xorLib.at(subArray[1]+1);
}

void SubArrayXor::HandleXorResult()
{
    int tmp = 0;
    for(int i = 0; i < m_array.size();i++) {
       tmp ^= m_array[i];
       m_xorLib.push_back(tmp);
    }
}

void SubArrayXor::UpdateTestCase()
{
    std::vector<int> tmpArr = {1,3,4,8};
    std::vector<std::vector<int>> tmpQueries = {
        {0,1},{1,2},{0,3},{3,3}
    };
    m_queries = tmpQueries;
    m_array = tmpArr;
    hopeResult = {2,7,14,8};
}

WORD SubArrayXor::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}