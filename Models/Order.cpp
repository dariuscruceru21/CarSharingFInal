#include "Order.h"

Order::Order(float moneySum, std::string observation, User user, tm *begin, tm *end, Car car,
                         std::list <Order> repository) : car(car) {
    //order type: reservation (begin is given by parameter)

    bool check = callAllValidationFunctions(car,repository,*begin,*end,"Reservation",user);  //requirement B5: Validations
    if (!check) { status = "Error"; return;}  //order is not created; in Repository class, object will not be added if status == Error

    time_t now = time(0);
    this->moneySum = moneySum;
    this->observation = observation;
    this->user = user;
    orderDate = localtime(&now);
    this->status = "Reservation";
    this->begin = begin;
    this->end = end;

    //specification B5.5: employee field is not specified
}

Order::Order(float moneySum, std::string observation, User user, tm *end, Car car, Employee employee1,
                         std::list <Order> repository)
        : car(car) {
    //order type: currently active (begin equals current time)

    bool check = callAllValidationFunctions(car,repository,*begin,*end,"Order",user);
    if (!check) { status = "Error"; return;}  //order is not created

    this->car = car;
    this->employee = employee1;
    this->moneySum = moneySum;
    this->observation = observation;
    time_t now = time(0);
    this->user = user;
    orderDate = localtime(&now);
    this->status = "Order";
    this->begin = localtime(&now);
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

void Order::setBegin(tm time) {
    begin = &time;
}

tm Order::getBegin() {
    return *begin;
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
    moneySum = sum;
}

float Order::getMoney() {
    return moneySum;
}

void Order::setObservation(std::string observation) {
    this->observation = observation;
}

std::string Order::getObservation() {
    return observation;
}



void Order::writeAll() {
    std::cout<<orderNumber<<" ordered on "<<orderDate<<"; from "<<begin<<" until "<<end
             <<" (current status: "<<status<<"), total cost: "<<moneySum<<".\n";  //nu toate detaliile apar
    std::cout<<"Ordered by "<<user.getUserLastName()<<", handled by"<<employee.getUserLastName()<<"\n";
    std::cout<<"-->Observation: "<<observation<<"\n\n";
}





void Order::showAllOrdersInASpecificTimeInterval(std::list<Order> repository, tm start, tm end) {
    std::list<Order> orderList;
    for (Order obj: repository)
    {
        if (obj.begin >= &start && obj.end <= &end)   //object is to be written on the screen; add to orderList
        {
            orderList.push_back(obj);
        }
    }

    orderList.sort(Order::compareByTotalPrice);

    std::cout<<"All orders between the date of "<<&start<<" and "<<&end<<":\n";
    for (Order i: orderList)
    {
        std::cout<<orderNumber<<": price-"<<moneySum<<", car-"<<car.brand<<", user-"<<user.getUserLastName()<<", employee-"<<employee.getUserLastName();
    }
}

Order Order::searchOrderByOrderNumber(std::list<Order> repository, int orderNr) {
    for (Order obj: repository)
    {
        if (obj.orderNumber == orderNr)
            return obj;
    }
}

void Order::totalSumOfATimeInterval(std::list<Order> repository, tm time, std::string type) {
    if (type == "month")
        for (Order obj: repository)
        {
            if (obj.begin->tm_mon <= time.tm_mon && obj.end->tm_mon >= time.tm_mon) //if the month is included in the order's time interval
                std::cout<<orderNumber<<": price-"<<moneySum<<", car-"<<car.brand<<", user-"<<user.getUserLastName()<<", employee-"<<employee.getUserLastName();
        }
    else
        for (Order obj: repository)
        {
            if (obj.begin->tm_year >= time.tm_year && obj.end->tm_year <= time.tm_year) //if the time is included in a year
                std::cout<<orderNumber<<": price-"<<moneySum<<", car-"<<car.brand<<", user-"<<user.getUserLastName()<<", employee-"<<employee.getUserLastName();

        }
}



bool Order::callAllValidationFunctions(Car car, std::list<Order> repository, tm begin, tm end,
                                             std::string status, User user) {
    if (checkIfCarIsAlreadyUsed(car,repository,begin,end)) {std::cout<<"\nError: Car is already used on specified date; cannot create order\n"; return false;}

    if (!checkIfBeginIsSmallerOrEqualEnd(begin,end)) {std::cout<<"\nError: Begin time surpasses end time\n"; return false;}

    if (!userHasLessThanFiveReservations(user,status,repository)) {std::cout<<"\nError: number of reservations cannot exceed 5\n"; return false;}

    orderNumber = determineOrderNumber(repository);

    return true;
}

bool Order::checkIfCarIsAlreadyUsed(Car car, std::list<Order> repository, tm begin, tm end) {
    for (Order obj: repository)
    {
        if (obj.car.licensePlate == car.licensePlate)  //an order has been found using the same car; check if the new order wants to use it in an already occupied time period
            if (&end >= obj.begin && &end <= obj.end || &begin <= obj.end && &begin >= obj.begin)
                return true;  //car is used, cannot create order
    }
    return false;
}

bool Order::checkIfBeginIsSmallerOrEqualEnd(tm begin, tm end) {
    if (&begin <= &end) return true;
    return false;
}

bool Order::userHasLessThanFiveReservations(User user, std::string status, std::list<Order> repository) {
    if (status != "Reservation") return true;  //order is not a reservation, will not be problematic

    int ct=0;
    for (Order obj: repository)
    {
        if (obj.user.getUserEmail() == user.getUserEmail())  //cant have duplicate emails; users can be identified this way then
            ct++;
    }

    if (ct >= 5) return false;  //cannot make order; user reached maximum amount of reservations

    return true;
}

int Order::determineOrderNumber(std::list<Order> repository) {
    int maxi = 0;
    for (Order obj: repository)
        if (obj.orderNumber > maxi)
            maxi = obj.orderNumber;

    return maxi + 1;
}
