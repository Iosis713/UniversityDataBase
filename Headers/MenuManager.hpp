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
public: 
    MenuManager() = default;
    ~MenuManager() = default;
    void displayMenu(PersonManager& manager);
    void displayMenuOptions();
    void setOption();
    
    bool isActive();
};

