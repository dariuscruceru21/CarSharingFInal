#include "Order.h"

Order::Order(float totalCost, std::string observation, User user, tm *start, tm *end, Car car,
             std::list <Order> repository) : car(car) {
    //order type: reservation (start is given by parameter)

    bool check = callAllValidationFunctions(car, repository, *start, *end, "Reservation", user);  //requirement B5: Validations
    if (!check) { status = "Error"; return;}  //order is not created; in Repository class, object will not be added if status == Error

    time_t now = time(0);
    this->totalCost = totalCost;
    this->observation = observation;
    this->user = user;
    orderDate = localtime(&now);
    this->status = "Reservation";
    this->start = start;
    this->end = end;

    //specification B5.5: employee field is not specified
}

Order::Order(float totalCost, std::string observation, User user, tm *end, Car car, Employee employee1,
             std::list <Order> repository)
        : car(car) {
    //order type: currently active (start equals current time)

    bool check = callAllValidationFunctions(car,repository,*start,*end,"Order",user);
    if (!check) { status = "Error"; return;}  //order is not created

    this->car = car;
    this->employee = employee1;
    this->totalCost = totalCost;
    this->observation = observation;
    time_t now = time(0);
    this->user = user;
    orderDate = localtime(&now);
    this->status = "Order";
    this->start = localtime(&now);
    this->end = end;

}


void Order::setOrderNr(int nr) {
    orderNumber = nr;
}

int Order::getOrderNr() const {
    return orderNumber;
}

void Order::setOrderDate(tm &time){
    orderDate = &time;
}

tm Order::getOrderDate() {
    return *orderDate;
}

void Order::setStart(tm time) {
    start = &time;
}

tm Order::getStart() {
    return *start;
}

void Order::setEnd(tm time) {
    end = &time;
}

tm Order::getEnd() {
    return *end;
}

void Order::setStatus(std::string status) {
    this->status = status;
}

std::string Order::getStatus() {
    return status;
}

void Order::setCar(Car car) {
    this->car = car;
}

Car Order::getCar() {
    return car;
}

void Order::setUser(User user) {
    this->user = user;
}

User Order::getUser() {
    return user;
}

void Order::setEmployee(Employee employee) {
    this->employee = employee;
}

Employee Order::getEmployee() {
    return employee;
}

void Order::setMoney(float sum) {
    totalCost = sum;
}

float Order::getMoney() {
    return totalCost;
}

void Order::setObservation(std::string observation) {
    this->observation = observation;
}

std::string Order::getObservation() {
    return observation;
}



void Order::writeAll() {
    std::cout<<orderNumber<<" ordered on "<<orderDate<<"; from "<<start<<" until "<<end
             <<" (current status: "<<status<<"), total cost: "<<totalCost<<".\n";  //nu toate detaliile apar
    std::cout<<"Ordered by "<<user.getUserLastName()<<", handled by"<<employee.getUserLastName()<<"\n";
    std::cout<<"-->Observation: "<<observation<<"\n\n";
}

