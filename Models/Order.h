#ifndef APP_ORDER_H
#define APP_ORDER_H

#include<ctime>
#include<string>

#include "Employee.h"
#include "User.h"
#include "Car.h"

class Order {
private:
    int orderNumber;

    tm* orderDate;
    tm* start;
    tm* end;

    std::string status;
    Car car;/** TODO */
    User user; //CUSTOMER??
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

    //transform obect into csv format
    std::string toCSV() const;

    //transform object from csv format
    void fromCSV(const std::string &csvLine);

};


#endif //APP_ORDER_H
