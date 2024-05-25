#ifndef APP_ORDER_H
#define APP_ORDER_H

#include<ctime>
#include<string>

#include "Employee.h"
#include "User.h"

class Order {
private:
    int orderNumber;

    tm* orderDate;
    tm* start;
    tm* end;

    std::string status;
    Car car;/** TODO */
    User user;
    Employee employee; /** TODO */
    float totalCost;
    std::string observation;
public:
    //TODO: getters and setters
    Order(float totalCost, std::string observation, User user, tm *start, tm *end, Car car,
          std::list <Order> repository);
    Order(float totalCost, std::string observation, User user, tm *start, Car car, Employee employee1,
          std::list <Order> repository);
    void changeStatus();

    void setOrderNr(int nr);
    int getOrderNr() const;
    void setOrderDate(tm &time);
    tm getOrderDate();
    void setStart(tm time);
    tm getStart();
    void setEnd(tm time);
    tm getEnd();
    void setStatus(std::string status);
    std::string getStatus();
    void setCar(Car car);
    Car getCar();
    void setUser(User user);
    User getUser();
    void setEmployee(Employee employee);
    Employee getEmployee();
    void setMoney(float sum);
    float getMoney();
    void setObservation(std::string observation);
    std::string getObservation();

    //general function for writing an order's details
    void writeAll();




    //B.4 Auflisten der Bestellungen
    void showAllOrdersInASpecificTimeInterval(std::list<Order> repository, tm start, tm end);
    static bool compareByTotalPrice(Order c1, Order c2)
    { return c1.moneySum < c2.moneySum; }

    Order searchOrderByOrderNumber(std::list<Order> repository, int orderNr);

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


    //transform obect into csv format
    std::string toCSV() const;

    //transform object from csv format
    void fromCSV(const std::string &csvLine);
};


#endif //APP_ORDER_H
