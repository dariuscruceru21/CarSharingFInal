//
// Created by sorin on 5/22/2024.
//

#include "EmployeeRepository.h"
#include <algorithm>
#include <cctype>


// Method to list all employees
std::vector<Employee> EmployeeRepository::listAllEmployees() {
    return employees;
}

// Method to find employees by any string (search through various attributes with partial matching)
std::vector<Employee> EmployeeRepository::findEmployeeByString(const std::string& searchString) {
    // Helper lambda function to convert a string to lowercase
    auto toLower = [](const std::string& str) {
        std::string lowerStr = str; // Create a copy of the input string
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower); // Convert each character to lowercase
        return lowerStr; // Return the lowercase string
    };

    // Convert the search string to lowercase for case-insensitive comparison
    std::string lowerSearchString = toLower(searchString);

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
    // Vector to store matching employees
    std::vector<Employee> matchingEmployees;

    // Iterate over all employees in the repository
    for (const auto& employee : employees) {
        // Convert each employee attribute to lowercase and check if the search string is a substring
        if (toLower(employee.getName()).find(lowerSearchString) != std::string::npos || // Check if name contains the search string
            toLower(employee.getSurname()).find(lowerSearchString) != std::string::npos || // Check if surname contains the search string
            toLower(employee.getEmail()).find(lowerSearchString) != std::string::npos || // Check if email contains the search string
            toLower(employee.getPosition()).find(lowerSearchString) != std::string::npos || // Check if position contains the search string
            toLower(employee.getAbbreviation()).find(lowerSearchString) != std::string::npos || // Check if abbreviation contains the search string
            toLower(employee.getRemarks()).find(lowerSearchString) != std::string::npos) { // Check if remarks contain the search string
            // If any attribute contains the search string, add the employee to the matchingEmployees vector
            matchingEmployees.push_back(employee);
        }
    }

    // Return the vector of matching employees
    return matchingEmployees;
}