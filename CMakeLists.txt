cmake_minimum_required(VERSION 3.10)
project(government)

# Add Google Test as a subdirectory
add_subdirectory(googletest)

# Enable testing for this project
enable_testing()

# Add the source files for your project
add_library(Citizen 
    Citizen/AllCitizenIterator.cpp 
    Citizen/CitizenIterator.cpp
    Citizen/Citizen.cpp
    Citizen/Creator.cpp
    Citizen/HighCitizen.cpp 
    Citizen/HighCitizenCreator.cpp 
    Citizen/Income.cpp 
    Citizen/LowCitizen.cpp 
    Citizen/LowCitizenCreator.cpp 
    Citizen/Mayor.cpp 
    Citizen/MayorCreator.cpp 
    Citizen/MayorIterator.cpp 
    Citizen/MiddleCitizen.cpp 
    Citizen/MiddleCitizenCreator.cpp)

add_library(Government 
    Government.cpp 
    GovernmentInvoker.cpp 
    TaxationCommand.cpp 
    PolicyImplementationCommand.cpp 
    Materials.cpp 
    Energy.cpp 
    Water.cpp 
    CityResourceMediator.cpp 
    Budget.cpp 
    BudgetAllocationCommand.cpp 
    Taxes.cpp 
    TaxMemento.cpp)

# Define each test as an executable and link to Google Test
add_executable(AllCitizenIteratorTest tests/AllCitizenIteratorTest.cpp)
target_link_libraries(AllCitizenIteratorTest PRIVATE gtest gtest_main Citizen)

add_executable(CreatorTest tests/CreatorTest.cpp)
target_link_libraries(CreatorTest PRIVATE gtest gtest_main Citizen)

add_executable(HighCitizenTest tests/HighCitizenTest.cpp)
target_link_libraries(HighCitizenTest PRIVATE gtest gtest_main Citizen)

add_executable(LowCitizenTest tests/LowCitizenTest.cpp)
target_link_libraries(LowCitizenTest PRIVATE gtest gtest_main Citizen)

add_executable(MayorIteratorTest tests/MayorIteratorTest.cpp)
target_link_libraries(MayorIteratorTest PRIVATE gtest gtest_main Citizen)

add_executable(MayorTest tests/MayorTest.cpp)
target_link_libraries(MayorTest PRIVATE gtest gtest_main Citizen)

add_executable(MiddleCitizenTest tests/MiddleCitizenTest.cpp)
target_link_libraries(MiddleCitizenTest PRIVATE gtest gtest_main Citizen)

add_executable(CityResourceMediatorTest tests/CityResourceMediatorTest.cpp)
target_link_libraries(CityResourceMediatorTest PRIVATE gtest gtest_main Government)

# Register tests with CMake's testing tool
add_test(NAME AllCitizenIteratorTest COMMAND AllCitizenIteratorTest)
add_test(NAME CreatorTest COMMAND CreatorTest)
add_test(NAME HighCitizenTest COMMAND HighCitizenTest)
add_test(NAME LowCitizenTest COMMAND LowCitizenTest)
add_test(NAME MayorIteratorTest COMMAND MayorIteratorTest)
add_test(NAME MayorTest COMMAND MayorTest)
add_test(NAME MiddleCitizenTest COMMAND MiddleCitizenTest)
add_test(NAME CityResourceMediatorTest COMMAND CityResourceMediatorTest)