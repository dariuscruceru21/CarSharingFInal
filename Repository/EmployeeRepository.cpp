//
// Created by sorin on 5/22/2024.
//

#include "EmployeeRepository.h"

void EmployeeRepository::createEmployee(std::string name, std::string surname, std::string email, std::string position, tm *birthdate,
                                        std::string abbreviation, float salary, std::string remarks) {

    Employee newEmployee(name, surname, email, position, birthdate, abbreviation, salary, remarks);

    employees.push_back(newEmployee);

    //logic to add to csv


}

Employee EmployeeRepository::findEmployeeByName(const std::string& employeeName, const std::string& employeeSurname) {
    for (auto current : employees){//go through customers and check current customer name and surname; if it matches => return it
        if (current.getName() == employeeName && current.getSurname() == employeeSurname){
            return current;
        }
    }

}