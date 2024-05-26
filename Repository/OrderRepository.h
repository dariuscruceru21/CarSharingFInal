#ifndef CARSHARINGFINAL_ORDERREPOSITORY_H
#define CARSHARINGFINAL_ORDERREPOSITORY_H
#include <iostream>
#include <string>
#include <fstream>
#include "../Models/Order.h"
#include <vector>

class OrderRepository {
private:
    std::string filename;
public:


    //B.4 Auflisten der Bestellungen
    void showAllOrdersInASpecificTimeInterval(std::list<Order> repository, tm start, tm end);
    static bool compareByTotalPrice(Order c1, Order c2)
    { return c1.moneySum < c2.moneySum; }

    Order findOrderByID(std::list<Order> repository, int orderNr);

    void totalSumOfATimeInterval(std::list<Order> repository, tm time, std::string type); //time is either a month or a year (ex. January or 2024)


    //B.5 Validierungen   --> is called everytime when an object is created (in the constructor)
    bool callAllValidationFunctions(Car car, std::list<Order> repository, tm begin, tm end,
                                    std::string status, User user);

    //if the car is already used on the given date, an error occurs
    bool checkIfCarIsAlreadyUsed(Car car, std::list<Order> repository, tm begin, tm end);
    //begin must be smaller than end
    bool checkIfBeginIsSmallerOrEqualEnd(tm begin, tm end);
    //a user is not allowed to have more than 5 reservations
    bool userHasLessThanFiveReservations(User user, std::string status, std::list<Order> repository);
    //order number is issued automatically by the system
    int determineOrderNumber(std::list<Order> repository);   //numbers are made by maximum + 1  (ex. 1 2 3 5 6 7 --> 8)


    //--Repository functions--
    //Order findOrderByID -> is included in B4
    void saveOrder(Order obj);
    void deleteOrder(Order obj);
    void updateOrder(Order obj);
    vector<Order> listAllOrders();
    Order searchOrder(int orderID);
};


#endif //CARSHARINGFINAL_ORDERREPOSITORY_H