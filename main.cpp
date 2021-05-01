#include "CommonInterferce.h"

int main()
{
    std::map<WORD, std::string> output = {
        {SUCESS, "the result is ok"},
        {FAILURE, "the result is faiure"},
        {INVALID, "please init result"},
    };
    std::unique_ptr<StdLibBase> ptr(new xmlLoad());
    auto it = output.find(ptr->execute());
    if (it != output.end()) {
        std::cout << it->second << std::endl;
    }
    return 0;
}