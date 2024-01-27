#pragma once
#include <iostream>
#include <string>

class Person
{
protected:
    const std::string personType_;
    std::string name_;
    std::string surname_;
    std::string adress_;
    const long int pesel_;
    const std::string sex_;

public:
    Person(const std::string personType,
           std::string name,
           std::string surname,
           std::string adress,
           const long int pesel,
           const std::string sex);

    virtual ~Person() = default;
    
    bool operator==(const Person& person) const;    
    virtual void printPerson();

//_____________________________GETTERS____________________________

    std::string getName() const;
    std::string getSurname() const;
    std::string getAdress() const;
    long int getPesel() const;
    std::string getSex() const;
    std::string getPersonType() const;
//_____________________________SETTERS____________________________

    void setAdress(const std::string& adress);
    void setName(const std::string& name);
    void setSurname(const std::string& surname);

};

