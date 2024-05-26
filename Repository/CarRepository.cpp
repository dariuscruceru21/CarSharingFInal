//
// Created by scoti on 25.05.2024.
//

#include "CarRepository.h"
#include <fstream>

void CarRepository::readFromCsv() {
    this->cars.clear();
    std::ifstream file(this->fileName);
    std::string line;
    while(std::getline(file,line)){
        Car car;
        car.fromCsv(line);
        this->cars.push_back(car);
    }
    file.close();
}

void CarRepository::writeToCsv() {
    std::ofstream file(this->fileName);
    for(auto& car: this->cars)
        file<<car.toCsv()<<"\n";
    file.close();
}

CarRepository::CarRepository(std::string fileName) {
    readFromCsv();
}

//cadou---> decomenteaza si da push :))
Car CarRepository::findByLicensePlate(std::string &licensePlate) {
    for(Car obj: this->cars){
        if(obj.getLicensePlate()==licensePlate)
            return obj;
    }
}

//cadou---> decomenteaza si da push :))
void CarRepository::addCar(Car &car) {
   /* this->cars.push_back(car);
    writeToCsv();   */
}

void CarRepository::saveCar(Car &car) {

}

void CarRepository::deleteCar(std::string &licensePlate) {

}

void CarRepository::updateCar(Car &car) {

}

std::vector<Car> CarRepository::listAllCars() {

}

std::vector<Car> CarRepository::searchCar(std::string &licensePlate) {

}

