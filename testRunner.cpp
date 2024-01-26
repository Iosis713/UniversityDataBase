#include <iostream>
#include <gtest/gtest.h>

#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"

TEST(AddPersonTest, PersonAdding)
{
    PersonManager personManager;
    personManager.addPerson('P', "Bartosz", "Kowalski", "Ulica", 11223344, 'M');

    Person referencePerson('P', "Bartosz", "Kowalski", "Ulica", 11223344, 'M');

    ASSERT_TRUE(*personManager.getManager()[0] == referencePerson);
}


TEST(AddPersonTest, StudentAdding)
{
    PersonManager personManager;
    personManager.addPerson('S', "Bartosz", "Kowalski", "Ulica", 11223344, 'M', 123456);

    Student referenceStudent('S', "Bartosz", "Kowalski", "Ulica", 11223344, 'M', 123456);

    ASSERT_TRUE(*personManager.getManager()[0] == referenceStudent);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
