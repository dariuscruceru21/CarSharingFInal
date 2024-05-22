//
// Created by scoti on 22.05.2024.
//

#ifndef CARSHARINGFINAL_EMPLOYEE_H
#define CARSHARINGFINAL_EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
private:

    std::string name;
    std::string surname;
    std::string email;
    std::string position;
    std::string abbreviation;
    float salary;
    std::string remarks;
    tm *birthdate;

public:

    //constructor
    Employee(std::string name, std::string surname, std::string email, std::string position, tm *birthdate,
             std::string abbreviation, float salary, std::string remarks);

    //getters
    std::string getName();

    std::string getSurname();

    std::string getEmail();

    std::string getPosition();

    std::string getAbbreviation();

    float getSalary();

    std::string getRemarks();

    tm *getBirthdate();

    //setters
    void setPosition(std::string newPosition);

    void setBirthdate(tm* newBirthdate);

    void setAbbreviation(std::string newAbbreviation);

    void setSalary(float newSalary);

    void setEmail(std::string newEmail);

    void setName(std::string newName);

    void setSurname(std::string newSurname);

    void setRemarks(std::string newRemarks);

    //methode
    void updateProfile();

};


#endif //CARSHARINGFINAL_EMPLOYEE_H
