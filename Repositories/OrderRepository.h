#ifndef CARSHARINGFINAL_ORDERREPOSITORY_H
#define CARSHARINGFINAL_ORDERREPOSITORY_H


class OrderRepository {
private:

public:


    //B.4 Auflisten der Bestellungen
    void showAllOrdersInASpecificTimeInterval(std::list<Order> repository, tm start, tm end);
    static bool compareByTotalPrice(Order c1, Order c2)
    { return c1.moneySum < c2.moneySum; }

    Order searchOrderByOrderNumber(std::list<Order> repository, int orderNr);

    void totalSumOfATimeInterval(std::list<Order> repository, tm time, std::string type); //time is either a month or a year (ex. January or 2024)

};


#endif //CARSHARINGFINAL_ORDERREPOSITORY_H
