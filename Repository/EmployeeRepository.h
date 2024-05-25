//
// Created by sorin on 5/22/2024.
//

#ifndef CARSHARING_EMPLOYEEREPOSITORY_H
#define CARSHARING_EMPLOYEEREPOSITORY_H
#include <vector>
#include "Employee.h"
using namespace std;

class EmployeeRepository {
private:
    std::vector<Employee> employees;


public:
    EmployeeRepository() {}

    ~EmployeeRepository() {}

    void createEmployee();

    auto findEmployeeByName();

    std::vector<Employee> findEmployeeByString();

    auto saveEmployee();

    auto deleteEmployee();

    auto updateEmployee();

    std::vector<Employee> listAllEmployees();

    auto searchEmployee();
};


#endif //CARSHARING_EMPLOYEEREPOSITORY_H
