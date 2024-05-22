//
// Created by Robert on 5/22/2024.
//

#include "User.h"

User::User(int id, std::string email, std::string password, std::string firstName, std::string lastName) {
    this->id = id;
    this->email = email;
    this->password = password;
    this->firstName = firstName;
    this->lastName = lastName;
}

std::string User::getUserFirstName() const {
    return this->firstName;
}

std::string User::getUserEmail() const {
    return this->email;
}

std::string User::getUserLastName() const {
    return this->lastName;
}

std::string User::getUserPassword() const {
    return this->password;
}

void User::setUserFirstName(std::string newFirstName) {
    this->firstName = newFirstName;
}

void User::setUserLastName(std::string newLastName) {
    this->lastName = newLastName;
}

void User::setUserEmail(std::string newEmail) {
    this->email = newEmail;
}

void User::setUserPassword(std::string newPassword) {
    this->password = newPassword;}
