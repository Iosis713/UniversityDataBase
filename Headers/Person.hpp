#pragma once
#include <iostream>
#include <string>

class Person
{
protected:
    std::string name_;
    std::string surname_;
    std::string adress_;
    const long int pesel_;
    const char sex_;

public:
    Person(std::string name,
           std::string surname,
           std::string adress,
           const long int pesel,
           const char sex);

    virtual ~Person() = default;
    
    bool operator==(const Person& person) const;    
    //virtual void printPerson();

//_____________________________GETTERS____________________________

    std::string getName() const;
    std::string getSurname() const;
    std::string getAdress() const;
    long int getPesel() const;
    char getSex() const;

//_____________________________SETTERS____________________________

    void setAdress(const std::string& adress);
    void setName(const std::string& name);
    void setSurname(const std::string& surname);

};

