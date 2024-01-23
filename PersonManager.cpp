#include "Headers/PersonManager.hpp"

PersonManager::PersonManager()
{
    manager_.reserve(20);
}

void PersonManager::addPerson(const std::string& name,
                              const std::string& surname,
                              const std::string& adress,
                              const long int pesel,
                              const char sex)
{
    manager_.push_back(std::make_unique<Person>(name, surname, adress, pesel, sex));
}


//_______________________________GETTERS_______________________________________

std::vector<std::unique_ptr<Person>>& PersonManager::getManager()
{
    return this-> manager_;
}

