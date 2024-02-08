cmake_minimum_required(VERSION 3.10)
project(UniversityDataBase)


set(CXX_STANDARD REQUIRED 17)
set(FLAGS -Wall -Wpedantic -Wextra -Werror)
set(SRC  Person.cpp
         Student.cpp
         Employee.cpp
         PersonManager.cpp
         MenuManager.cpp)

find_package(GTest REQUIRED)

add_library(${PROJECT_NAME}-lib   ${SRC})

add_executable(TestRunner testRunner.cpp)
add_executable(UniversityDataBase main.cpp)

target_link_libraries(TestRunner PRIVATE  ${GTEST_LIBRARIES}
                                          ${PROJECT_NAME}-lib)


target_link_libraries(${PROJECT_NAME} PRIVATE  ${GTEST_LIBRARIES}
                                               ${PROJECT_NAME}-lib)


target_compile_options(${PROJECT_NAME}-lib   PRIVATE ${FLAGS})
target_compile_options(TestRunner PRIVATE ${FLAGS})
target_compile_options(UniversityDataBase PRIVATE ${FLAGS})


set_target_properties(${PROJECT_NAME}-lib    PROPERTIES
                                             CXX_STANDARD 17
                                             CXX_STANDARD_REQUIRED ON)

set_target_properties(TestRunner    PROPERTIES
                                    CXX_STANDARD 17
                                    CXX_STANDARD_REQUIRED ON)

set_target_properties(${PROJECT_NAME}    PROPERTIES
                                         CXX_STANDARD 17
                                         CXX_STANDARD_REQUIRED ON)

