#include <iostream>
#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"
#include "Headers/MenuManager.hpp"

int main()
{
/*
    //SORT BY PESEL//SURNAME MANUAL TEST
    
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

    personManager.addPerson("Person", "Andrzej", "Boryna", "ZeSzczecina", 332211445, "Male");
    personManager.addPerson("Person", "Zaneta", "Zmakbeta", "Breslau", 001133667, "Female");
    std::cout << "People added: \n";
    personManager.printAll();


    std::cout << "Sort by surname! \n\n";
    personManager.sortBySurname();
    personManager.printAll();
*/


    PersonManager personManager;

    MenuManager menu;
    while(menu.isActive())
    {
        menu.displayMenu(personManager);
    }

   return 0;
}
