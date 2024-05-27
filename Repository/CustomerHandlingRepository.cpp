//
// Created by Andrei on 25.05.2024.
//

#include "CustomerHandlingRepository.h"
#include <regex>
#include <algorithm>
#include "../Models/Customer.h"
#include <iostream>

CustomerHandlingRepository::CustomerHandlingRepository(const std::string& fileName) {
    readFromCsv();
}

void CustomerHandlingRepository::readFromCsv() {
    this->Customers.clear();
    std::ifstream file(this->fileName);
    std::string line;
    while(std::getline(file,line)){
        Customer customer;
        customer.fromCsv(line);
        this->Customers.push_back(customer);
    }
    file.close();
}

void CustomerHandlingRepository::writeToCsv() {
    std::ofstream file(this->fileName);
    for(auto& customer : this->Customers)
        file<<customer.toCsv()<<"\n";
    file.close();
}

void CustomerHandlingRepository::createCustomer(std::string name, std::string surname, std::string customerEmail, std::string customerPassword, std::string address, std::string remarks, std::string phone,
                                                bool gdprDeleted) {
    Customer newCustomer(name, surname, phone, customerEmail, customerPassword, address, remarks, gdprDeleted);
    Customers.push_back(newCustomer);
    Customers.push_back(newCustomer);
    writeToCsv();

}

void CustomerHandlingRepository::deleteCustomer(std::string email) {
    for (int i = 0; i < Customers.size(); i++){
        if (Customers[i].getEmail() == email){
            Customers.erase(Customers.begin() + i);
            break;
        }
    }
    writeToCsv();
}
void CustomerHandlingRepository::updateCustomer(Customer& updatedCustomer) {
    for (auto& customer:Customers){
        if (customer.getEmail() == updatedCustomer.getEmail()){
            customer.setName(updatedCustomer.getName());
            customer.setAddress(updatedCustomer.getAddress());
            customer.setGdprDeleted(updatedCustomer.getGdprDeleted());
            customer.setPhone(updatedCustomer.getPhone());
            customer.setSurname(updatedCustomer.getSurname());
            customer.setRemarks(updatedCustomer.getRemarks());
            break;
        }
    }
    writeToCsv();
}


bool CustomerHandlingRepository::checkFormatEmail(Customer c) {
    std::string email = c.getEmail();
    const std::regex pattern(R"(^[a-zA-Z]+(?:\.[a-zA-Z]+)?@[a-zA-Z]+\.[a-zA-Z]{2,}$)");

    return std::regex_match(email, pattern);
}

bool CustomerHandlingRepository::checkFormatPhoneNumber(Customer c) {
    std::string phone = c.getPhone();

    const std::regex pattern(R"(^\+\d{2} \d{9}$)");

    return std::regex_match(phone, pattern);
}

bool CustomerHandlingRepository::checkUniqueEmail(Customer c) {
    std::string email = c.getEmail();
    int flagUnique = 1;

    for (auto current : Customers){
        if (current.getEmail() == email){
            flagUnique = 0;
        }
    }

    return flagUnique == 1;
}

//see header for details
bool CustomerHandlingRepository::validateProfileByGDPR(Customer c) {
    bool gdprDeleted = c.getGdprDeleted();

    //if gdpr is deleted
    if (gdprDeleted){
        if (c.getSurname().empty() || c.getName().empty()){
            return false;
        } else{
            return true;
        }

    }else{
        if (c.getSurname().empty() || c.getName().empty() || c.getEmail().empty() ||
        c.getPhone().empty() || c.getAddress().empty()){
            return false;
        } else{
            return true;
        }
    }

    //use case in UI:
    //if method returns false => display message : Error in creating customer. One/several mandatory fields must be completed according to GDPR

}

std::vector<Customer> CustomerHandlingRepository::listCustomersSortedByName() {
    std::vector<Customer> sortedCustomers = Customers; // Create a copy of the Customers vector
    std::sort(sortedCustomers.begin(), sortedCustomers.end(), [](const Customer& a, const Customer& b) {
        return a.getName() < b.getName();
    });
    return sortedCustomers; // Return the sorted vector
}

std::vector<Customer> CustomerHandlingRepository::searchCustomersByEmail(std::string email) {
    std::vector<Customer> results;
    for (auto &customer: Customers) {
        if (customer.getEmail() == email) {
            results.push_back(customer);
        }
    }
    return results;
}

std::vector<Customer> CustomerHandlingRepository::searchCustomersByPhoneNumber(std::string phoneNumber) {
    std::vector<Customer> results;
    for (auto &customer: Customers) {
        if (customer.getPhone() == phoneNumber) {
            results.push_back(customer);
        }
    }
    return results;
}

std::vector<Customer> CustomerHandlingRepository::searchCustomersByName(std::string surname) {
    std::vector<Customer> results;
    for (auto &customer: Customers) {
        if (customer.getSurname() == surname) {
            results.push_back(customer);
        }
    }
    return results;
}

std::vector<Customer> CustomerHandlingRepository::geterCustomers() {
    return this->Customers;
}
/std::vector<Customer> CustomerHandlingRepository::geterCustomers() {
    return this->Customers;
}

void CustomerHandlingRepository::changeCustomerPassword(std::string newPassword, std::string emailToSearchBy) {
    for (auto customer : Customers){
        if (customer.getEmail() == emailToSearchBy){
            customer.setPassword(newPassword);
        }
    }
    writeToCsv();
}

void CustomerHandlingRepository::changeCustomerRemarks(std::string newRemarks, std::string emailToearchBy) {
    for (auto customer : Customers){
        if (customer.getEmail() == emailToearchBy){
            customer.setRemarks(newRemarks);
        }
    }
    writeToCsv();
}

void CustomerHandlingRepository::addFavouriteCar(Car newCar) {
    favouriteCars.push_back(newCar);
}

void CustomerHandlingRepository::removeFavoriteCar(Car carToRemove) {
    for (int i = 0;i < favouriteCars.size();i++){
        auto current = favouriteCars[i];
        if (current.getLicensePlate() == carToRemove.getLicensePlate() && current.getModel() == carToRemove.getModel() &&
                current.getBrand() == carToRemove.getBrand() && current.getYearOfFirstRegistration() == carToRemove.getYearOfFirstRegistration() &&
                current.getMileage() == carToRemove.getMileage() && current.getDailyRate() == carToRemove.getDailyRate() &&
                current.getFuelType() == carToRemove.getFuelType() && current.getTransmission() == carToRemove.getTransmission() &&
                current.getColor() == carToRemove.getColor() && current.getisActive() == carToRemove.getisActive()) {

            favouriteCars.erase(favouriteCars.begin() + 1);
        }
    }
}

void CustomerHandlingRepository::viewFavouriteCars() {
    for (auto current : favouriteCars){
        std::cout << current.getLicensePlate() << " " << current.getModel() << " " << current.getBrand() << " " << current.getYearOfFirstRegistration() << " " << current.getMileage() << " " << current.getDailyRate() << " " << current.getFuelType() << " " << current.getTransmission() << current.getColor() << " " << current.getRemarks() << " " << current.getisActive() << '\n';
    }
}
