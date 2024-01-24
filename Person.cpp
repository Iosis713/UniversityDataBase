#include "Headers/Person.hpp"

Person::Person(std::string name,
               std::string surname,
               std::string adress,
               const long int pesel,
               const char sex)
        : name_(name)
        , surname_(surname)
        , adress_(adress)
        , pesel_(pesel)
        , sex_(sex)
{}

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

//_____________________SETTERS___________________________________________

void Person::setAdress(const std::string& adress)
{
    adress_ = adress;
}

void Person::setName(const std::string& name)
{
    name_ = name;
}

void Person::setSurname(const std::string& surname)
{
    surname_ = surname;
}

