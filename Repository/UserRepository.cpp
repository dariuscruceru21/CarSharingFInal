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

//iterates through user vector and deletes the searched user
void UserRepository::deleteUser(int userId) {
    for (int i = 0; i < users.size(); i++){
        if (users[i].getUserId() == userId){
            users.erase(users.begin() + i);
            break;
        }
    }
    writeToCsv();
}

//iterates through user vector and modifies the attributes of a specified user
void UserRepository::updateUser(User& updatedUser) {
    for (auto& user:users){
        if (user.getUserId() == updatedUser.getUserId()){
            user.setUserFirstName(updatedUser.getUserFirstName());
            user.setUserLastName(updatedUser.getUserLastName());
            user.setUserEmail(updatedUser.getUserEmail());
            user.setUserPassword(updatedUser.getUserPassword());
            break;
        }
    }
    writeToCsv();
}
