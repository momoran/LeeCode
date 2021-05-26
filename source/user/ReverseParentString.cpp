#include "ReverseParentString.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

WORD ReverseParentString::execute()
{
    UpdateTestCase();
    result = reverseParentheses(m_inputStr);
    return VerifyResult();
}

std::string ReverseParentString::reverseParentheses(std::string s)
{ 
    std::stack<char> tmpStack;
    for(int i = 0; i < s.size();i++) {
        if(s[i] == ')') {
            std::queue<char> tmp;
            while(tmpStack.top() != '(') {
                tmp.push(tmpStack.top());
                tmpStack.pop();
            }
            tmpStack.pop();
            while(!tmp.empty()) {
                tmpStack.push(tmp.front());
                tmp.pop();
            }
        } else {
            tmpStack.push(s[i]);
        }
    } 

    std::string result;
    while(!tmpStack.empty()) {
        result += tmpStack.top();
        tmpStack.pop();
    }
    std::reverse(result.begin(), result.end());
    std::cout << result << std::endl;
    return result;
}

void ReverseParentString::UpdateTestCase()
{
    m_inputStr = "(ed(et(oc))el)";
    hopeResult = "leetcode";
}

WORD ReverseParentString::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}