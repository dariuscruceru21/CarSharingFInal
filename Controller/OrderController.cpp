

#include "OrderController.h"

void OrderController::createOrder(float totalCost, std::string observation, Customer user, tm start, tm end,
                                  Car car, Employee employee) const{

    time_t now = time(0);
    tm *ltm = localtime(&now);
    Order newOrder;
    newOrder.setCar(car);
    newOrder.setCustomer(user);
    newOrder.setEnd(end);
    newOrder.setStart(start);
    newOrder.setMoney(totalCost);
    newOrder.setObservation(observation);
    newOrder.setEmployee(employee);
    newOrder.setOrderDate(*ltm);
    newOrder.setRepository(repo.listAllOrders());
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
    updatedOrder.setRepository(repo.listAllOrders());
    repo.updateOrder(updatedOrder);
}

void OrderController::completeOrder(int id) {
    Order completed = repo.searchOrder(id);
    long long diff = completed.getDiff();//dif dintre start si end
    int numOfDays = diff /day;
    if(numOfDays * day < diff){
        numOfDays++;
    }
    completed.setMoney(numOfDays * completed.getCar().getDailyRate());
    completed.setStatus("completed");
    repo.updateOrder(completed);
}

void OrderController::takeAwayOrder(int id, Employee employee) {
    Order change = repo.searchOrder(id);
    change.setEmployee(employee);
    repo.updateOrder(change);
}

void OrderController::takeOverOrder(int id) {
    Order change = repo.searchOrder(id);
    change.setEmployee()
}

std::list<Order> OrderController::listOrders() {
    return repo.listAllOrders();
}

Order OrderController::searchOrder(int id) {
    return repo.searchOrder(id);
}

