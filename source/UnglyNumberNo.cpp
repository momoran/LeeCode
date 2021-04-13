#include "UnglyNumberNo.h"
#include <iostream>
#include <set>
#include <algorithm>

UnglyNumberNo::UnglyNumberNo()
{

}

UnglyNumberNo::~UnglyNumberNo()
{

}

WORD UnglyNumberNo::execute()
{
    UpdateTestCase();
    result = nthUglynumber(inputNum);
    return VerifyResult();
}

int UnglyNumberNo::nthUglynumber(int n)
{
/*    int index = 0;
    while (n > 0) {
        index++;
        if (isUgly(index)) {
            n--;
            std::cout << "number is:" << index << std::endl;
        }
    }
    std::cout << "next number is:" << index << std::endl;
*/
    std::set<int> lib = {1, 2, 3};
    std::set<int> tmpResult = {2, 3, 5, 4, 6, 10, 6, 9, 15};
    auto size = lib.size();
    while (size < n)
    {
        auto it = find_if(tmpResult.begin(), tmpResult.end(), [&](int temp) -> bool{
            return temp > *(lib.rbegin());
        });
        long tempNum = *it;
        lib.insert(static_cast<int>(tempNum));
        int array2[] = {tempNum * 2, tempNum * 3, tempNum * 5};
        tmpResult.insert(array2, array2 + 3);
        std::cout << "number:" << *it << "last:" << *(lib.rbegin()) << std::endl;
        size = lib.size();
    }
    auto first = lib.begin();
    int index = 1;
    while(first != lib.end()) {
        if (index == n) {
            return *first;
        }
        index++;
        first++;
    }
    return 0;
}

void UnglyNumberNo::UpdateTestCase()
{
    inputNum = 10;
    hopeResult = 12;
}

WORD UnglyNumberNo::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}