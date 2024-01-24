#include "Headers/Student.hpp"

Student::Student(const std::string name,
        std::string surname,
        std::string adress,
        const long int pesel,
        const char sex,
        const long int index)
    : Person(name, surname, adress, pesel, sex)
    , index_(index)
{}

bool Student::operator==(const Student& student) const
{
    return(name_ == student.getName() and
           surname_ == student.getSurname() and
           adress_ == student.getAdress() and
           pesel_ == student.getPesel() and
           sex_ == student.getSex() and
           index_ == student.getIndex());
}

//________________________GETTERS__________________________

long int Student::getIndex() const
{
    return this->index_;
}




