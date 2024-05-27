//
// Created by scoti on 25.05.2024.
//

#include "CarRepository.h"
#include <fstream>

void CarRepository::readFromCsv() {
    this->cars.clear();
    std::ifstream file(this->fileName);
    std::string line;
    while (std::getline(file, line)) {
        Car car;
        car.fromCsv(line);
        this->cars.push_back(car);
    }
    file.close();
}

void CarRepository::writeToCsv() {
    std::ofstream file(this->fileName);
    for (auto &car: this->cars)
        file << car.toCsv() << "\n";
    file.close();
}

CarRepository::CarRepository(std::string fileName) {
    readFromCsv();
}

Car CarRepository::findByLicensePlate(std::string &licensePlate) {
    for (const Car &car: this->cars) {
        if (car.getLicensePlate() == licensePlate)
            return car;
    }
    std::cout << "No car with the introduced license plate was found in our repository.";
    return Car();
}

void CarRepository::saveCar(Car &car) {
    this->cars.push_back(car);
    writeToCsv();
}

void CarRepository::deleteCar(std::string &licensePlate) {
    for (int i = 0; i < this->cars.size(); i++) {
        if (this->cars[i].getLicensePlate() == licensePlate) {
            this->cars.erase(this->cars.begin() + i);
            break;
        }

    }
    writeToCsv();
}

void CarRepository::updateCar(Car &updatedCar) {
    for(auto& car : this->cars){
        if(car.getLicensePlate() == updatedCar.getLicensePlate()){
            car.setBrand(updatedCar.getBrand());
            car.setColor(updatedCar.getColor());
            car.setDailyRate(updatedCar.getDailyRate());
            car.setFuelType(updatedCar.getFuelType());
            car.setModel(updatedCar.getModel());
            car.setYearOfFirstRegistration(updatedCar.getYearOfFirstRegistration());
            car.setTransmission(updatedCar.getTransmission());
            car.setMileage(updatedCar.getMileage());
            car.setLicensePlate(updatedCar.getLicensePlate());
            car.setRemarks(updatedCar.getRemarks());
            break;
        }

    }
    writeToCsv();

}

std::vector<Car> CarRepository::listAllCars() {
    return this->cars;

}

std::vector<Car> CarRepository::searchCar(std::string &licensePlate) {
    std::vector results = std::vector<Car>{};
    for(Car car:this->cars){
        size_t found = car.getLicensePlate().find(licensePlate);
        if (found != std::string::npos)  {
            results.push_back(car);
        }
    }
}

