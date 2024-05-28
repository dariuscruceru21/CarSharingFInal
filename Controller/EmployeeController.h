//
// Created by scoti on 27.05.2024.
//

#ifndef CARSHARINGFINAL_EMPLOYEECONTROLLER_H
#define CARSHARINGFINAL_EMPLOYEECONTROLLER_H

#include "../Models/Employee.h"
#include "../Repository/EmployeeRepository.h"
#include <vector>
#include <iostream>

class EmployeeController {
private:
    EmployeeRepository employeeRepo;
public:
    EmployeeController(const std::string &filename) : employeeRepo(filename) {}

    void createEmployee();

    void updateEmployee();

    void deleteEmployee();

    void activateDeactivateEmployee();

    void assignRemoveAdminRights();

    void resetPassword();

    void updateProfile();

    std::vector<Employee> listEmployees();

    std::vector<Employee> searchEmployee();

};


#endif //CARSHARINGFINAL_EMPLOYEECONTROLLER_H
