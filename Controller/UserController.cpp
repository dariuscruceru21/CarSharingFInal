//
// Created by Darius on 5/27/2024.
//

#include "UserController.h"

User UserController::findUserByEmail(std::string searchedEmail) {
    return this->userRepo.findUserByEmail(searchedEmail);
}

void UserController::addUser(User &user) {
    this->userRepo.addUser(user);
}

void UserController::deleteUser(int userId) {
    this->userRepo.deleteUser(userId);
}

void UserController::updateUser(User &updatedUser) {
    this->userRepo.updateUser(updatedUser);
}
