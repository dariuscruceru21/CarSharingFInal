#include "Car.h"
#include "sstream"


Car::Car(std::string licensePlate, std::string model, std::string brand, int yearOfFirstRegistration, int mileage,
         float dailyRate, std::string fuelType, std::string transmission, std::string color, std::string remarks,
         bool isActive) {
    this->licensePlate = licensePlate;
    this->model = model;
    this->brand = brand;
    this->yearOfFirstRegistration = yearOfFirstRegistration;
    this->mileage = mileage;
    this->dailyRate = dailyRate;
    this->fuelType = fuelType;
    this->transmission = transmission;
    this->color = color;
    this->remarks = remarks;
    this->isActive = isActive;
}


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

void Car::setisActive(bool isActive) {
    this->isActive = isActive;
}

bool Car::getisActive() {
    return isActive;
}

std::string Car::toCsv() {
    std::ostringstream oss;
    oss << this->licensePlate << "," << this->model << "," << this->brand << "," << this->yearOfFirstRegistration << ","
        << this->mileage << "," << this->dailyRate << "," << this->fuelType << "," << this->transmission << ","
        << this->color << "," << this->remarks;
}

void Car::fromCsv(std::string &csvLine) {
    std::istringstream ss(csvLine);
    //only strings
    std::getline(ss, this->model, ',');
    std::getline(ss, this->brand, ',');
    std::getline(ss, this->fuelType, ',');
    std::getline(ss, this->transmission, ',');
    std::getline(ss, this->color, ',');
    std::getline(ss, this->remarks, ',');

    //ints,floats---> we ignore the comma
    ss >> this->licensePlate;
    ss.ignore(1);
    ss >> this->dailyRate;
    ss.ignore(1);
    ss >> this->yearOfFirstRegistration;
    ss.ignore(1);
    ss >> this->mileage;
    ss.ignore(1);

}



