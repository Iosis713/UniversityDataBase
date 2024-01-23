#pragma once
#include <iostream>
#include <string>

class Person
{
protected:
    const std::string name_;
    const std::string surname_;
    std::string adress_;
    const long int pesel_;
    const char sex_;

public:
    Person(const std::string name,
           const std::string surname,
           std::string adress,
           const long int pesel,
           const char sex);

    virtual ~Person() = default;
    void changeAdress(const std::string& adress);
    bool operator==(const Person& person) const;    

    std::string getName() const;
    std::string getSurname() const;
    std::string getAdress() const;
    long int getPesel() const;
    char getSex() const;
};

