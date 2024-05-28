//
// Created by Andra on 5/27/2024.
//

#ifndef CARSHARINGFINAL_CUSTOMERCONTROLLER_H
#define CARSHARINGFINAL_CUSTOMERCONTROLLER_H



#include "../Repository//CustomerHandlingRepository.h"
class CustomerController {
private:
    CustomerHandlingRepository customerRepo;
public:
    CustomerController(const std::string& fileName) : customerRepo(fileName) {}
    void addCustomer(std::string name, std::string surname, std::string phone, std::string customerEmail, std::string address,
                     std::string remarks, bool gdprDeleted, std::string password, std::vector<std::string> favoriteCars);
    void deleteCustomer(std::string email);
    void updateCustomer(Customer& updatedCustomer);
    std::vector<Customer> listCustomersSorted();
    std::vector<Customer> searchCustomersByEmail(std::string email);
    std::vector<Customer> searchCustomersByPhoneNumber(std::string phoneNumber);
    std::vector<Customer> searchCustomersByName(std::string surname);
};


#endif //CARSHARINGFINAL_CUSTOMERCONTROLLER_H
