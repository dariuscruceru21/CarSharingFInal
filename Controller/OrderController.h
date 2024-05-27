
#ifndef APP_ORDERCONTROLLER_H
#define APP_ORDERCONTROLLER_H

#include "../Repository/OrderRepository.h"
#include<list>

class OrderController {
private:
    OrderRepository repo;
public:
    void createOrder(float totalCost, std::string observation, Customer user, tm start, tm end, Car car, Employee employee) const;
    void updateOrder(float totalCost, std::string observation, Customer user, tm start, tm end, Car car, Employee employee, int id);
    void completeOrder(); //poate sa returneze costul?
    void takeOverOrder();
    void takeAwayOrder();
    std::list<Order> listOrders();
    std::list<Order> searchOrder();

};


#endif //APP_ORDERCONTROLLER_H
