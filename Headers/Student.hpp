#pragma once

#include "Person.hpp"

class Student : public Person
{
protected:
    const long int index_;

public:
    Student(const std::string name,
            std::string surname,
            std::string adress,
            const long int pesel,
            const char sex,
            const long int index);

    virtual ~Student() = default;
    
    bool operator==(const Student& student) const;

//_________________________GETTERS____________________________

    long int getIndex() const;

};

