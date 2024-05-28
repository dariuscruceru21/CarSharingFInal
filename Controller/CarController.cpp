#include "CarController.h"

CarController::CarController(CarRepository repository) : carRepository(repository) {
    std::vector<Car> sampleCars = {
            Car("XYZ123", "A5", "Audi", 2020, 12000, 180.0, "Petrol", "Automatic", "Red", "new", true),
            Car("LMN456", "3 Series", "BMW", 2021, 8000, 160.0, "Diesel", "Manual", "Blue", "new", true),
            Car("OPQ789", "C-Class", "Mercedes-Benz", 2019, 22000, 200.0, "Petrol", "Automatic", "White", "scratched", true),
            Car("RST012", "CX-5", "Mazda", 2018, 30000, 140.0, "Petrol", "Automatic", "Black", "old", true),
            Car("UVW345", "Outback", "Subaru", 2017, 40000, 130.0, "Petrol", "Manual", "Green", "repainted", true),
            Car("JKL678", "Astra", "Opel", 2016, 50000, 110.0, "Diesel", "Manual", "Grey", "scratched", true),
            Car("BCD901", "Passat", "Volkswagen", 2015, 60000, 150.0, "Petrol", "Automatic", "Silver", "best", true),
            Car("EFG234", "Model 3", "Tesla", 2022, 5000, 200.0, "Electric", "Automatic", "Blue", "new", true),
            Car("HIJ567", "Leaf", "Nissan", 2021, 10000, 170.0, "Electric", "Automatic", "Black", "futuristic", true),
            Car("KLM890", "Kona", "Hyundai", 2020, 15000, 160.0, "Electric", "Automatic", "White", "amazing", true)
    };

    for (const auto &car : sampleCars) {
        carRepository.saveCar(car);
    }
}

void CarController::createCar(Car car) {
    carRepository.saveCar(car);
}

void CarController::updateCar(Car car) {
    carRepository.updateCar(car);
}

void CarController::deleteCar(std::string &licensePlate) {
    carRepository.deleteCar(licensePlate);
}

void CarController::deactivateCar(Car car) {
    carRepository.updateCar(car);
}

std::vector<Car> CarController::listCars() {
    return carRepository.listAllCars();
}

std::vector<Car> CarController::searchCar(std::string &licensePlate) {
    return carRepository.searchCar(licensePlate);
}
