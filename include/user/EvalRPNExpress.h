#ifndef _EVALRPNEXPRESS_H
#define _EVALRPNEXPRESS_H
#include "std_lib.h"
#include "operateLib.h"
#include <stack>
#include <map>
#include <functional>
#include <string.h>
#include <vector>
#include <cstdlib>

namespace {
    std::map<std::string, std::function<int(int, int)>> CALCULATE_RESULT = {
        {"+", [](int value1, int value2){return (value1 + value2);}},
        {"-", [](int value1, int value2){return (value1 - value2);}},
        {"*", [](int value1, int value2){return (value1 * value2);}},
        {"/", [](int value1, int value2){return (value1 / value2);}},
    };
};

class EvalRPNExpress : public StdLibBase
{
public:
    EvalRPNExpress() = default;
    virtual ~EvalRPNExpress() override= default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int evalRPN(std::vector<std::string>& tokens);
    std::vector<std::string> m_tokensArray;
    int result;
    int hopeResult;
};

#endif