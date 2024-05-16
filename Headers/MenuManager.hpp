#pragma once

#include <iostream>
//#include <stdlib.h>
//#include <curses.h>
#include "PersonManager.hpp"

class MenuManager
{
protected:
    int option_ = 1;
    bool active_ = true;

    void addPersonToDatabase(PersonManager& manager);

public: 
    MenuManager() = default;
    ~MenuManager() = default;
    void displayMenu(PersonManager& manager);

    void setOption();
    
    bool isActive();
};

