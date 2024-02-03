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
    personManager.addPerson("Student", "Bartosz", "Kowalski", "Ulica", 11223344, "Male", 123456);
    
    const std::string referenceSurname = "Alibaba";

    ASSERT_EQ(personManager.searchBySurname("Alibaba"), nullptr);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
