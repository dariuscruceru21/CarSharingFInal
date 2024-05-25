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

    void createEmployee(std::string name, std::string surname, std::string email, std::string position, tm *birthdate,
                        std::string abbreviation, float salary, std::string remarks);

    Employee findEmployeeByName(const std::string& employeeName, const std::string& employeeSurname);

    std::vector<Employee> findEmployeeByString(const std::string& searchString);


    auto saveEmployee();


    auto deleteEmployee();

    auto updateEmployee();

    std::vector<Employee> listAllEmployees();

    auto searchEmployee();
};


#endif //CARSHARING_EMPLOYEEREPOSITORY_H
