//
// Created by Carla Chira on 24.05.2024.
//

#ifndef APP_ORDER_H
#define APP_ORDER_H

#include<ctime>
#include<string>

#include "Employee.h"
#include "User.h"

class Order {
private:
    int orderNumber;

    tm* orderDate;
    tm* start;
    tm* end;

    std::string status;
    Car car;/** TODO */
    User user;
    Employee employee; /** TODO */
    float totalCost;
    std::string observation;
public:
    //TODO: getters and setters
};


#endif //APP_ORDER_H
