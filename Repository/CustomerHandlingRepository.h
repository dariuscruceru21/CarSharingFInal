//
// Created by Andrei on 25.05.2024.
//

#ifndef CARSHARINGFINAL_CUSTOMERHANDLINGREPOSITORY_H
#define CARSHARINGFINAL_CUSTOMERHANDLINGREPOSITORY_H

#include <vector>
#include "../Models/Customer.h"

class CustomerHandlingRepository {
private:
    std::vector<Customer> Customers;
public:
    // Only Employees are allowed to create, delete and update clients
    // Only Employees are allowed to see Client related data

    // Client Handling functions
    void createCustomer();

    void deleteCustomer();

    void updateCustomer();

    // GDPR related functions
    void anonymizeCustomer();

    // Listing functions
    void listCustomersSortedByName();

    // Search functions
    void searchCustomersByEmail();

    void searchCustomersByPhoneNumber();

    void searchCustomersByName();

    void searchCustomersByCar();

    // Profile editing functions
    void changeCustomerPassword();

    void changeCustomerNotes();

    void addCarToFavorites();

    void removeCarFromFavorites();

    //Validation functions

    bool checkUniqueEmail(Customer c);

    //email format: firstname.lastname@smth.com
    bool checkFormatEmail(Customer c);

    //phone format: +00 123456789
    bool checkFormatPhoneNumber(Customer c);

    void validateProfileByGDPR();


};


#endif //CARSHARINGFINAL_CUSTOMERHANDLINGREPOSITORY_H
