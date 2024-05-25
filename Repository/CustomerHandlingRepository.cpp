//
// Created by Andrei on 25.05.2024.
//

#include "CustomerHandlingRepository.h"
#include <regex>
#include "../Models/Customer.h"

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