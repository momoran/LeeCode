#include <iostream>
#include "operateLib.h"
#include "std_lib.h"
#include "MatchAdd.h"
#include <memory>
#include <map>
#include <string>

int main()
{
    std::map<WORD, std::string> output = {
        {SUCESS, "the result is ok"},
        {FAILURE, "the result is faiure"},
    };
    std::unique_ptr<StdLibBase> ptr(new MatchAdd());
    auto it = output.find(ptr->execute());
    if (it != output.end()) {
        std::cout << it->second << std::endl;
    }
    return 0;
}