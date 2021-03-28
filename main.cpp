#include <iostream>
#include "mathCalculate.h"
#include "operateLib.h"
#include <map>
#include <tuple>
int main()
{
    std::map<WEEK, std::tuple<std::string, WORD>> person = {
        {MONDAY,     {" is working and eat", 1}},
        {TUESDAY,    {" is working", 2}},
        {WEDNESDAY,  {" is working and sleep", 3}},
        {THURSDAY,   {" is working", 4}},
        {FRIDAY,     {" is working and eat", 5}},
        {SATURDAY,   {" is working, eat and sleep", 6}},
        {SUNDAY,     {" is eat and sleep", 7}},
    };
    WEEK test = WEDNESDAY;
    auto it = person.find(test);
    if (it != person.end()) {
        std::cout << "num = " << std::get<1>(it->second) << std::get<0>(it->second) << std::endl;
    }
    return 0;
}