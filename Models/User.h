//
// Created by Robert on 5/22/2024.
//

#ifndef CARSHARINGFINAL_USER_H
#define CARSHARINGFINAL_USER_H
#include <string>

class User {
private:
    int id;
    std::string email;
    std::string password;
    std::string firstName;
    std::string lastName;

public:
    User(int id, std::string email, std::string password, std::string firstName, std::string lastName);
    User();
    bool login();

    std::string getUserEmail() const;
    std::string getUserPassword() const;
    std::string getUserFirstName() const;
    std::string getUserLastName() const;
    int getUserId() const;

    void setUserFirstName(std::string newFirstName);
    void setUserLastName(std::string newLastName);
    void setUserPassword(std::string newPassword);
    void setUserEmail(std::string newEmail);

    //convert to csv format
    std::string toCsv();

    //convert into normal type from csv
    void fromCsv(std::string& csvLine);

};


#endif //CARSHARINGFINAL_USER_H
