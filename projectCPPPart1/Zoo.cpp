#include "Zoo.h"

Zoo::Zoo(const string& nme, int numOfCages, Address& add, int maximumEmployees) : address(add)
{
	this->name = nme;
	maxCagesCount = numOfCages;
	this->cages = new Cage*[maxCagesCount];
	this->maxEmployees = maximumEmployees;
	this->employees = new Employee*[maximumEmployees];
	this->employeesCount = 0;
}

Zoo::Zoo(Zoo& other) : address(other.getAddress())
{
	this->name = other.name;
	cages = new Cage*[sizeof(other.cages)];
	this->cages = other.cages;
	employees = new Employee*[sizeof(other.employees)];
	this->employees = other.employees;
	this->cagesCount = other.cagesCount;
	this->maxCagesCount = other.maxCagesCount;
	this->animalsCount = other.animalsCount;
	this->employeesCount = other.employeesCount;
	this->maxEmployees = other.maxEmployees;
}

Zoo::Zoo(Zoo&& other) : address(other.address)
{
	name = other.name;
	cages = other.cages;
	other.cages = nullptr;
	employees = other.employees;
	other.employees = nullptr;
	// address = other.address;
	// other.address = nullptr;
	cagesCount = other.cagesCount;
	maxCagesCount = other.maxCagesCount;
	animalsCount = other.animalsCount;
	employeesCount = other.employeesCount;
	maxEmployees = other.maxEmployees;
}

Zoo::~Zoo()
{
	// delete address;
	delete[] employees;
}

void Zoo::addAnimal(Animal* animal) 
{
	if (cagesCount == 0)
	{
		// TODO: handle cages addition (if no appropriate cage, add it)
		addCage(animal->getType());
		// throw "There is no cages in the zoo, Please add one.";
	}
	bool succes = false;
	for (int i = 0; i < cagesCount; i++)
	{
		if (cages[i]->getType() == animal->getType())
		{
			cages[i]->addAnimal(animal);
			cout << "Animal was added successfully!!" << endl;
			return;
		}
	}
	throw "There is no cage for that type.";
}

void Zoo::removeAnimal(int serialNumber) {
	for (int i = 0; i < cagesCount; i++) 
	{
		for (int j = 0; j < cages[i]->getAnimalsCount();j++) 
		{
			Animal** a = cages[i]->getAnimals();
			cout << "Animals: " << *a << endl;
			cout << a[j] << endl;
			if (cages[i]->getAnimals()[j]->getSerialNumber() == serialNumber) 
			{
				cages[i]->removeAnimal(serialNumber);
				return;
			}
		}
	}
    cout << "Serial number was not belong to any animal!!!" << endl;
}

void Zoo::addEmployee(Employee* employee) 
{
	if (employeesCount < maxEmployees)
		employees[employeesCount++] = new Employee(*employee);
	else
	{
		cout << "employees count is smaller then maxEmployees" << endl;
		throw "There is not enough room for new employee";
	}
}

void Zoo::removeEmployee(int employeeNumber) 
{
	for (int i = 0; i < employeesCount; i++)
	{
		if (employees[i]->getEmployeeNumber() == employeeNumber)
		{
			Employee** newArray = new Employee*[maxEmployees];
			std::copy(employees, employees + i, newArray);
			std::copy(employees + i + 1, employees + employeesCount, newArray + i);
			delete[] employees;
			employees = newArray;
			--employeesCount;
			return;
		}
	}
	throw "There is no employee with this number";
}

void Zoo::show()  
{
	cout << "Zoo " << name << " in " << address << endl;
	showAllAnimals();
	showAllEmployees();
}

void Zoo::addCage(int type) 
{
	if (cagesCount < maxCagesCount)
		cages[cagesCount++] = new Cage(type);
	else
		throw "There is maximum cages in the zoo.";
}

void Zoo::showAllAnimals() const {
	cout << "Animals :\n";
	for (int i = 0; i < cagesCount; i++)
		cout << "Cage number " << i << " animals :\n" << *(cages[i]);
}

void Zoo::showAllEmployees() const {
	cout << "\nEmployees :\n";
	for (int i = 0; i < employeesCount; i++)
		cout << *employees[i] << endl;
}

void Zoo::feedAllAnimals() {
    for (int i = 0; i < cagesCount; i++) 
		for (int j = 0;j < (*this)[i].getAnimalsCount();j++) 
			cages[i]->getAnimals()[j]->eat();
}