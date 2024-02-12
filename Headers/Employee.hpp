#pragma once

#include "Person.hpp"

class Employee : public Person
{
protected:
    float salary_;

public:
    Employee(const std::string personType,
              std::string name,
              std::string surname,
              std::string adress,
              const long int pesel,
              const std::string sex,
              float salary);

    virtual ~Employee() = default;
    
    bool operator==(const Employee& employee) const;

    void changeSalary(const float newSalary);
    void printPerson() override;

    float getSalary() const;
    
};

