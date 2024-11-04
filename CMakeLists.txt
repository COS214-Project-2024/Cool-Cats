cmake_minimum_required(VERSION 3.10)
project(City)

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
    Citizen/MiddleCitizenCreator.cpp
    )
add_library(government
    #  Citizen/AllCitizenIterator.cpp 
    # Citizen/CitizenIterator.cpp
    # Citizen/Citizen.cpp
    # Citizen/Creator.cpp
    # Citizen/HighCitizen.cpp 
    # Citizen/HighCitizenCreator.cpp 
    # Citizen/Income.cpp 
    # Citizen/LowCitizen.cpp 
    # Citizen/LowCitizenCreator.cpp 
    # Citizen/Mayor.cpp 
    # Citizen/MayorCreator.cpp 
    # Citizen/MayorIterator.cpp 
    # Citizen/MiddleCitizen.cpp 
    # Citizen/MiddleCitizenCreator.cpp
    government/Government.cpp
    government/GovernmentInvoker.cpp
    government/PolicyImplementationCommand.cpp
    government/TaxationCommand.cpp
    government/Taxes.cpp
    government/TaxMemento.cpp
    government/BudgetAllocationCommand.cpp
    government/CityResourceMediator.cpp
    government/Energy.cpp
    government/Materials.cpp
    government/Water.cpp
    )

# Link the government library with the Citizen library
target_link_libraries(government PRIVATE Citizen)

# Define each test as an executable and link to Google Test
# add_executable(AllCitizenIteratorTest tests/AllCitizenIteratorTest.cpp)
# target_link_libraries(AllCitizenIteratorTest PRIVATE gtest gtest_main Citizen)

# add_executable(CreatorTest tests/CreatorTest.cpp)
# target_link_libraries(CreatorTest PRIVATE gtest gtest_main Citizen)

# add_executable(HighCitizenTest tests/HighCitizenTest.cpp)
# target_link_libraries(HighCitizenTest PRIVATE gtest gtest_main Citizen)

# add_executable(LowCitizenTest tests/LowCitizenTest.cpp)
# target_link_libraries(LowCitizenTest PRIVATE gtest gtest_main Citizen)

# add_executable(MayorIteratorTest tests/MayorIteratorTest.cpp)
# target_link_libraries(MayorIteratorTest PRIVATE gtest gtest_main Citizen)

# add_executable(MayorTest tests/MayorTest.cpp)
# target_link_libraries(MayorTest PRIVATE gtest gtest_main Citizen)

# add_executable(MiddleCitizenTest tests/MiddleCitizenTest.cpp)
# target_link_libraries(MiddleCitizenTest PRIVATE gtest gtest_main Citizen)

add_executable(GovernmentTest tests/GovernmentTest.cpp)
target_link_libraries(GovernmentTest PRIVATE gtest gtest_main government)

add_executable(TaxesTest tests/TaxesTest.cpp)
target_link_libraries(TaxesTest PRIVATE gtest gtest_main government)

add_executable(TaxMementoTest tests/TaxMementoTest.cpp)
target_link_libraries(TaxMementoTest PRIVATE gtest gtest_main government)

# Register tests with CMake's testing tool
# add_test(NAME AllCitizenIteratorTest COMMAND AllCitizenIteratorTest)
# add_test(NAME CreatorTest COMMAND CreatorTest)
# add_test(NAME HighCitizenTest COMMAND HighCitizenTest)
# add_test(NAME LowCitizenTest COMMAND LowCitizenTest)
# add_test(NAME MayorIteratorTest COMMAND MayorIteratorTest)
# add_test(NAME MayorTest COMMAND MayorTest)
# add_test(NAME MiddleCitizenTest COMMAND MiddleCitizenTest)
add_test(NAME GovernmentTest COMMAND GovernmentTest )
add_test(NAME TaxesTest COMMAND TaxesTest )
add_test(NAME TaxMementoTest COMMAND TaxMementoTest )