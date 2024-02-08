#include <iostream>
#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"
#include "Headers/MenuManager.hpp"

int main()
{
    PersonManager personManager;

    MenuManager menu;
    while(menu.isActive())
    {
        menu.displayMenuOptions();
        menu.displayMenu(personManager);
    }

   return 0;
}
