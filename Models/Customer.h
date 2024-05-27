//
// Created by demku on 5/22/2024.
//

#ifndef CARSHARING_CUSTOMER_H
#define CARSHARING_CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string surname;
    std::string phone;
    std::string customerEmail;
    std::string password;
    std::string address;
    std::string remarks;
    bool gdprDeleted;

public:

    Customer(std::string name, std::string surname, std::string phone, std::string customerEmail, std::string password,std::string address,
             std::string remarks, bool gdprDeleted);

    //pentru default constructor?
    Customer();

    std::string getName() const;

    std::string getPassword() ;


    std::string getSurname();

    std::string getPhone();

    std::string getAddress();

    std::string getRemarks();

    std::string getEmail() ;

    bool getGdprDeleted();

    void setName(std::string newName);

    void setPassword(std::string newPassword);

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

    //method to print out the atributes of a customer for the UI
    std::string toString() {
        return "Name: " + name + ", Surname: " + surname + ", Phone: " + phone + ", Email: " + customerEmail +
               ", Address: " + address + ", Remarks: " + remarks + ", GDPR Deleted: " + (gdprDeleted ? "Yes" : "No");
    }
};


#endif //CARSHARING_CUSTOMER_H
