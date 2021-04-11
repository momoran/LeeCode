#include "UnglyNumberNo.h"
#include <iostream>
#include <set>

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
    /*int index = 0;
    while (n > 0) {
        index++;
        if (isUgly(index)) {
            n--;
            std::cout << "number is:" << index << std::endl;
        }
    }
    std::cout << "next number is:" << index << std::endl;*/
    int array[3] = {1, 2, 3};
    int array1[3] = {2, 3, 5};
    std::set<int> lib(array, array + 3);
    int size = lib.size();
    //while (size <= n) {
        auto last = lib.end();
        int index = 0;
        while (index < 3) {
            last--;
            array1[index] = (*last) * 2;
            std::cout << "number is: " << array1[index] << std::endl;
            index ++;
        }
        
    //}
    return 1;
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