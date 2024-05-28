//
// Created by demku on 5/22/2024.
//

#include "Customer.h"
#include "sstream"
#include <iostream>
#include <vector>

Customer:: Customer(std::string name, std::string surname, std::string phone, std::string customerEmail, std::string address,
                    std::string remarks, bool gdprDeleted, std::string password, std::vector<std::string> favoriteCars){
    this->name = name;
    this->surname = surname;
    this->phone = phone;
    this->customerEmail = customerEmail;
    this->password = password;
    this->address = address;
    this->remarks = remarks;
    this->gdprDeleted = gdprDeleted;
    this->favoriteCars=favoriteCars;


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
    //this->favoriteCars = "";
}

std::string Customer::getName () const {
    return name;
}

std::string Customer::getSurname() const {
    return surname;
}

std::string Customer::getPhone() const{
    return phone;
}

std::string Customer::getAddress()const {
    return address;
}

std::string Customer::getRemarks() const{
    return remarks;
}

bool Customer::getGdprDeleted()const {
    return gdprDeleted;
}

std::string Customer::getPassword() const {
    return password;
}

std::vector<std::string> Customer::getFavoriteCars() const {
    return favoriteCars;
}

void Customer::setPassword(std::string newPassword) {
    this->password=newPassword;
}

void Customer::setFavoriteCars(std::vector<std::string> newFavoriteCars) {
    this->favoriteCars=newFavoriteCars;
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

std::string Customer::toString(){
    std::ostringstream oss;
    oss << "Name: " << name << "\n"
        << "Surname: " << surname << "\n"
        << "Phone: " << phone << "\n"
        << "Email: " << customerEmail << "\n"
        << "Address: " << address << "\n"
        << "Remarks: " << remarks << "\n"
        << "GDPR Deleted: " << (gdprDeleted ? "Yes" : "No") << "\n"
        << "Favorite Cars: ";
    for (const auto &car : favoriteCars) {
        oss << car << " ";
    }
    return oss.str();
}

