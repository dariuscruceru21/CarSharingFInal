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
    Order(float moneySum, std::string observation, User user, tm *begin, tm *end, Car car,
                std::list <Order> repository);
    Order(float moneySum, std::string observation, User user, tm *end, Car car, Employee employee1,
                std::list <Order> repository);
    void changeStatus();

    void setOrderNr(int nr);
    int getOrderNr() const;
    void setOrderDate(tm &time);
    tm getOrderDate();
    void setBegin(tm time);
    tm getBegin();
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

};


#endif //APP_ORDER_H
