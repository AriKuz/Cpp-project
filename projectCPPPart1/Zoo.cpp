#include "Zoo.h"

Zoo* Zoo::theZoo = 0;

Zoo::Zoo(const string& nme, Address& add) : address(add) {}

Zoo* Zoo::getInstance(const string& name, Address& add)
{
    if (theZoo == 0)
        theZoo = new Zoo(name, add);

    return theZoo;
}

void Zoo::addAnimal(Animal* animal)
{
	if (cages.size() == 0)
	{
		//added first cage in zoo 
		cout << "create first cage with type: "<< animal->getType() << endl;

		addCage(animal->getType());
	}
	for (auto it = cages.begin(); it != cages.end(); ++it)
	{
    	if ((*it)->getType() == animal->getType())
		{
			if ((*it)->getAnimals().size() < 5)
			{
				(*it)->addAnimal(animal);
				cout << "Animal was added successfully!!" << endl;
				return;
			}
			cout << "Animal was not created. There were too many animals in the cage.\n";
		}
	}
	//create cage and added animal to this new cage 
	addCage(animal->getType());
	cages.at(cages.size() - 1)->addAnimal(animal);
	cout << "Cage for this animal created and Animal was added successfully!!" << endl;
}

void Zoo::removeAnimal(int serialNumber)
{
	auto itr_cages = cages.begin();
	auto itr_end = cages.end();
	for (; itr_cages != itr_end; ++itr_cages)
		(*itr_cages)->removeAnimal(serialNumber);
	cout << "Serial number was not belong to any animal!!!" << endl;
}

void Zoo::addEmployee(Employee* employee)
{
	employees.push_back(new Employee(*employee));
    employees2.add(employee);
}

void Zoo::removeEmployee(int employeeNumber)
{
	for (auto it = employees.begin(); it != employees.end(); ++it)
		if ((*it)->getEmployeeNumber() == employeeNumber)
		{
			employees.erase(it);
			return;
		}
	cout << "Cant remove employee, didnt find this employee number: " << employeeNumber << endl;
}

void Zoo::show()
{
	cout << "Zoo " << name << endl;
	cout << "located at: " << address << endl;
	showAllAnimals();
	showAllEmployees();
}

void Zoo::addCage(int type)
{
	for (auto it = cages.begin(); it != cages.end(); ++it)
	{
		if ((*it)->getType() == type) 
		{
			if ((*it)->getAnimals().size() < 5)
			{
				cages.push_back(new Cage(type));
				return;
			}
			cout << "Cage was not created. There is a cage with less than 5 animals in with this type.\n";
			return;
		}
	}
	cages.push_back(new Cage(type));
}

void Zoo::showAllAnimals() const 
{
	cout << "Animals:\n";
	int counter = 0;
	for (auto it = cages.begin(); it != cages.end(); ++it, counter++)
		cout << "Cage number " << counter << ", animals:\n" << **it;
}

void Zoo::showAllEmployees() const 
{
	cout << "\nEmployees:\n";
	int counter = 0;
	for (auto it = employees.begin(); it != employees.end(); ++it, counter++){
        cout << **it << endl;
        cout << "from linked list: " << employees2.head->data->getEmployeeNumber() <<
        "\n" << "name: " << employees2.head->data->getEmployeeName() << " role: "
        << employees2.tail->data->getEmployeeRole();
	}
}

void Zoo::feedAllAnimals()
{
	for (auto it = cages.begin(); it != cages.end(); ++it)
		(*it)->feedAllAnimalsInCage();
}