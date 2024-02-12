#include "Headers/Employee.hpp"

Employee::Employee(const std::string personType,
              std::string name,
              std::string surname,
              std::string adress,
              const long int pesel,
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

void Employee::changeSalary(const float newSalary)
{
    this->salary_ = newSalary;
}

void Employee::printPerson()
{
    Person::printPerson();
    std::cout << salary_ << " \n";
}

float Employee::getSalary() const
{
    return this->salary_;
}


