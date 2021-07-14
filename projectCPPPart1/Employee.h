#pragma warning(disable: 4996)
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;


class Employee
{
private:
	int employeeNumber;
	string name;
	string role;

public:
	Employee(int en, string& nme, string& rol) : employeeNumber(en), name(nme), role(rol){}

	friend ostream& operator<< (ostream& o, const Employee& a)
	{
		cout << "Employee num#" << a.employeeNumber << ", name: " << a.name << ", role:" << a.role << endl;
		return o; 
	}
	int getEmployeeNumber() { return this->employeeNumber;}
	
    std::string getEmployeeName() { return this->name;}
    std::string getEmployeeRole() { return this->role;}
};

#endif 
