#include <iostream>
#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"
#include "Headers/MenuManager.hpp"

int main()
{
    PersonManager personManager;
    
    /*
    personManager.addPerson("Person", "Pjoter", "Takijakja", "Ulica", 1122334455, "Male");
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Marek", "Nowa", "Nobezjaj", 11111111, "Male", 0000222);
    personManager.addPerson("Person", "Pjoterka", "Takijakja2", "Tralalalala", 007, "Female");

    personManager.addToFile("database2.txt");
    
       
    std::cout << "Before reading: \n";
    personManager.printAll();

    personManager.readFromFile("database.txt");
    
    std::cout << "After reading: \n";
    personManager.printAll();
    */

    MenuManager menu;
    while(menu.isActive())
    {
        menu.displayMenu(personManager);
    }

   return 0;
}

