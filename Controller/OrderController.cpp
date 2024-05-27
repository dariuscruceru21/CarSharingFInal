

#include "OrderController.h"

void OrderController::createOrder(float totalCost, std::string observation, Customer user, tm start, tm end,
                                  Car car, Employee employee) const{

    Order newOrder;
    newOrder.setCar(car);
    newOrder.setCustomer(user);
    newOrder.setEnd(end);
    newOrder.setStart(start);
    newOrder.setMoney(totalCost);
    newOrder.setObservation(observation);
    newOrder.setEmployee(employee);
    this->repo.saveOrder(newOrder);
}
