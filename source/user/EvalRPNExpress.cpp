#include "EvalRPNExpress.h"
#include <iostream>
#include <stack>

WORD EvalRPNExpress::execute()
{
    UpdateTestCase();
    result = evalRPN(m_tokensArray);
    return VerifyResult();
}

int EvalRPNExpress::evalRPN(std::vector<std::string>& tokens)
{ 
    std::stack<std::string> tmpLib;
    std::string digitl = "+-/*";
    for(auto i = 0; i < tokens.size(); i++) {
        if(strstr(digitl.c_str(), tokens[i].c_str()) != nullptr) {
            auto it = CALCULATE_RESULT.find(tokens[i]);
            if (it != CALCULATE_RESULT.end()) {
                int second = std::stoi(tmpLib.top());
                tmpLib.pop();
                int fisrt = std::stoi(tmpLib.top());
                tmpLib.pop();
                tmpLib.push(std::to_string(it->second(fisrt,second)));
            }
        } else {
            tmpLib.push(tokens[i]);
            std::cout << tokens[i] << std::endl;
        }
    }
    std::cout << "result:" << std::stoi(tmpLib.top()) << std::endl;
    return std::stoi(tmpLib.top());
}

void EvalRPNExpress::UpdateTestCase()
{
    std::vector<std::string> tmp = {"2","1","+","3","*"};
    m_tokensArray = tmp;
    hopeResult = 9;
}

WORD EvalRPNExpress::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}