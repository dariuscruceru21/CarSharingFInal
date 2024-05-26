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

Car CarRepository::findByLicensePlate(std::string &licensePlate) {
    for(const Car& car : this->cars){
        if(car.getLicensePlate() == licensePlate)
            return car;
    }
    std::cout << "No car with the introduced license plate was found in our repository.";
}

void CarRepository::saveCar(Car &car) {
    this->cars.push_back(car);
    writeToCsv();
}

void CarRepository::deleteCar(const std::string& licensePlate) {
    auto it = std::remove_if(this->cars.begin(), this->cars.end(),
                             [&licensePlate](const Car& car) { return car.getLicensePlate() == licensePlate; });
    this->cars.erase(it, this->cars.end());
}

void CarRepository::updateCar(Car &car) {

}

std::vector<Car> CarRepository::listAllCars() {

}

std::vector<Car> CarRepository::searchCar(std::string &licensePlate) {

}

