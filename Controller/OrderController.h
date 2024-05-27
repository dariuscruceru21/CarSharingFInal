
#ifndef APP_ORDERCONTROLLER_H
#define APP_ORDERCONTROLLER_H

#include "../Repository/OrderRepository.h"
#include<list>

class OrderController {
private:
    OrderRepository repo;
    int day = 86400;
public:
    void createOrder(float totalCost, std::string observation, Customer user, tm start, tm end, Car car, Employee employee) const;

    void updateOrder(float totalCost, std::string observation, Customer user, tm start, tm end, Car car, Employee employee, int id);

    void completeOrder(int id);

    void takeOverOrder(int id);

    void takeAwayOrder(int id, Employee employee);

    std::list<Order> listOrders();

    Order searchOrder(int id);

};


#endif //APP_ORDERCONTROLLER_H
