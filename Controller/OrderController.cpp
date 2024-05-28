

#include "OrderController.h"

void OrderController::createOrder(float totalCost, std::string observation, std::string customerPhoneNr, tm start, tm end,
                                  std::string carLicensePlate, std::string employeeName, std::string employeeSurname) const{

    EmployeeRepository employeeSearch;
    CustomerHandlingRepository customerSearch("CarSharingFInal/Information/Customers.csv");
    CarRepository carSearch("");//TODO:carfile
    Order newOrder(totalCost, observation, customerSearch.searchCustomersByPhoneNumber(customerPhoneNr)[0], start, end, carSearch.findByLicensePlate(carLicensePlate));
    newOrder.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    newOrder.setRepository(repo.listAllOrders());
    this->repo.saveOrder(newOrder);
}

void OrderController::updateOrder(float totalCost, std::string observation, std::string customerPhoneNr, tm start, tm end,
                                  std::string carLicensePlate, std::string employeeName, std::string employeeSurname, int id) {
    //waiting for login info

    Order updatedOrder;
    EmployeeRepository employeeSearch;
    CustomerHandlingRepository customerSearch("CarSharingFInal/Information/Customers.csv");
    CarRepository carSearch("");//TODO: waiting for carfile
    updatedOrder.setCar(carSearch.findByLicensePlate(carLicensePlate));
    updatedOrder.setCustomer(customerSearch.searchCustomersByPhoneNumber(customerPhoneNr)[0]);
    updatedOrder.setEnd(end);
    updatedOrder.setStart(start);
    updatedOrder.setMoney(totalCost);
    updatedOrder.setObservation(observation);
    updatedOrder.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    updatedOrder.setOrderNr(id);
    updatedOrder.setRepository(repo.listAllOrders());
    repo.updateOrder(updatedOrder);
}

void OrderController::completeOrder(int id) {
    Order completed = repo.searchOrder(id);
    long long diff = completed.getDiff();//dif dintre start si end
    int numOfDays = ceil(diff /day);
    completed.setMoney(numOfDays * completed.getCar().getDailyRate());
    completed.setStatus("completed");
    repo.updateOrder(completed);
}

void OrderController::takeAwayOrder(int id, std::string employeeName, std::string employeeSurname) {
    Order change = repo.searchOrder(id);
    EmployeeRepository employeeSearch;
    change.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    repo.updateOrder(change);
}

void OrderController::takeOverOrder(int id, std::string employeeName, std::string employeeSurname) {
    Order change = repo.searchOrder(id);
    EmployeeRepository employeeSearch;
    change.setEmployee(employeeSearch.findEmployeeByName(employeeName, employeeSurname));
    repo.updateOrder(change);
}

std::vector<Order> OrderController::listOrders() {
    return repo.listAllOrders();
}

Order OrderController::searchOrder(int id) {
    return repo.searchOrder(id);
}

