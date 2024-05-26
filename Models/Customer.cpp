//
// Created by demku on 5/22/2024.
//

#include "Customer.h"
#include "sstream"
#include <iostream>
#include <vector>

Customer::Customer(std::string name, std::string surname, std::string phone, std::string customerEmail,
                   std::string address, std::string remarks, bool gdprDeleted) {
    this->name = name;
    this->surname = surname;
    this->phone = phone;
    this->customerEmail = customerEmail;
    this->address = address;
    this->remarks = remarks;
    this->gdprDeleted = gdprDeleted;

}
//default constructor?
Customer::Customer() {
    this->name = "";
    this->surname = "";
    this->phone = "";
    this->customerEmail = "";
    this->address = "";
    this->remarks = "";
    this->gdprDeleted = false;
}

void Customer::changePassword() {
    std::string oldPassword, newPassword;
    std::cout << "Enter your old password: ";
    std::cin >> oldPassword;
    std::cout << "Enter your new password: ";
    std::cin >> newPassword;
    std::cout << "Password changed successfully.\n";
}

void Customer::updateRemarks() {
    std::string newRemarks;
    std::cout << "Enter new remarks: ";
    std::cin.ignore(); //o sa ignore "\n" din ce primeste ca input
    std::getline(std::cin, newRemarks);
    this->remarks = newRemarks;
    std::cout << "Remarks updated successfully.\n";
}

void Customer::removeFavoriteCar() {
    std::string car;
    std::cout << "Enter the car to remove from favorites: ";
    std::cin.ignore();
    std::getline(std::cin, car);
    std::cout << "Car removed from favorites.\n";
}

void Customer::addFavoriteCar() {
    std::string car;
    std::cout << "Enter the car to add to favorites: ";
    std::cin.ignore();
    std::getline(std::cin, car);
    std::cout << "Car added to favorites.\n";
}
//nu stiu daca e ok metoda asta
void Customer::viewFavorites() {
    std::vector<std::string> favorites = {"Car1", "Car2", "Car3"};
    std::cout << "Favorite cars:\n";
    for (const auto& car : favorites) {
        std::cout << car << "\n";
    }
}


std::string Customer::getName () const {
    return name;
}

std::string Customer::getSurname() {
    return surname;
}

std::string Customer::getPhone() {
    return phone;
}

std::string Customer::getAddress() {
    return address;
}

std::string Customer::getRemarks() {
    return remarks;
}

bool Customer::getGdprDeleted() {
    return gdprDeleted;
}


void Customer::setName(std::string newName) {
    this->name = newName;
}

void Customer::setSurname(std::string newSurname) {
    this->surname = newSurname;
}

void Customer::setPhone(std::string newPhone) {
    this->phone = newPhone;
}

void Customer::setAddress(std::string newAddress) {
    this->address = newAddress;
}

void Customer::setRemarks(std::string newRemarks) {
    this->remarks = newRemarks;
}

void Customer::setGdprDeleted(bool newGdprDeleted) {
    this->gdprDeleted = newGdprDeleted;
}

std::string Customer::toCsv() {
    std::ostringstream oss;
    oss << this->name<<","<<this->surname<<","<<this->phone<<","<<this->customerEmail<<","<<this->address<<","<<this->remarks<<","<<this->gdprDeleted;
}

void Customer::fromCsv(std::string &csvLine) {

    std::istringstream ss(csvLine);
    std::getline(ss,this->name,',');
    std::getline(ss,this->surname,',');
    std::getline(ss,this->phone,',');
    std::getline(ss,this->customerEmail,',');
    std::getline(ss,this->address,',');
    std::getline(ss,this->remarks,',');
    ss>>this->gdprDeleted;
    ss.ignore(1);//ignores comma
}



