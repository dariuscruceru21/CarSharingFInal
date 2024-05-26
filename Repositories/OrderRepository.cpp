#include "OrderRepository.h"

void OrderRepository::showAllOrdersInASpecificTimeInterval(std::list<Order> repository, tm start, tm end) {
    std::list<Order> orderList;
    for (Order obj: repository)
    {
        if (obj.start >= &start && obj.end <= &end)   //object is to be written on the screen; add to orderList
        {
            orderList.push_back(obj);
        }
    }

    orderList.sort(Order::compareByTotalPrice);

    std::cout<<"All orders between the date of "<<&start<<" and "<<&end<<":\n";
    for (Order i: orderList)
    {
        std::cout<<orderNumber<<": price-"<<totalCost<<", car-"<<car.brand<<", user-"<<user.getUserLastName()<<", employee-"<<employee.getUserLastName();
    }
}

Order OrderRepository::findOrderByID(std::list<Order> repository, int orderNr) {
    for (Order obj: repository)
    {
        if (obj.orderNumber == orderNr)
            return obj;
    }
}

void OrderRepository::totalSumOfATimeInterval(std::list<Order> repository, tm time, std::string type) {
    if (type == "month")
        for (Order obj: repository)
        {
            if (obj.start->tm_mon <= time.tm_mon && obj.end->tm_mon >= time.tm_mon) //if the month is included in the order's time interval
                std::cout<<orderNumber<<": price-"<<totalCost<<", car-"<<car.brand<<", user-"<<user.getUserLastName()<<", employee-"<<employee.getUserLastName();
        }
    else
        for (Order obj: repository)
        {
            if (obj.start->tm_year >= time.tm_year && obj.end->tm_year <= time.tm_year) //if the time is included in a year
                std::cout<<orderNumber<<": price-"<<totalCost<<", car-"<<car.brand<<", user-"<<user.getUserLastName()<<", employee-"<<employee.getUserLastName();

        }
}


bool OrderRepository::callAllValidationFunctions(Car car, std::list<Order> repository, tm begin, tm end,
                                       std::string status, User user) {
    if (checkIfCarIsAlreadyUsed(car,repository,begin,end)) {std::cout<<"\nError: Car is already used on specified date; cannot create order\n"; return false;}

    if (!checkIfBeginIsSmallerOrEqualEnd(begin,end)) {std::cout<<"\nError: Begin time surpasses end time\n"; return false;}

    if (!userHasLessThanFiveReservations(user,status,repository)) {std::cout<<"\nError: number of reservations cannot exceed 5\n"; return false;}

    orderNumber = determineOrderNumber(repository);

    return true;
}

bool OrderRepository::checkIfCarIsAlreadyUsed(Car car, std::list<Order> repository, tm begin, tm end) {
    for (Order obj: repository)
    {
        if (obj.car.licensePlate == car.licensePlate)  //an order has been found using the same car; check if the new order wants to use it in an already occupied time period
            if (&end >= obj.start && &end <= obj.end || &begin <= obj.end && &begin >= obj.start)
                return true;  //car is used, cannot create order
    }
    return false;
}

bool OrderRepository::checkIfBeginIsSmallerOrEqualEnd(tm begin, tm end) {
    if (&begin <= &end) return true;
    return false;
}

bool OrderRepository::userHasLessThanFiveReservations(User user, std::string status, std::list<Order> repository) {
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

int OrderRepository::determineOrderNumber(std::list<Order> repository) {
    int maxi = 0;
    for (Order obj: repository)
        if (obj.orderNumber > maxi)
            maxi = obj.orderNumber;

    return maxi + 1;
}



void OrderRepository::saveOrder(Order obj) {

}