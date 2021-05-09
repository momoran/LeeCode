#include "MakeFlowers.h"
#include <iostream>
#include <set>

WORD MakeFlowers::execute()
{
    UpdateTestCase();
    result = minDays(m_bloomDay, m_m, m_k);
    return VerifyResult();
}

int MakeFlowers::minDays(std::vector<int>& bloomDay, int m, int k)
{ 
    if (m * k > bloomDay.size()) {
        return -1;
    }
    std::set<int> lib(bloomDay.begin(), bloomDay.end());
    int min = *lib.begin();
    int max = *lib.rbegin();
    std::cout << min << "max" << max << std::endl;
    while(min < max) {
        int mid = (min + max) / 2;
        if (IsLowLimitDay(bloomDay, m, k, mid)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    std::cout << "result:" << min << "max:" << max << std::endl;
    return max;
}

bool MakeFlowers::IsLowLimitDay(std::vector<int>& bloomDay, int m, int k, int th)
{
    int total = 0;
    int frequence = 0;
    for(auto i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] > th) {
            frequence = 0;
        } else {
            frequence++;
        }
        if (frequence >= k) {
            total++;
            frequence = 0;
        }
    }
    return (total >= m);
}

void MakeFlowers::UpdateTestCase()
{
    std::vector<int> tmp = {7,7,7,7,12,7,7};
    m_bloomDay = tmp;
    m_m = 2;
    m_k = 3;
    hopeResult = 12;
}

WORD MakeFlowers::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}