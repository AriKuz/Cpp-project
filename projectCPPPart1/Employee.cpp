#include "Employee.h"

Employee::~Employee()
{
    delete name;
    delete role;
}