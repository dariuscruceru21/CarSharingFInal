//
// Created by Alex on 5/27/2024.
//

#ifndef CARSHARINGFINAL_ORDERUI_H
#define CARSHARINGFINAL_ORDERUI_H

#include "../Controller/OrderController.h"
#include <iostream>

class OrderUi {
private:
    OrderController controller;

public:
    OrderUi(OrderController& controller) : controller(controller) {}
    void displayMenu();
    void handleUserInput(int userType);
    void createOrder();
    void updateOrder();
    void completeOrder();
    void takeOverOrder();
    void takeAwayOrder();
    void listOrders();
    void searchOrder();
    int removeOrder();
};


#endif //CARSHARINGFINAL_ORDERUI_H
