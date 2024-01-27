#include <iostream>
#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"

int main()
{
    Person person1('P', "Bartosz", "TAKIJAKJA", "Ulica", 1122334455, 'M');
    person1.setAdress("Odolanowska");

    PersonManager personManager;
   
    personManager.addPerson('P', "Pjoter", "Takijakja", "Ulica", 1122334455, 'M');
    personManager.addPerson('S', "Bartosz", "Kowalski", "Ulica", 11223344, 'M', 123456);
    personManager.addPerson('S', "Marek", "Nowa", "Nobezjaj", 11111111, 'M', 0000222);

    personManager.addToFile();

    personManager.printAll();

   return 0;
}

