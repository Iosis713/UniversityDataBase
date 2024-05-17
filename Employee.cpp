#include "Headers/Employee.hpp"

Employee::Employee(const std::string personType,
              std::string name,
              std::string surname,
              std::string adress,
              const unsigned long int pesel,
              const std::string sex,
              float salary)
    : Person(personType, name, surname, adress, pesel, sex)
    , salary_(salary)
{}

bool Employee::operator==(const Employee& employee) const
{
    return(personType_ == employee.getPersonType() and
           name_ == employee.getName() and
           surname_ == employee.getSurname() and
           adress_ == employee.getAdress() and
           pesel_ == employee.getPesel() and
           sex_ == employee.getSex() and
           salary_ == employee.getSalary());
}

float Employee::getSalary() const
{
    return this->salary_;
}

void Employee::printPerson()
{
    Person::printPerson();
    std::cout << salary_ << " ";
}


