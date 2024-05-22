//
// Created by demku on 5/22/2024.
//

#include "Customer.h"

void Customer::changePassword() {

}

void Customer::updateRemarks() {

}

void Customer::removeFavoriteCar() {

}

void Customer::addFavoriteCar() {

}

void Customer::viewFavorites() {

}


std::string Customer::getName() {
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
