#include <iostream>
#include "Zoo.h"
#include "Address.h"
#include "Bat.h"
#include "Lion.h"
#include "Ostrich.h"
#include "Crocodile.h"
#include "Parrot.h"
#include <string.h>
#include <string>
using namespace std;

void menu()
{
    cout << "\n";
    cout << "Choose action from menu : \n";
    cout << "Choose 1 : to add an animal \n";
    cout << "Choose 2 : to remove an animal \n";
    cout << "Choose 3 : to add an Employee\n";
    cout << "Choose 4 : to remove an employee \n";
    cout << "Choose 5 : to add a cage \n";
    cout << "Choose 6 : to show all zoo \n";
    cout << "Choose 7 : to show all the animals \n";
    cout << "Choose 8 : to show all the employees \n";
    cout << "Choose 9 : to feed all the animals \n";
    cout << "Choose 0 : to exit \n";
}
void addAnimalMenu()
{
    cout << "\n";
    cout << "What animal you want to add : \n";
    cout << "Choose 1 : for adding a Lion \n";
    cout << "Choose 2 : for adding a Crocodile \n";
    cout << "Choose 3 : for adding a Parrot\n";
    cout << "Choose 4 : for adding a Ostrich \n";
    cout << "Choose 5 : for adding a Bat\n";
    cout << "Choose 0 : for exit \n";
}
Lion* getLion()
{
    int sn;
    string name;
    float height;
    float weight;
    cout << "Please specify the serial Number (int):\n";
    cin >> sn;
    cout << "Please specify the name (limit of 20 chars):\n";
    cin >> name;
    cout << "Please specify the height (int):\n";
    cin >> height;
    cout << "Please specify the weight (int):\n";
    cin >> weight;

    return new Lion(sn, name, height, weight);
}
Ostrich* getOstrich()
{

    int sn;
    string name;
    float height;
    float weight;
    string color;
    cout << "Please specify the serial Number (int): \n";
    cin >> sn;
    cout << "Please specify the name (limit of 20 chars): \n";
    cin >> name;
    cout << "Please specify the height (int): \n";
    cin >> height;
    cout << "Please specify the weight (int): \n";
    cin >> weight;
    cout << "Please specify the color of the ostrich (char): \n";
    cin >> color;
    
    return new Ostrich(sn, name, height, weight,color);
}
Bat* getBat()
{

    int sn;
    string name;
    float height;
    float weight;
    cout << "Please specify the serial Number (int):\n";
    cin >> sn;
    cout << "Please specify the name (limit of 20 chars):\n";
    cin >> name;
    cout << "Please specify the height (int):\n";
    cin >> height;
    cout << "Please specify the weight (int):\n";
    cin >> weight;
    
    return new Bat(sn, name, height, weight);
}
Parrot* getParrot() 
{
    int sn;
    string name;
    float height;
    float weight;
    string color;
    float sizeofBeak;
    int speedOfFlight;
    cout << "Please specify the serial Number (int):\n";
    cin >> sn;
    cout << "Please specify the name (limit of 20 chars):\n";
    cin >> name;
    cout << "Please specify the height (int):\n";
    cin >> height;
    cout << "Please specify the weight (int):\n";
    cin >> weight;
    cout << "Please specify the color of the parrot (string):\n";
    cin >> color;
    cout << "Please specify the size  of beak of the parrot (int):\n";
    cin >> sizeofBeak;
    cout << "Please specify the speed of flight of the parrot (int):\n";
    cin >> speedOfFlight;
    
    return new Parrot(sn, name, height, weight, color,sizeofBeak,speedOfFlight);
}
Crocodile* getCroc()
{
    int sn;
    string name;
    float height;
    float weight;
    cout << "Please specify the serial Number (int):\n";
    cin >> sn;
    cout << "Please specify the name (limit of 20 chars):\n";
    cin >> name;
    cout << "Please specify the height (int):\n";
    cin >> height;
    cout << "Please specify the weight (int):\n";
    cin >> weight;
    
    return new Crocodile(sn, name, height, weight);
}
Employee* getEmployee()
{
    int employeNumber;
    string name;
    string role;
    cout << "Please specify the employe Number (int):\n";
    cin >> employeNumber;
    cout << "Please specify the name (limit of 20 chars):\n";
    cin >> name;
    cout << "Please specify the role of employee (limit of 20 chars):\n";
    cin >> role;
    cout << "adding employee...." << endl;
    return new Employee(employeNumber, name, role);
}
void addCageMenu()
{
    
    cout << "choose type of cage that this zoo can add \n";
    cout << "1 for Lion \n";
    cout << "2 for Crocodile \n";
    cout << "3 for Parrot \n";
    cout << "4 for Bat \n";
    cout << "5 for Ostrich \n";
    cout << "0 for exit \n";
}

int main()
{
    Address add("Bialik", 8, "Ramla");
    const string nameOfZoo = "Jungle Ramla";
    Zoo zoo = *(Zoo::getInstance(nameOfZoo, add));
    int option = 10;
    do {
        
        menu();
        try
        {
            cin >> option;
        }
        catch (const std::exception& )
        {
            cout << "Wrong input \n";
        }
        switch (option)
        {
        
        case 1:
            cout << "You chose : add an animal" << endl;
            int animalOption;
            
            do {
                addAnimalMenu();
                try
                {
                    cin >> animalOption;       
                }
                catch (const std::exception&)
                {
                    cout << "wrong input \n";

                }
                switch (animalOption) 
                {
                case 1:
                    zoo.addAnimal(getLion());
                    break;
                case 2:
                    zoo.addAnimal(getCroc());
                    break;
                case 3:
                    zoo.addAnimal(getParrot());
                    break;
                case 4:
                    zoo.addAnimal(getOstrich());
                    break;
                case 5:
                    zoo.addAnimal(getBat());
                    break;
                case 0:
                    cout << "Exiting animal addition menu" << endl;
                    break;
                default:
                    cout << "Invalid option :" << option << ", please try again\n";
                    break;
                }

            } while (animalOption != 0);
            
            break;
        case 2:
            cout << "You chose : remove an animal" << endl;
            int sn;
            cout << "Please specify a serial number of an animal to remove (int):\n";
            cin >> sn;
            zoo.removeAnimal(sn);
            break;
        case 3:
            cout << "You chose : add an employee" << endl;
            zoo.addEmployee(getEmployee());
            break;
        case 4:
            cout << "You chose : remove an employee" << endl;
            int em;
            cout << "Please specify the employe number of the employee which you would like to remove (int):\n";
            cin >> em;
            zoo.removeEmployee(em);
            break;

        case 5:
            cout << "You chose : add a cage" << endl;
            int cageOption ;

            do
            {
                addCageMenu();
                   try
               {
                   cin >> cageOption;
               }
               catch (const std::exception&)
               {
                   cout << "Wrong input \n";
               }
                switch (cageOption)
                {
                    case 1:
                        zoo.addCage(LION);
                        break;

                    case 2:
                        zoo.addCage(CROCODILE);
                        break;

                    case 3:
                        zoo.addCage(PARROT);
                        break;

                    case 4:
                        zoo.addCage(BAT);
                        break;

                    case 5:
                        zoo.addCage(OSTRICH);
                        break;

                    default:
                        cout << "Invalid option " << cageOption << ", please try again\n";
                        break;
                }
            } while (cageOption != 0);

            break;
        case 6:
            cout << "You chose : show all zoo" << endl;
            zoo.show();
            break;
        case 7:
            cout << "You chose : show all the animals" << endl;
            zoo.showAllAnimals();
            break;
        case 8:
            cout << "You chose : show all the employees" << endl;
            zoo.showAllEmployees();
            break;
        case 9:
            cout << "You chose : feed all the animals" << endl;
            zoo.feedAllAnimals();
            break;
        default:
            cout << "Invalid option " << option << ", please try again" << endl;
            break;
        }

    } while (option != 0);

    return 0;
}