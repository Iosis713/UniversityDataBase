#pragma once

#include "Person.hpp"

class Student : public Person
{
protected:
    const unsigned long int index_;

public:
    Student(const std::string personType,
            const std::string name,
            std::string surname,
            std::string adress,
            const unsigned long int pesel,
            const std::string sex,
            const unsigned long int index);

    virtual ~Student() = default;
    
    bool operator==(const Student& student) const;
    void printPerson();
    

//_________________________GETTERS____________________________

    unsigned long int getIndex() const;

};

