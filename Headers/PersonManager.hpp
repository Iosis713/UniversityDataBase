#pragma once

#include "Person.hpp"
#include "Student.hpp"
#include <memory>
#include <vector>

class PersonManager
{
protected:
    std::vector<std::unique_ptr<Person>> manager_;

public:
    PersonManager();
    //base Person class adding
    void addPerson(const std::string& name,
                   const std::string& surname,
                   const std::string& adress,
                   const long int pesel,
                   const char sex);
    
    //Student class adding
    void addPerson(const std::string& name,
                   const std::string& surname,
                   const std::string& adress,
                   const long int pesel,
                   const char sex,
                   const long int index);
    


    std::vector<std::unique_ptr<Person>>& getManager();

};

