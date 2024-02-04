#pragma once

#include "Person.hpp"
#include "Student.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <memory>
#include <typeinfo>
#include <vector>

class PersonManager
{
protected:
    std::vector<std::shared_ptr<Person>> manager_;

public:
    PersonManager();
    //base Person class adding
    void addPerson(const std::string& personType,
                   const std::string& name,
                   const std::string& surname,
                   const std::string& adress,
                   const long int pesel,
                   const std::string& sex);
    
    //Student class adding
    void addPerson(const std::string& personType,
                   const std::string& name,
                   const std::string& surname,
                   const std::string& adress,
                   const long int pesel,
                   const std::string& sex,
                   const long int index);

    void printAll();

    void addToFile(std::string databaseName);
    void readFromFile(std::string fileName);
    
    std::shared_ptr<Person> searchByPesel(const long int pesel);
    std::shared_ptr<Person> searchBySurname(const std::string& surname);
    void sortByPesel();

    std::vector<std::shared_ptr<Person>>& getManager();

};

