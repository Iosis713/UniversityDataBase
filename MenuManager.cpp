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
        std::cout << '\n';
        break;

    case 2:
        std::cout << "Enter a file name You want to read:\n";
        {
            std::string file = "database.txt";
            std::cin >> file;

            manager.readFromFile(file);
        }
        std::cout << '\n';
        break;

    case 3:
        std::cout << "Enter file name You want to save as:\n";
        {   
            std::string newFileName;
            std::cin >> newFileName;
            manager.addToFile(newFileName);
        }
        break;
    
    case 4:
        {
            std::cout << "Enter person type (Person/Student - Case matters!):\n";
            std::string tempPersonType;
            std::cin >> tempPersonType;
        
            if(tempPersonType == "Person" or
               tempPersonType == "Student")
            {
                std::cout << "Enter name:\n";
                std::string tempName;
                std::cin >> tempName;

                std::cout << "Enter surname:\n";
                std::string tempSurname;
                std::cin >> tempSurname;
        
                std::cout << "Enter adress:\n";
                std::string tempAdress;
                std::cin >> tempAdress;
        
                std::cout << "Enter pesel:\n";
                long int tempPesel;
                std::cin >> tempPesel;

                std::cout << "Enter sex:\n";
                std::string tempSex;
                std::cin >> tempSex;

                if(tempPersonType == "Student")
                    {
                    std::cout << "Enter index number:\n";
                    long int tempIndex;
                    std::cin>> tempIndex;

                    manager.addPerson(tempPersonType,
                                      tempName,
                                      tempSurname,
                                      tempAdress,
                                      tempPesel,
                                      tempSex,
                                      tempIndex);
                    }

                else if(tempPersonType == "Person")
                {
                    manager.addPerson(tempPersonType,
                                      tempName,
                                      tempSurname,
                                      tempAdress,
                                      tempPesel,
                                      tempSex);             
                }
            }

            else
            {   
                std::cout << "Invalid person type!\n";
                break;
            }
            
        }
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

