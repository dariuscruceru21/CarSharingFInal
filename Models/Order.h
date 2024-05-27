#ifndef APP_ORDER_H
#define APP_ORDER_H

#include<ctime>
#include<string>
#include <list>
#include "sstream"

#include "Employee.h"
#include "Customer.h"
#include "Car.h"
//
class Order {
private:
    int orderNumber;

    tm* orderDate;
    tm* start;
    tm* end;

    std::string status;
    Car car;/** TODO */
    Customer customer;
    Employee employee; /** TODO */
    float totalCost;
    std::string observation;
public:
    Order(float totalCost, std::string observation, Customer user, tm *start, tm *end, Car car,
          std::list <Order> repository);
    Order(float totalCost, std::string observation, Customer user, tm *start, Car car, Employee employee1,
          std::list <Order> repository);
    Order(){};
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
    void setCustomer(Customer user);
    Customer getCustomer();
    void setEmployee(Employee employee);
    Employee getEmployee();
    void setMoney(float sum);
    float getMoney();
    void setObservation(std::string observation);
    std::string getObservation();

    //general function for writing an order's details
    void writeAll();

    //B.5 Validierungen   --> is called everytime when an object is created (in the constructor)
    bool callAllValidationFunctions(Car car, std::list<Order> repository, tm begin, tm end,
                                    std::string status, Customer user);

    //if the car is already used on the given date, an error occurs
    static bool checkIfCarIsAlreadyUsed(Car car, std::list<Order> repository, tm begin, tm end);
    //begin must be smaller than end
    static bool checkIfBeginIsSmallerOrEqualEnd(tm begin, tm end);
    //a user is not allowed to have more than 5 reservations
    static bool userHasLessThanFiveReservations(Customer user, std::string status, std::list<Order> repository);
    //order number is issued automatically by the system
    static int determineOrderNumber(std::list<Order> repository);   //numbers are made by maximum + 1  (ex. 1 2 3 5 6 7 --> 8)


    //transform obect into csv format
    std::string toCSV();

    //transform object from csv format
    void fromCSV(const std::string &csvLine);

};


#endif //APP_ORDER_H
