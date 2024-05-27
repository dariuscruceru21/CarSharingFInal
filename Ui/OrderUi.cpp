#include "OrderUi.h"
#include <iomanip>
#include <string>

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
    float totalCost;
    std::string observation;
    Customer user;
    tm start = {}, end = {};
    Car car;
    Employee employee;

    std::cout << "Enter total cost: ";
    std::cin >> totalCost;
    std::cin.ignore();

    std::cout << "Enter observation: ";
    std::getline(std::cin, observation);

    std::string customerName, customerContact;
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);
    std::cout << "Enter customer contact: ";
    std::getline(std::cin, customerContact);
    user.setName(customerName);
    user.setPhone(customerContact);

    std::cout << "Enter start time (year month day hour minute): ";
    std::cin >> start.tm_year >> start.tm_mon >> start.tm_mday >> start.tm_hour >> start.tm_min;
    start.tm_year -= 2000;
    start.tm_mon -= 1;

    std::cout << "Enter end time (year month day hour minute): ";
    std::cin >> end.tm_year >> end.tm_mon >> end.tm_mday >> end.tm_hour >> end.tm_min;
    end.tm_year -= 2000;
    end.tm_mon -= 1;

    std::string carMake, carModel, carPlate;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter car make: ";
    std::getline(std::cin, carMake);
    std::cout << "Enter car model: ";
    std::getline(std::cin, carModel);
    std::cout << "Enter car plate number: ";
    std::getline(std::cin, carPlate);
    car.setModel(carMake);
    car.setModel(carModel);
    car.setLicensePlate(carPlate);

    std::string employeeName, employeePosition;
    std::cout << "Enter employee name: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter employee position: ";
    std::getline(std::cin, employeePosition);
    employee.setName(employeeName);
    employee.setPosition(employeePosition);

    controller.createOrder(totalCost, observation, user, start, end, car, employee);
    std::cout << "Order created successfully.\n";
}

void OrderUi::updateOrder() {
    float totalCost;
    std::string observation;
    Customer user;
    tm start = {}, end = {};
    Car car;
    Employee employee;
    int id;

    std::cout << "Enter order ID to update: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter total cost: ";
    std::cin >> totalCost;
    std::cin.ignore();

    std::cout << "Enter observation: ";
    std::getline(std::cin, observation);

    std::string customerName, customerContact;
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);
    std::cout << "Enter customer contact: ";
    std::getline(std::cin, customerContact);
    user.setName(customerName);
    user.setPhone(customerContact);

    std::cout << "Enter start time (year month day hour minute): ";
    std::cin >> start.tm_year >> start.tm_mon >> start.tm_mday >> start.tm_hour >> start.tm_min;
    start.tm_year -= 2000;
    start.tm_mon -= 1;

    std::cout << "Enter end time (year month day hour minute): ";
    std::cin >> end.tm_year >> end.tm_mon >> end.tm_mday >> end.tm_hour >> end.tm_min;
    end.tm_year -= 2000;
    end.tm_mon -= 1;

    std::string carMake, carModel, carPlate;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter car make: ";
    std::getline(std::cin, carMake);
    std::cout << "Enter car model: ";
    std::getline(std::cin, carModel);
    std::cout << "Enter car plate number: ";
    std::getline(std::cin, carPlate);
    car.setModel(carMake);
    car.setModel(carModel);
    car.setLicensePlate(carPlate);

    std::string employeeName, employeePosition;
    std::cout << "Enter employee name: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter employee position: ";
    std::getline(std::cin, employeePosition);
    employee.setName(employeeName);
    employee.setPosition(employeePosition);

    controller.updateOrder(totalCost, observation, user, start, end, car, employee, id);
    std::cout << "Order updated successfully.\n";
}

void OrderUi::completeOrder() {
    int id;
    std::cout << "Enter order ID to complete: ";
    std::cin >> id;
    controller.completeOrder(id);
    std::cout << "Order completed successfully.\n";
}

void OrderUi::takeAwayOrder() {
    int id;
    Employee employee;

    std::cout << "Enter order ID to take away: ";
    std::cin >> id;

    std::string employeeName, employeePosition;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter employee name: ";
    std::getline(std::cin, employeeName);
    std::cout << "Enter employee position: ";
    std::getline(std::cin, employeePosition);
    employee.setName(employeeName);
    employee.setPosition(employeePosition);

    controller.takeAwayOrder(id, employee);
    std::cout << "Order taken away successfully.\n";
}

void OrderUi::listOrders() {
    auto orders = controller.listOrders();
    for (Order order : orders) {
        order.displayOrder();
    }
}

void OrderUi::searchOrder() {
    auto orders = controller.searchOrder();
    for (Order order : orders) {
        order.displayOrder();
    }
}
