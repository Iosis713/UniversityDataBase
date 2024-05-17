#include "Headers/MenuManager.hpp"

void MenuManager::addPersonToDatabase(PersonManager& manager)
{
    std::cout << "Enter person type (Person/Student/Employee - Case matters!):\n";
    std::string tempPersonType;
    std::cin >> tempPersonType;
        
    if(tempPersonType == "Person" or
       tempPersonType == "Student" or
       tempPersonType == "Employee")
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
        else if(tempPersonType == "Employee")
        {
            std::cout << "Enter salary:\n";
            float tempSalary;
            std::cin >> tempSalary;
                    
            manager.addEmployee(tempPersonType,
                                tempName,
                                tempSurname,
                                tempAdress,
                                tempPesel,
                                tempSex,
                                tempSalary);
        }
    }

    else
    {   
        std::cout << "Invalid person type!\n";
    }     
}

void MenuManager::displayMenu(PersonManager& manager)
{
    std::cout << "Click number to choose option:\n\n";

    std::cout << "0. Exit\n";
    std::cout << "1. Display actual database\n";
    std::cout << "2. Read database\n";
    std::cout << "3. Save database to file\n";
    std::cout << "4. Add person\n";
    std::cout << "5. Search by pesel\n";
    std::cout << "6. Serach by surname\n";
    std::cout << "7. Sort by pesel\n";
    std::cout << "8. Sort by surname\n";

    setOption();
    std::cout << '\n'; 

    switch(option_){
    case 0:
        {
            active_ = false;
            std::cout << '\n';
            break;
        }
    case 1:
        { 
            std::cout << '\n';
            manager.printAll();
            std::cout << '\n';
            break;
        }
    case 2:
        {
            std::cout << "Enter a file name You want to read:\n";
            std::string file;
            std::cin >> file;
            manager.readFromFile(file);
            std::cout << '\n';
            break;
        }
    case 3:
        {
            std::cout << "Enter file name You want to save as:\n";   
            std::string newFileName;
            std::cin >> newFileName;
            manager.addToFile(newFileName);
            break;
        }
    case 4:
        {
            addPersonToDatabase(manager);
            break;
        }
    case 5:
        {
            std::cout << "Enter pesel of person You are looking for:\n";
            long int pesel;
            std::cin >> pesel;
            manager.searchByPesel(pesel);
            break;
        }
    case 6:
        {
            std::cout << "Enter surname of person You are looking for:\n";
            std::string surname;
            std::cin >> surname;
            manager.searchBySurname(surname);
            break;
        }
    case 7:
        {
            std::cout << "Sorting by pesel number!\n";
            manager.sortByPesel();
            break;
        }
    case 8:
        {
            std::cout << "Sorting by surname!\n";
            manager.sortBySurname();
            break;        
        }
    default:
        {
            std::cout << '\n';
            break;
        }
    }
}

void MenuManager::setOption()
{   
    int newOption;
    do{
        std::cin >> newOption;
        if(newOption > 8 or newOption < 0)
        {
            std::cout << "\nSELECTED OPTION IS OUT OF RANGE!\n";
        }
    }while(newOption > 8 or newOption < 0);

    option_ = newOption;
}

bool MenuManager::isActive()
{
    return this->active_;
}

