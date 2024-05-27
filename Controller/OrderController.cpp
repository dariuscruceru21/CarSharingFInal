

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

void OrderController::updateOrder(float totalCost, std::string observation, Customer user, tm start, tm end,
                                  Car car, Employee employee, int id) {
    Order updatedOrder;
    updatedOrder.setCar(car);
    updatedOrder.setCustomer(user);
    updatedOrder.setEnd(end);
    updatedOrder.setStart(start);
    updatedOrder.setMoney(totalCost);
    updatedOrder.setObservation(observation);
    updatedOrder.setEmployee(employee);
    updatedOrder.setOrderNr(id);
    repo.updateOrder(updatedOrder);
}

void OrderController::completeOrder(int id) {
    Order completed = repo.searchOrder(id);
    completed.setStatus("completed");
    repo.updateOrder(completed);
}

void OrderController::takeAwayOrder(int id, Employee employee) {
    Order change = repo.searchOrder(id);
    change.setEmployee(employee);
    repo.updateOrder(change);
}

