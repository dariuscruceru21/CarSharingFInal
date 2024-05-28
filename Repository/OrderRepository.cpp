#include "OrderRepository.h"




std::vector<Order> OrderRepository::showAllOrdersInASpecificTimeInterval(std::vector<Order> repository, tm start, tm end) {
    std::list<Order> orderList;
    for (Order obj: repository)
    {
        if (obj.getStart().tm_year >= start.tm_year && obj.getStart().tm_mon >= start.tm_mon && obj.getStart().tm_mday >= start.tm_mday)
            if (obj.getEnd().tm_year <= end.tm_year && obj.getEnd().tm_mon <= end.tm_mon && obj.getEnd().tm_mday <= end.tm_mday)
        {
            orderList.push_back(obj);
        }
    }

    orderList.sort(OrderRepository::compareByTotalPrice);

//    std::cout<<"All orders between the date of "<<&start<<" and "<<&end<<":\n";
//    for (Order obj: orderList)
//    {
//        std::cout<<obj.getOrderNr()<<": price-"<<obj.getMoney()<<", car-"<<obj.getCar().getBrand()<<", customer-"<<obj.getCustomer().getSurname()<<", employee-"<<obj.getEmployee().getSurname();
//    }
    return convertListToVector(orderList);
}


void OrderRepository::totalSumOfATimeInterval(std::vector<Order> repository, tm time, std::string type) { //type: either month or year
    if (type == "month")
        for (Order obj: repository)
        {
            if (obj.getStart().tm_mon <= time.tm_mon && obj.getEnd().tm_mon >= time.tm_mon) //if the month is included in the order's time interval
                std::cout << obj.getOrderNr() << ": price-" << obj.getMoney() << ", car-" << obj.getCar().getBrand() << ", customer-" << obj.getCustomer().getSurname() << ", employee-" << obj.getEmployee().getSurname();
        }
    else
        for (Order obj: repository)
        {
            if (obj.getStart().tm_year >= time.tm_year && obj.getEnd().tm_year <= time.tm_year) //if the order time is included in the given year
                std::cout<<obj.getOrderNr()<<": price-"<<obj.getMoney()<<", car-"<<obj.getCar().getBrand()<<", user-"<<obj.getCustomer().getSurname()<<", employee-"<<obj.getEmployee().getSurname();

        }
}


void OrderRepository::saveOrder(Order obj) const {
    //read all current orders into a list, add the new object to the list, then save the new list
    std::ifstream f(filename);

    std::list<Order> repo;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        repo.push_back(obj1);
    }
    f.close();
    repo.push_back(obj);


    std::ofstream g(filename);
    if (!g.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (auto &obj1 : repo) {
        g << obj1.toCSV() << std::endl;
    }

    g.close();
}

void OrderRepository::deleteOrder(Order obj) {
    //read all current orders into a list, except for the one we want to remove
    std::ifstream f(filename);

    std::list<Order> repo;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        if (obj1.getOrderNr() != obj.getOrderNr())
            repo.push_back(obj1);
    }
    f.close();

    std::ofstream g(filename);
    if (!g.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (auto &obj1 : repo) {
        g << obj1.toCSV() << std::endl;
    }

    g.close();
}


void OrderRepository::updateOrder(Order obj) {
    //read all current orders into a list, except for the one, which will be replaced by the updated version

    /*int orderNr1; tm* orderDate1, begin1,end1; std::string status1;
    std::string carLicensePlate1; int customerID1, employeeID1;
    float totalCost1; std::string observation1;*/  //partea asta creca vine in UI sau Controller
    //(si se da ca parametru obiectul nou cu acelasi ID ca inainte)

    std::ifstream f(filename);

    std::list<Order> repo;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        if (obj1.getOrderNr() != obj.getOrderNr())
            repo.push_back(obj1);
        else
            repo.push_back(obj);
    }
    f.close();

    std::ofstream g(filename);
    if (!g.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    for (auto &obj1 : repo) {
        g << obj1.toCSV() << std::endl;
    }

    g.close();
}

//B.3
std::string OrderRepository::returnUserType(Order obj) {
    std::ifstream f("../Information/Customers.csv");

    std::list<Customer> repo1;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        /**TODO waiting for permission check (login page) */
    }
}

/**maybe this ?
 * TODO
 * need to modify the params*/
std::vector<Order> OrderRepository::removeReservation(int orderNr, const std::string& requesterRole, const std::string& requesterID) {
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return std::vector<Order>();
    }

    std::list<Order> repo;
    std::string line;
    bool removed = false;

    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);

        if (obj1.getOrderNr() != orderNr) {
            repo.push_back(obj1);
        } else {
            // Check if the requester is allowed to remove this reservation
            if (requesterRole == "admin" || requesterRole == "employee" || obj1.getCustomer() == requesterID) {
                removed = true;  // Reservation removed
            } else {
                // If not allowed, keep the reservation
                repo.push_back(obj1);
            }
        }
    }

    f.close();

    if (removed) {
        // Save the updated list back to the file
        std::ofstream outFile(filename, std::ofstream::trunc);
        if (!outFile.is_open()) {
            std::cerr << "Unable to open file " << filename << std::endl;
            return std::vector<Order>();
        }

        for (auto& order : repo) {
            outFile << order.toCSV() << "\n";
        }

        outFile.close();
    }

    return convertListToVector(repo);
}

//std::list <Order> OrderRepository::removeReservation(int orderNr) {
//    std::ifstream f(filename);
//
//    std::list<Order> repo;
//    std::string line;
//    while (std::getline(f, line)) {
//        Order obj1;
//        obj1.fromCSV(line);
//        if (obj1.getOrderNr() != orderNr)
//            repo.push_back(obj1);
//        else if(obj1.getCustomer())
//    }
//
//    f.close();
//    return repo;
//
//}

//B.3.3
std::vector<Order> OrderRepository::changeReservation(int orderNr) {
    std::ifstream f(filename);

    std::list<Order> repo;
    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        if (obj1.getOrderNr() != orderNr)
            repo.push_back(obj1);

    }
    f.close();

//    std::list<Order> aux;
//    for (Order obj: repo)
//        if (obj.getOrderNr() != obj.getOrderNr())
//            aux.push_back(obj);
//        else if ( /*is admin*/) { /**TODO verification*/
//            int option;
//            std::cin >> option;
//
//            switch (option) {
//                case 1: {    //Admins
//
//                    break;
//                }
//                case 2: {
//
//                    break;
//                }
//            }
//        } else if ( /*is customer*/) {
//            int option;
//            std::cin >> option;
//
//            switch (option) {
//                case 1: {    //customers
//
//                    break;
//                }
//                case 2: {
//
//                    break;
//                }
//            }
//        }
    return convertListToVector(repo);
}
std::vector<Order> OrderRepository::listAllOrders() const {
    std::ifstream f(filename);
    std::list<Order> orders;

    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);
        orders.push_back(obj1);
    }
    f.close();

    return convertListToVector(orders);
}

Order OrderRepository::searchOrder(int orderID) {
    std::ifstream f(filename);

    std::string line;
    while (std::getline(f, line)) {
        Order obj1;
        obj1.fromCSV(line);

        if (obj1.getOrderNr() == orderID)
            return obj1;
    }
    f.close();
    std::cout<<"Error: object does not exist";
}


std::vector<Order> OrderRepository::convertListToVector(std::list<Order> &repo) {
    std::vector<Order> newRepo;
    for (Order obj: repo)
        newRepo.push_back(obj);
    return newRepo;
}



void OrderRepository::readFromCsv() {
    std::vector<Order> orders;

    orders.clear();
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            // Parse each line and create Customer objects
            // Assuming your CSV format is comma-separated
            //
            //
            std::stringstream ss(line);
            std::string orderNr, orderDate, beginDate, endDate, status, carLicensePlate,
            customerEmail, employeeEmail, totalCost, observation;

            std::getline(ss, orderNr, ',');
            int orderNrFloat = std::stoi(orderNr);
            std::getline(ss, orderDate, ',');
            std::getline(ss, beginDate, ',');
            std::getline(ss, endDate, ',');
            std::getline(ss, status, ',');
            std::getline(ss, carLicensePlate, ',');
            std::getline(ss, customerEmail, ',');
            std::getline(ss, employeeEmail, ',');
            std::getline(ss, totalCost, ',');
            float totalCostFloat = std::stof(totalCost);
            std::getline(ss, observation, ',');


            // Create Customer object and add to vector
            auto obj = new Order(orderNr, orderDate, beginDate, endDate, status, carLicensePlate,
                                 customerEmail, employeeEmail, totalCost, observation)
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

}

void OrderRepository::writeToCsv() {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (Customer &customer: Customers) {
            // Write each customer's data in CSV format
            file << customer.getName() << ","
                 << customer.getSurname() << ","
                 << customer.getEmail() << ","
                 << customer.getPassword() << ","
                 << customer.getAddress() << ","
                 << customer.getRemarks() << ","
                 << customer.getPhone() << ","
                 << (customer.getGdprDeleted() ? "1" : "0") << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << fileName << std::endl;
    }
}