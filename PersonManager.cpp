#include "Headers/PersonManager.hpp"

PersonManager::PersonManager()
{
    manager_.reserve(20);
}

void PersonManager::addPerson(const std::string& personType,
                              const std::string& name,
                              const std::string& surname,
                              const std::string& adress,
                              const long int pesel,
                              const std::string& sex)
{
    manager_.push_back(std::make_shared<Person>(personType, name, surname, adress, pesel, sex));
}

void PersonManager::addPerson(const std::string& personType,
                              const std::string& name,
                              const std::string& surname,
                              const std::string& adress,
                              const long int pesel,
                              const std::string& sex,
                              const long int index)
{
    manager_.push_back(std::make_shared<Student>(personType, name, surname, adress, pesel, sex, index));
}


void PersonManager::addEmployee(const std::string& personType,
                              const std::string& name,
                              const std::string& surname,
                              const std::string& adress,
                              const long int pesel,
                              const std::string& sex,
                              float salary)
{
    manager_.push_back(std::make_shared<Employee>(personType, name, surname, adress, pesel, sex, salary));
}

void PersonManager::addToFile(std::string databaseName)
{
    std::ofstream database(databaseName, database.out | database.app);
    if(database.is_open())
    {
        for(const auto& person : manager_)
        {
            database << person->getPersonType() << '\n';
            database << person->getName() << '\n';
            database << person->getSurname() << '\n';
            database << person->getAdress() << '\n';
            database << person->getPesel() << '\n';
            database << person->getSex() << '\n';
            
            if(typeid(*person) == typeid(Student))
            {
                database << std::dynamic_pointer_cast<Student>(person)->getIndex() << '\n';
            }
            
            else if(typeid(*person) == typeid(Employee))
            {
                database << std::dynamic_pointer_cast<Employee>(person)->getSalary();
            }
        }
    }
}

void PersonManager::deleteByIndex(const long int& index)
{
    auto it = std::find_if(manager_.begin(), manager_.end(), [&](const auto& person)
                {
                    auto ptr = std::dynamic_pointer_cast<Student>(person);
                    return ptr && (ptr->getIndex() == index);
                });
    if(it != manager_.end())
    {
        manager_.erase(it);
        std::cout << "Student sucessfully deleted!\n";
    }
    else
    {
        std::cout << "Student with given index number not found!\n";
    }
}

void PersonManager::readFromFile(std::string fileName)
{
    std::fstream database;
    database.open(fileName, database.in);

    if(database.is_open())
    {
        std::string str;
        getline(database, str, '\n');
        while(!database.eof())
        {   
            //std::cout << str << '\n';
            if(str == "Person")
            {
                const std::string tempPersonType = str;
                getline(database, str, '\n');
                const std::string tempName = str;
                getline(database, str, '\n');
                const std::string tempSurname = str;
                getline(database, str, '\n');
                const std::string tempAdress = str;
                getline(database, str, '\n');
                const long int tempPesel = stol(str);
                getline(database, str, '\n');
                const std::string tempSex = str;
                addPerson(tempPersonType, tempName, tempSurname, tempAdress, tempPesel, tempSex);
                
                getline(database, str, '\n');

            }

            else if(str == "Student")
            {
                const std::string tempPersonType = str;
                getline(database, str, '\n');
                const std::string tempName = str;
                getline(database, str, '\n');
                const std::string tempSurname = str;
                getline(database, str, '\n');
                const std::string tempAdress = str;
                getline(database, str, '\n');
                const long int tempPesel = stol(str);
                getline(database, str, '\n');
                const std::string tempSex = str;
                getline(database,str, '\n');
                const long int tempIndex = stol(str);
                addPerson(tempPersonType, tempName, tempSurname, tempAdress, tempPesel, tempSex, tempIndex);
                getline(database, str, '\n');
            }
        }
    }
}

void PersonManager::printAll()
{
    for(auto& person : manager_)
    {
        person->printPerson();
        std::cout << '\n';
    }
}

std::shared_ptr<Person> PersonManager::searchBySurname(const std::string& surname)
{
    for(auto& person : manager_)
    {
        if(surname == person->getSurname())
        {
            person->printPerson();
            std::cout << "\nLook for another person? y/n\n";
            char answer;
            std::cin >> answer;
            if(answer == 'n')
            {
                return person;
            }
        }
    }
    std::cout << "No person found!\n";
    return nullptr;
}

std::shared_ptr<Person> PersonManager::searchByPesel(const long int pesel)
{
    for(auto& person : manager_)
    {
        if(pesel == person->getPesel())
        {
            person->printPerson();
            std::cout << "Look for another person? y/n\n";
            char answer;
            std::cin >> answer;
            if(answer == 'n')
            {
                return person;
            }
        }
    }
    std::cout << "No person found!\n";

    return nullptr;
}

void PersonManager::sortByPesel()
{
    std::sort(manager_.begin(), manager_.end(), [](const std::shared_ptr<Person>& lhs,
                                                   const std::shared_ptr<Person>& rhs)
                                                {
                                                    return lhs->getPesel() < rhs->getPesel();
                                                });
}

void PersonManager::sortBySalary()
{
    //increasing sort
    std::sort(manager_.begin(), manager_.end(), [](const std::shared_ptr<Person>& lhs,
                                                   const std::shared_ptr<Person>& rhs)
            {   
                bool result = (std::dynamic_pointer_cast<Employee>(lhs)->getSalary() < 
                               std::dynamic_pointer_cast<Employee>(rhs)->getSalary());
                
                return result;
            });
}

void PersonManager::sortBySurname()
{
    std::sort(manager_.begin(), manager_.end(), [](const std::shared_ptr<Person>& lhs,
                                                   const std::shared_ptr<Person>& rhs)
            {
                return lhs->getSurname() < rhs->getSurname();
            });
}

//_______________________________GETTERS_______________________________________

std::vector<std::shared_ptr<Person>>& PersonManager::getManager()
{
    return this-> manager_;
}

