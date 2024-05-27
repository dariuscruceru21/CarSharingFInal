//
// Created by Alex on 5/27/2024.
//
#include "OrderUi.h"
#include <iostream>

void OrderUi::displayMenu() {
    std::cout << "Order Management System\n";
    std::cout << "1. Create Order\n";
    std::cout << "2. Update Order\n";
    std::cout << "3. Complete Order\n";
    std::cout << "4. Take Over Order\n";
    std::cout << "5. Take Away Order\n";
    std::cout << "6. List Orders\n";
    std::cout << "7. Search Order\n";
    std::cout << "0. Exit\n";
}

void OrderUi::handleUserInput() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createOrder();
                break;
            case 2:
                updateOrder();
                break;
            case 3:
                completeOrder();
                break;
            case 4:
                takeOverOrder();
                break;
            case 5:
                takeAwayOrder();
                break;
            case 6:
                listOrders();
                break;
            case 7:
                searchOrder();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);
}

void OrderUi::createOrder() {
    controller.createOrder();
    std::cout << "Order created successfully.\n";
}

void OrderUi::updateOrder() {
    controller.updateOrder();
    std::cout << "Order updated successfully.\n";
}

void OrderUi::completeOrder() {
    controller.completeOrder();
    std::cout << "Order completed successfully.\n";
}

void OrderUi::takeOverOrder() {
    controller.takeOverOrder();
    std::cout << "Order taken over successfully.\n";
}

void OrderUi::takeAwayOrder() {
    controller.takeAwayOrder();
    std::cout << "Order taken away successfully.\n";
}

void OrderUi::listOrders() {
    auto orders = controller.listOrders();
    for (const auto& order : orders) {
        std::cout << order << std::endl;
    }
}

void OrderUi::searchOrder() {
    auto orders = controller.searchOrder();
    for (const auto& order : orders) {
        std::cout << order << std::endl;
    }
}
