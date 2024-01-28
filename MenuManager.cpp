#include "Headers/MenuManager.hpp"

void MenuManager::displayMenu(PersonManager& manager)
{
    std::cout << "Click number to choose option:\n\n";

    std::cout << "0. Exit\n";
    std::cout << "1. Display actual database\n";
    std::cout << "2. Read database\n";
    std::cout << "3. Save database to file\n";
    std::cout << "4. Add person\n";
    
    setOption();
    std::cout << '\n';
    //std::system("cls");
    //std::clear();
    //std::cout<< u8"\033[2J\033[1;1H"; 

    switch(option_){
    case 0:
        active_ = false;
        std::cout << '\n';
        break;
    case 1:
        std::cout << '\n';
        manager.printAll();
        break;

    case 2:
        std::cout << "Give a file name\n";
        {
            std::string file = "database.txt";
            std::cin >> file;

            manager.readFromFile(file);
        }
        std::cout << '\n';

        break;

    default:
        std::cout << '\n';
        break;
    }

}

void MenuManager::setOption()
{   
    int newOption;
    do{
        std::cin >> newOption;
    }while(newOption > 4);

    option_ = newOption;
}

bool MenuManager::isActive()
{
    return this->active_;
}

