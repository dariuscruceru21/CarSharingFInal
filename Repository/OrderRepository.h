#ifndef CARSHARINGFINAL_ORDERREPOSITORY_H
#define CARSHARINGFINAL_ORDERREPOSITORY_H
#include <iostream>
#include <string>
#include <fstream>
#include "../Models/Order.h"
#include <vector>
#include <list>

class OrderRepository {
private:
    std::string filename = "CarSharingFInal/Information/Orders.csv";

public:

    //B.4 Auflisten der Bestellungen
    std::list<Order> showAllOrdersInASpecificTimeInterval(std::list<Order> repository, tm start, tm end);
    static bool compareByTotalPrice(Order c1, Order c2)
    { return c1.getMoney() < c2.getMoney(); }

    void totalSumOfATimeInterval(std::list<Order> repository, tm time, std::string type); //time is either a month or a year (ex. January or 2024)




    //--Repository functions--
    //Order findOrderByID -> is included in B4
    void saveOrder(Order obj) const;
    void deleteOrder(Order obj);
    void updateOrder(Order obj);
    std::vector<Order> listAllOrders();
    Order searchOrder(int orderID);

    //B.3 -Grama Andrei
    //Order & Reservation handling
    std::list <Order> removeReservation(Order obj);
    std::list <Order> changeReservation(Order obj);


};


#endif //CARSHARINGFINAL_ORDERREPOSITORY_H