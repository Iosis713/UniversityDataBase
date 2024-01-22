cmake_minimum_required(VERSION 3.10)
project(UniversityDataBase)


set(CXX_STANDARD REQUIRED 17)
set(FLAGS -Wall -Wpedantic -Wextra -Werror)

find_package(GTest REQUIRED)

add_executable(TestRunner testRunner.cpp)
add_executable(UniversityDataBase main.cpp)

target_link_libraries(TestRunner PRIVATE  ${GTEST_LIBRARIES})

target_compile_options(TestRunner PRIVATE ${FLAGS})
target_compile_options(UniversityDataBase PRIVATE ${FLAGS})

set_target_properties(TestRunner    PROPERTIES
                                    CXX_STANDARD 17
                                    CXX_STANDARD_REQUIRED ON)

set_target_properties(UniversityDataBase    PROPERTIES
                                            CXX_STANDARD 17
                                            CXX_STANDARD_REQUIRED ON)

