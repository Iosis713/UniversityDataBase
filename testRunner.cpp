#include <iostream>
#include <gtest/gtest.h>

#include "Headers/Person.hpp"
#include "Headers/Student.hpp"
#include "Headers/PersonManager.hpp"

TEST(AddPersonTest, PersonAdding)
{
    PersonManager personManager;
    personManager.addPerson("Person", "Bartosz", "Kowalski", "Ulica", 11223344, "Male");

    Person referencePerson("Person", "Bartosz", "Kowalski", "Ulica", 11223344, "Male");

    ASSERT_TRUE(*personManager.getManager()[0] == referencePerson);
}


TEST(AddPersonTest, StudentAdding)
{
    PersonManager personManager;
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 11223344, "Male", 123456);

    Student referenceStudent("Student", "Bartosz", "Kowalski", "Ulica", 11223344, "Male", 123456);

    ASSERT_TRUE(*personManager.getManager()[0] == referenceStudent);
}

TEST(SearchBySurname, positiveFound)
{
    PersonManager personManager;
    
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 11223344, "Male", 123456);
    
    const std::string referenceSurname = "Kowalczyk";

    ASSERT_STREQ(personManager.searchBySurname("Kowalczyk")->getSurname().c_str(), referenceSurname.c_str());
}


TEST(SearchBySurname, negativeFound)
{
    PersonManager personManager;
    
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 10223344, "Male", 123456);
    
    const std::string referenceSurname = "Alibaba";

    ASSERT_EQ(personManager.searchBySurname("Alibaba"), nullptr);
}

TEST(SearchByPesel, positiveFound)
{
    PersonManager personManager;
    
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 111222333, "Male", 123456);
    
    const long int referencePesel = 111222333;

    ASSERT_EQ(personManager.searchByPesel(referencePesel)->getPesel(), referencePesel);
}


TEST(SearchByPesel, negativeFound)
{
    PersonManager personManager;
    
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 11223344, "Male", 123456);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 111222333, "Male", 123456);
    
    const long int referencePesel = 000111222;

    ASSERT_EQ(personManager.searchByPesel(referencePesel), nullptr);
}

TEST(SortingByPesel, peselSorting1)
{
    PersonManager personManager;
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 222333444, "Male", 111111);

    PersonManager referencePersonManager;
    referencePersonManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);
    referencePersonManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    referencePersonManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 222333444, "Male", 111111);
 
    personManager.sortByPesel();
    bool result;
    
    for(int i = 0; i < static_cast<int>(personManager.getManager().size()); i++)
    {
        if(personManager.getManager()[i]->getPesel() !=
           referencePersonManager.getManager()[i]->getPesel())
        {
            result = false;
            break;
        }
        result = true;
    }

    ASSERT_TRUE(result);
}

TEST(DeleteByIndex, deletePositive)
{
    PersonManager personManager;
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 222333444, "Male", 111111);

    PersonManager referencePersonManager;
    referencePersonManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    referencePersonManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);

    personManager.deleteByIndex(111111);
    
    bool result;
    for(int i = 0; i < static_cast<int>(personManager.getManager().size()); i++)
    {
        if(!(*personManager.getManager()[i] == *referencePersonManager.getManager()[i]))
        {
            result = false;
            break;
        }
        else
        {
            result = true;
        }
    }

    ASSERT_TRUE(result);
}

TEST(DeleteByIndex, deleteNegative)
{
    PersonManager personManager;
    personManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    personManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 222333444, "Male", 111111);

    PersonManager referencePersonManager;
    referencePersonManager.addPerson("Student", "Adam", "Malysz", "Ulica", 111222333, "Male", 333333);
    referencePersonManager.addPerson("Student", "Bartosz", "Kowalczyk", "Ulica", 101202303, "Male", 222222);
    referencePersonManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 222333444, "Male", 111111);
    personManager.deleteByIndex(100000);

    bool result;
    for(int i = 0; i < static_cast<int>(personManager.getManager().size()); i++)
    {
        if(!(*personManager.getManager()[i] == *referencePersonManager.getManager()[i]))
        {
            result = false;
            break;
        }
        else
        {
            result = true;
        }
    }

    ASSERT_TRUE(result);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
