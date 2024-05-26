#include "EmployeeRepository.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include "../Models/Employee.h"
#include "fstream"

// Method to list all employees
std::vector<Employee> EmployeeRepository::listAllEmployees() {
    return employees;
}

// Method to find employees by any string (search through various attributes with partial matching)
std::vector<Employee> EmployeeRepository::findEmployeeByString(std::string searchString) {
    // Helper lambda function to convert a string to lowercase
    auto toLower = [](std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower); // Convert each character to lowercase
        return str; // Return the lowercase string
    };

    // Convert the search string to lowercase for case-insensitive comparison
    std::string lowerSearchString = toLower(searchString);

    // Vector to store matching employees
    std::vector<Employee> matchingEmployees;

    // Iterate over all employees in the repository
    for (auto employee : employees) {
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

void EmployeeRepository::createEmployee(std::string name, std::string surname, std::string email, std::string position, std::string birthdate,
                                        std::string abbreviation, float salary, std::string remarks) {
    Employee newEmployee(name, surname, email, position, birthdate, abbreviation, salary, remarks);
    employees.push_back(newEmployee);
    writeToCsv();  // Write to CSV after adding
}

Employee EmployeeRepository::findEmployeeByName(std::string employeeName, std::string employeeSurname) {
    for (auto current : employees) { // Go through employees and check current employee name and surname; if it matches => return it
        if (current.getName() == employeeName && current.getSurname() == employeeSurname) {
            return current;
        }
    }
    throw std::runtime_error("Employee not found");
}
/*
 * ///in opinia mea ii aceasi chestie ca si create,pareri, sanse ,nota ?
void EmployeeRepository::saveEmployee(Employee employee) {
    employees.push_back(employee);
    writeToCsv();  // Write to CSV after saving
}
*/
void EmployeeRepository::deleteEmployee(std::string employeeName, std::string employeeSurname) {
    for (size_t i = 0; i < employees.size(); ++i) {
        if (employees[i].getName() == employeeName && employees[i].getSurname() == employeeSurname) {
            employees.erase(employees.begin() + i);
            writeToCsv();  // Write to CSV after deleting
            return;
        }
    }
    throw std::runtime_error("Employee not found");
}

void EmployeeRepository::updateEmployee(Employee& updatedEmployee) {
    bool found = false;
    for (auto &employee: employees) {
        if (employee.getEmail() == updatedEmployee.getEmail()) {
            employee.setName(updatedEmployee.getName());
            employee.setSurname(updatedEmployee.getSurname());
            employee.setEmail(updatedEmployee.getEmail());
            employee.setPosition(updatedEmployee.getPosition());
            employee.setBirthdate(updatedEmployee.getBirthdate());
            employee.setAbbreviation(updatedEmployee.getAbbreviation());
            employee.setSalary(updatedEmployee.getSalary());
            employee.setRemarks(updatedEmployee.getRemarks());
            found = true;
            break;
        }
    }
    if (!found) {
    throw std::runtime_error("Employee not found");
    }
    writeToCsv();
}
EmployeeRepository::EmployeeRepository(std::string fileName) {
    readFromCsv();
}

void EmployeeRepository::readFromCsv() {
    this->employees.clear();
    std::ifstream file(this->fileName);
    std::string line;
    while (std::getline(file, line)) {
        Employee employee;
        employee.fromCsv(line);
        this->employees.push_back(employee);
    }
    file.close();
}

void EmployeeRepository::writeToCsv() {
    std::ofstream file(this->fileName);
    for (auto& employee : this->employees)
        file << employee.toCsv() << "\n";
    file.close();
}
