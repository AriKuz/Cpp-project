#include "Zoo.h"
#include "Cage.h"

void Zoo::addAnimal(Animal& animal) {
    for (int i =0; i<cagesCount; i++)
    {
        if(cages[i]->getType()== animal.getType())
        {
            cages[i]->addAnimal(animal);
            return;
        }
    }
    // No cage was found, so we create a new one

    cages[cagesCount] = new Cage(animal.getType()); // TODO - check what Cage c'tor requires
    cages[cagesCount]->addAnimal(animal);
}
void Zoo::removeAnimal(int serialNumber) {

}
void Zoo::addEmployee(Employee& employee) {

}
void Zoo::removeEmployee(int employeeNumber) {

}
void Zoo::show() const {

}
void Zoo::addCage(int type) {

}
void Zoo::showAllAnimals()const {

}
void Zoo::showAllEmployees()const {

}
void Zoo::feedAllAnimals() {

}
