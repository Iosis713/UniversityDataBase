#pragma once

#include "Person.hpp"
#include <memory>
#include <vector>

class PersonManager
{
protected:
    std::vector<std::unique_ptr<Person>> manager_;

public:
    PersonManager();
    void addPerson(const std::string& name,
                   const std::string& surname,
                   const std::string& adress,
                   const long int pesel,
                   const char sex);
    
    std::vector<std::unique_ptr<Person>>& getManager();

};

