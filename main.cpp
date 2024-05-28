#include <iostream>
#include "Repository/CustomerHandlingRepository.h"
#include "Controller/CustomerController.h"

int main() {

    CustomerController controller("Customers.csv");
    controller.addCustomer("Stefan","daaa","stefan@gmail.com","hhhhh","mmaamam","dadadada","+40758904149",true);

    return 0;
}
