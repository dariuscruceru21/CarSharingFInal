//
// Created by Andrei on 25.05.2024.
//

#include "CustomerHandlingRepository.h"
#include <regex>
#include "../Models/Customer.h"

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

void CustomerHandlingRepository::createCustomer() {

}

void CustomerHandlingRepository::deleteCustomer() {

}
void CustomerHandlingRepository::updateCustomer() {

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

