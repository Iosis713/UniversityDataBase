#include "Headers/Person.hpp"

Person::Person(const std::string name,
               const std::string surname,
               std::string adress,
               const long int pesel,
               const char sex)
        : name_(name)
        , surname_(surname)
        , adress_(adress)
        , pesel_(pesel)
        , sex_(sex)
{}

void Person::changeAdress(const std::string& adress)
{
    adress_ = adress;
}

bool Person::operator==(const Person& person) const
{
    return(name_ == person.getName() and
           surname_ == person.getSurname() and
           adress_ == person.getAdress() and
           pesel_ == person.getPesel() and
           sex_ == person.getSex());
}


//_______________________GETTERS______________________________________

std::string Person::getName() const
{
    return this->name_;
}

std::string Person::getSurname() const
{
    return this->surname_;
}

std::string Person::getAdress() const
{
    return this->adress_;
}

long int Person::getPesel() const
{
    return this->pesel_;
}

char Person::getSex() const
{
    return this->sex_;
}


