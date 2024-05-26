#include "UserRepository.h"
#include "fstream"

void UserRepository::readFromCsv() {
    this->users.clear();
    std::ifstream file(this->fileName);
    std::string line;
    while(std::getline(file,line)){
        User user;
        user.fromCsv(line);
        this->users.push_back(user);
    }
    file.close();
}

void UserRepository::writeToCsv() {
    std::ofstream file(this->fileName);
    for(auto& user : this->users)
        file<<user.toCsv()<<"\n";
    file.close();
}


UserRepository::UserRepository(std::string fileName) {
    readFromCsv();
}




//iterates through user vector and searches for the target email
User UserRepository::findUserByEmail(std::string searchedEmail) {
    for(User obj: this->users){
        if(obj.getUserEmail() == searchedEmail)
            return obj;
    }
}

void UserRepository::addUser(User &user) {
    this->users.push_back(user);
    writeToCsv();
}