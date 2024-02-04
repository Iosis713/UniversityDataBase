#include <iostream>
#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"
#include "Headers/MenuManager.hpp"

int main()
{
/*
 *  SORT BY PESEL MANUAL TEST
    PersonManager personManager;
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 222333444, "Male", 111111);

    PersonManager referencePersonManager;
    referencePersonManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);
    referencePersonManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    referencePersonManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 222333444, "Male", 111111);
    
    personManager.sortByPesel();
    personManager.printAll();
    referencePersonManager.printAll();
*/

    MenuManager menu;
    while(menu.isActive())
    {
        menu.displayMenu(personManager);
    }

   return 0;
}
