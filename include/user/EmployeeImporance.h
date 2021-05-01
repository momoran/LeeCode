#ifndef _EMPLOYEEIMPORANCE_H
#define _EMPLOYEEIMPORANCE_H
#include "std_lib.h"
#include "operateLib.h"
#include <vector>

struct Employee {
    int id;
    int importance;
    std::vector<int> subordinates;
};

class EmployeeImporance : public StdLibBase
{
public:
    EmployeeImporance() = default;
    virtual ~EmployeeImporance() override= default;
    WORD execute() override;
    void UpdateTestCase() override;
    WORD VerifyResult() override;
    
private:
    int getImportance(std::vector<Employee> employees, int id);
    std::vector<Employee> m_enployees;
    int m_id;
    int result;
    int hopeResult;
};

#endif