#include "Headers/PersonManager.hpp"

PersonManager::PersonManager()
{
    manager_.reserve(20);
}

void PersonManager::addPerson(const char personType,
                              const std::string& name,
                              const std::string& surname,
                              const std::string& adress,
                              const long int pesel,
                              const char sex)
{
    manager_.push_back(std::make_unique<Person>(personType, name, surname, adress, pesel, sex));
}

void PersonManager::addPerson(const char personType,
                              const std::string& name,
                              const std::string& surname,
                              const std::string& adress,
                              const long int pesel,
                              const char sex,
                              const long int index)
{
    manager_.push_back(std::make_unique<Student>(personType, name, surname, adress, pesel, sex, index));
}

void PersonManager::printAll()
{
    for(auto& person : manager_)
    {
        person->printPerson();
        std::cout << '\n';
    }
}

//_______________________________GETTERS_______________________________________

std::vector<std::unique_ptr<Person>>& PersonManager::getManager()
{
    return this-> manager_;
}

