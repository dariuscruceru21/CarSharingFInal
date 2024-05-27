//
// Created by demku on 5/22/2024.
//

#ifndef CARSHARING_CUSTOMER_H
#define CARSHARING_CUSTOMER_H

#include <string>
#include <vector>

class Customer {
private:
    std::string name;
    std::string surname;
    std::string phone;
    std::string customerEmail;
    std::string address;
    std::string remarks;
    bool gdprDeleted;
    std::string password;
    std::vector<std::string> favoriteCars;



public:

    Customer(std::string name, std::string surname, std::string phone, std::string customerEmail, std::string address,
             std::string remarks, bool gdprDeleted, std::string password, std::vector<std::string> favoriteCars);

    //pentru default constructor?
    Customer();

    std::string getName() const;

    std::string getSurname() const;

    std::string getPhone() const;

    std::string getAddress() const;

    std::string getRemarks() const;

    std::string getEmail() const;

    bool getGdprDeleted() const;

    void setName(std::string newName);

    void setSurname(std::string newSurname);

    void setPhone(std::string newPhone);

    void setEmail(std::string newEmail);

    void setAddress(std::string newAddress);

    void setRemarks(std::string newRemarks);

    void setGdprDeleted(bool newGdprDeleted);

    //convert to csv format
    std::string toCsv();

    //convert into normal type from csv
    void fromCsv(std::string &csvLine);
};


#endif //CARSHARING_CUSTOMER_H
