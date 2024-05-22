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
    std::string address;
    std::string remarks;
    bool gdprDeleted;

public:
    void changePassword();

    void updateRemarks();

    void addFavoriteCar();

    void removeFavoriteCar();

    void viewFavorites();

    std::string getName();

    std::string getSurname();

    std::string getPhone();

    std::string getAddress();

    std::string getRemarks();

    bool getGdprDeleted();

    void setName(std::string newName);

    void setSurname(std::string newSurname);

    void setPhone(std::string newPhone);

    void setAddress(std::string newAddress);

    void setRemarks(std::string newRemarks);

    void setGdprDeleted(bool newGdprDeleted);
};


#endif //CARSHARING_CUSTOMER_H
