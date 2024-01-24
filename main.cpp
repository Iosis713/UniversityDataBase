#include <iostream>
#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"

int main()
{
   Person person1("Bartosz", "TAKIJAKJA", "Ulica", 1122334455, 'M');
   person1.setAdress("Odolanowska");

   PersonManager personManager;


   return 0;
}

