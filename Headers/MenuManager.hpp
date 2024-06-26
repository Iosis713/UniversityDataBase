#pragma once

#include <iostream>

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
    void displayOptions();
    void setOption();
    
    bool isActive();
};

