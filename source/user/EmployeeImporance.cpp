#include "EmployeeImporance.h"
#include <iostream>
WORD EmployeeImporance::execute()
{
    UpdateTestCase();
    result = getImportance(m_enployees, m_id);
    return VerifyResult();
}

int EmployeeImporance::getImportance(std::vector<Employee> employees, int id)
{ 
    int importance = 0;
    auto it = employees.begin();
    while(it != employees.end()) {
        if (it->id == id) {
            if (it->subordinates.size() < 1) {
                return it->importance;
            }
            for(auto i = 0; i < it->subordinates.size(); i++) {
                importance += getImportance(employees, it->subordinates[i]);
                std::cout << "id:" << id << " importance is " << importance << std::endl;
            }
            importance += it->importance;
            break;
        }
        it++;
    }
    std::cout << "id:" << id << "importance is " << importance << std::endl;
    return importance;
}

void EmployeeImporance::UpdateTestCase()
{
    std::vector<Employee> tmp = {
        {1, 5, {2, 3}}, 
        {2, 3, {}}, 
        {3, 3, {}},
    };
    m_enployees = tmp;
    m_id = 1;
    hopeResult = 11;
}

WORD EmployeeImporance::VerifyResult()
{
    if (hopeResult == result) {
        return SUCESS;
    }
    return FAILURE;
}