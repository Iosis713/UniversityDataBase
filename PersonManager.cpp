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

void PersonManager::printAll()
{
    for(auto& person : manager_)
    {
        person->printPerson();
        std::cout << '\n';
    }
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
        }
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

//_______________________________GETTERS_______________________________________

std::vector<std::shared_ptr<Person>>& PersonManager::getManager()
{
    return this-> manager_;
}

