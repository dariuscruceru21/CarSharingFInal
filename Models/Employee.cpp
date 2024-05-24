//
// Created by scoti on 22.05.2024.
//

#include "Employee.h"

Employee::Employee(std::string name, std::string surname, std::string email, std::string position, tm *birthdate,
                   std::string abbreviation, float salary, std::string remarks) {

    this->name = name;
    this->surname = surname;
    this->email = email;
    this->position = position;
    this->birthdate = birthdate;
    this->abbreviation = abbreviation;
    this->salary = salary;
    this->remarks = remarks;
}

Employee::Employee() {}

//getters

std::string Employee::getName() {
    return this->name;
}

std::string Employee::getSurname() {
    return this->surname;
}

std::string Employee::getEmail() {
    return this->email;
}

std::string Employee::getAbbreviation() {
    return this->abbreviation;
}

std::string Employee::getRemarks() {
    return this->remarks;
}

tm *Employee::getBirthdate() {
    return this->birthdate;
}

float Employee::getSalary() {
    return salary;
}

std::string Employee::getPosition() {
    return this->position;
}
//setters

void Employee::setName(std::string newName) {
    this->name = newName;
}

void Employee::setSurname(std::string newSurname) {
    this->surname = newSurname;
}

void Employee::setEmail(std::string newEmail) {
    this->email = newEmail;
}

void Employee::setPosition(std::string newPosition) {
    this->position = newPosition;
}

void Employee::setBirthdate(tm *newBirthdate) {
    this->birthdate = newBirthdate;
}

void Employee::setAbbreviation(std::string newAbbreviation) {
    this->abbreviation = newAbbreviation;
}

void Employee::setSalary(float newSalary) {
    this->salary = newSalary;
}

void Employee::setRemarks(std::string newRemarks) {
    this->remarks = newRemarks;
}

//methode
void Employee::updateProfile() {}