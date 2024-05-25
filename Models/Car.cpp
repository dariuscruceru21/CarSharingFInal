#include "Car.h"

// Getters
std::string Car::getLicensePlate() const {
    return licensePlate;
}

std::string Car::getModel() const {
    return model;
}

std::string Car::getBrand() const {
    return brand;
}

int Car::getYearOfFirstRegistration() const {
    return yearOfFirstRegistration;
}

int Car::getMileage() const {
    return mileage;
}

float Car::getDailyRate() const {
    return dailyRate;
}

std::string Car::getFuelType() const {
    return fuelType;
}

std::string Car::getTransmission() const {
    return transmission;
}

std::string Car::getColor() const {
    return color;
}

std::string Car::getRemarks() const {
    return remarks;
}

// Setters
void Car::setLicensePlate(const std::string &newLicensePlate) {
    this->licensePlate = newLicensePlate;
}

void Car::setModel(const std::string &newModel) {
    this->model = newModel;
}

void Car::setBrand(const std::string &newBrand) {
    this->brand = newBrand;
}

void Car::setYearOfFirstRegistration(int newYearOfFirstRegistration) {
    this->yearOfFirstRegistration = newYearOfFirstRegistration;
}

void Car::setMileage(int newMileage) {
    this->mileage = newMileage;
}

void Car::setDailyRate(float newDailyRate) {
    this->dailyRate = newDailyRate;
}

void Car::setFuelType(const std::string &newFuelType) {
    this->fuelType = newFuelType;
}

void Car::setTransmission(const std::string &newTransmission) {
    this->transmission = newTransmission;
}

void Car::setColor(const std::string &newColor) {
    this->color = newColor;
}

void Car::setRemarks(const std::string &newRemarks) {
    this->remarks = newRemarks;
}