#include <iostream>
#include <gtest/gtest.h>

#include "Headers/Person.hpp"
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

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
