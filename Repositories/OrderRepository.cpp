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

Order OrderRepository::searchOrderByOrderNumber(std::list<Order> repository, int orderNr) {
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