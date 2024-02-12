#include "Headers/MenuManager.hpp"

void MenuManager::displayMenu(PersonManager& manager)
{
    setOption();
    std::cout << '\n';   

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
                    std::cin >> tempIndex;

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
                    std::cout << "Enter salary: \n";
                    float tempSalary = 0;
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
                break;
            }
            
        }
        break;
    
    case 5:
    {
        manager.sortByPesel();
        break;
    }

    case 6:
    {
        manager.sortBySalary();
        break;
    }

    case 7:
    {
        manager.sortBySurname();
        break;
    }

    case 8:
    {
        std::cout << "Pass index number to delete: \n";
        long int index = 0;
        std::cin >> index;

        manager.deleteByIndex(index);
        break;
    }
    
    case 9:
    {
        long int tempPesel = 0;
        float salary = 0;
        std::cout << "Pass pesel: \n";
        std::cin >> tempPesel;
        std::cout << "\nPass new salary:\n";
        std::cin >>  salary;
        std::shared_ptr<Person> tempPtr = manager.searchByPesel(tempPesel);

        if(tempPtr)
        {
            
            if(tempPtr->getPersonType() == "Employee")
            {
                std::dynamic_pointer_cast<Employee>(tempPtr)->changeSalary(salary);
            }
            else
            {
                std::cout << "Person type IS NOT 'Employee'\n";
            }
        }
        break;

    }
    default:
        std::cout << '\n';
        break;
    }
}

void MenuManager::displayMenuOptions()
{
    std::cout << "Click number to choose option:\n\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Display actual database\n";
    std::cout << "2. Read database\n";
    std::cout << "3. Save database to file\n";
    std::cout << "4. Add person\n";
    std::cout << "5. Sort by pesel\n";
    std::cout << "6. Sort by salary\n";
    std::cout << "7. Sort by surname\n";
    std::cout << "8. Delete by index\n";
    std::cout << "9. Find by pesel and change salary\n";

//search by surname/pesel has to be added here!
}

void MenuManager::setOption()
{   
    int newOption;
    do{
        std::cin >> newOption;
    }while(newOption > 9);

    option_ = newOption;
}

bool MenuManager::isActive()
{
    return this->active_;
}

