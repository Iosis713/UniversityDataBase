#include <iostream>
#include <gtest/gtest.h>

#include "Headers/Person.hpp"
#include "Headers/PersonManager.hpp"

TEST(AddPersonTest, testOne)
{
    PersonManager personManager;
    personManager.addPerson("Bartosz", "Kowalski", "Ulica", 11223344, 'M');

    Person referencePerson("Bartosz", "Kowalski", "Ulica", 11223344, 'M');

    ASSERT_TRUE(*personManager.getManager()[0] == referencePerson);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
