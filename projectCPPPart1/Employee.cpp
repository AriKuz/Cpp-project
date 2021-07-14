#include "Employee.h"


Employee::Employee(int en, char* nme, char* rol) {
		employeeNumber = en;
        name = strdup(nme);
		role = strdup(rol);
}

Employee::~Employee()
{
    delete name;
    delete role;
}

ostream& operator<< (ostream& o, const Employee& a)
{
		cout << "Employee number: " << a.employeeNumber << ", name: " << a.name << ", role:" << a.role << endl;
		return o; 
}