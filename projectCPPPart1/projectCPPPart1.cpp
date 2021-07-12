#include <iostream>
#include "Zoo.h"
#include "Address.h"
#include "Bat.h"
#include "Lion.h"
#include "Ostrich.h"
#include "Crocodile.h"
#include "Parrot.h"
#include <string.h>
using namespace std;

void menu(){
    cout << "\n";
    cout << "choose action from Menu : \n";
    cout << "choose 1 : for add Animal \n";
    cout << "choose 2 : for Remove Animal \n";
    cout << "choose 3 : for add Employee\n";
    cout << "choose 4 : for Remove Employee \n";
    cout << "choose 5 : for show all Zoo \n";
    cout << "choose 6 : for show all Animals \n";
    cout << "choose 7 : for show all Employees \n";
    cout << "choose 8 : for feed All Animals \n";
    cout << "choose 0 : for exit \n";
}
void addAnimalMenu() {
    cout << "\n";
    cout << "what animal you want to add : \n";
    cout << "choose 1 : for adding a Lion \n";
    cout << "choose 2 : for adding a Crocodile \n";
    cout << "choose 3 : for adding a Parrot\n";
    cout << "choose 4 : for adding a Ostrich \n";
    cout << "choose 5 : for adding a Bat\n";
    cout << "choose 0 : for exit \n";
}
Lion& getLion() {
    int sn;
    char name[20];
    float height;
    float weight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name limit of 20 chars:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;
    
    Lion l(sn, name, height, weight);
    return l;
}
Ostrich& getOstrich(){

    int sn;
    char name[20];
    float height;
    float weight;
    char color[10];
    cout << "give int serial Number: \n";
    cin >> sn;
    cout << "give name limit of 20 chars: \n";
    cin >> name;
    cout << "give the height: \n";
    cin >> height;
    cout << "give the weight: \n";
    cin >> weight;
    cout << "give the color of the ostrich: \n";
    cin >> color;
    Ostrich o(sn, name, height, weight,color);
    return o;
}
Bat& getBat() {

    int sn;
    char name[20];
    float height;
    float weight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name limit of 20 chars:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;
    Bat b(sn, name, height, weight);
    return b;
}
Parrot& getParrot() {
    int sn;
    char name[20];
    float height;
    float weight;
    char color[10];
    float sizeofBeak;
    int speedOfFlight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name limit of 20 chars:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;
    cout << "give the color of the parrot:";
    cin >> color;
    cout << "give the size  of beak of the parrot:";
    cin >> sizeofBeak;
    cout << "give the speed of flight of the parrot:";
    cin >> speedOfFlight;
    Parrot p(sn, name, height, weight, color,sizeofBeak,speedOfFlight);
    return p;
}
Crocodile& getCroc() {
    int sn;
    char name[20];
    float height;
    float weight;
    cout << "give int serial Number:";
    cin >> sn;
    cout << "give name limit of 20 chars:";
    cin >> name;
    cout << "give the height:";
    cin >> height;
    cout << "give the weight:";
    cin >> weight;
    Crocodile c(sn, name, height, weight);
    return c;
}
Employee& getEmployee() {
    int employeNumber;
    char name[20];
    char role[20];
    cout << "give  employe Number:";
    cin >> employeNumber;
    cout << "give name limit of 20 chars:";
    cin >> name;
    cout << "give the role of employee limit of 20 chars::";
    cin >> role;
    Employee e(employeNumber,name,role);
    return e;
}
void addCageMenu() {
    
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
    Address add("bialik", 8, "Ramla");
    const char* nameOfZoo = "Jungle Ramla";
    Zoo zoo(nameOfZoo,6,add);
    int option = 10;
    do {
        
        menu();
        try
        {
            cin >> option;
        }
        catch (const std::exception& )
        {
            cout << "wrong input \n";
           
        }
        switch (option)
        {
        
        case 1:
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
                default:
                    cout << "no option :" << option;

                    break;
                }

            } while (option != 0);
            
            break;
        case 2:
            int sn;
            cout << "give int serial Number of an animal to remove :";
            cin >> sn;
            zoo.removeAnimal(sn);
            break;
        case 3:
            zoo.addEmployee(getEmployee());
            break;
        case 4:
            int em;
            cout << "give int employe number of an employee to remove :";
            cin >> em;
            zoo.removeEmployee(em);
            break;

        case 5:
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
                   cout << "wrong input \n";

               }
                switch (cageOption) {
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
                    cout << "there is no option :" << cageOption;

                    break;
                }
            } while (cageOption != 0);

            break;
        case 6:
            zoo.show();
            cout << "you chose :" << 6;
            break;
        case 7:
            zoo.showAllAnimals();
            break;
        case 8:
            zoo.showAllEmployees();
            break;
        case 9:
            zoo.feedAllAnimals();
            break;
        default:
            cout << "no option :" << option;
            break;
        }

    } while (option != 0);


    return 0;


}


