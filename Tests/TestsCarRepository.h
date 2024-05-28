#ifndef TESTCARREPOSITORY_H
#define TESTCARREPOSITORY_H

#include "../Repository/CarRepository.h"

class TestCarRepository {
public:
    void testAll();
private:
    void testSaveCar(CarRepository &repository);
    void testUpdateCar(CarRepository &repository);
    void testDeleteCar(CarRepository &repository);
    void testFindCarByLicensePlate(CarRepository &repository);
    void testListAllCars(CarRepository &repository);
};

#endif // TESTCARREPOSITORY_H
