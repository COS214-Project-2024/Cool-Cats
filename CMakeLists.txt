cmake_minimum_required(VERSION 3.10)
project(City)

# Add Google Test as a subdirectory
add_subdirectory(googletest)

# Enable testing for this project
enable_testing()

# Add the source files for the Citizen library
add_library(Citizen
    AllCitizenIterator.cpp 
    CitizenIterator.cpp
    Citizen.cpp
    Creator.cpp
    HighCitizen.cpp 
    HighCitizenCreator.cpp 
    Income.cpp 
    LowCitizen.cpp 
    LowCitizenCreator.cpp 
    Mayor.cpp 
    MayorCreator.cpp 
    MayorIterator.cpp 
    MiddleCitizen.cpp 
    MiddleCitizenCreator.cpp
)

# Add the source files for the Government library
add_library(government
    Government.cpp
    GovernmentInvoker.cpp
    PolicyImplementationCommand.cpp
    TaxationCommand.cpp
    Taxes.cpp
    TaxMemento.cpp
    BudgetAllocationCommand.cpp
    CityResourceMediator.cpp
    Energy.cpp
    Materials.cpp
    Water.cpp
)

add_library(utilities
    Utilities.cpp
    WasteUtility.cpp
    WaterUtility.cpp
    PowerUtility.cpp
    SewageUtility.cpp


)

add_library(Buildings
    Structure.cpp
    BasicStructure.cpp
    StructureGroup.cpp
    StructureDecorator.cpp
    StructureIterator.cpp
    CstructIterator.cpp
    MaintenanceCostReducer.cpp
    ResourceEfficiencyEnhancer.cpp
    SatisfactionEnhancer.cpp
)

# Link the library with the City library
target_link_libraries(citizen PRIVATE City)
target_link_libraries(government PRIVATE City)

# Define each test as an executable and link to Google Test and the appropriate libraries
add_executable(AllCitizenIteratorTest Tests/AllCitizenIteratorTest.cpp)
target_link_libraries(AllCitizenIteratorTest PRIVATE gtest gtest_main Citizen)

add_executable(CreatorTest Tests/CreatorTest.cpp)
target_link_libraries(CreatorTest PRIVATE gtest gtest_main Citizen)

add_executable(HighCitizenTest Tests/HighCitizenTest.cpp)
target_link_libraries(HighCitizenTest PRIVATE gtest gtest_main Citizen)

add_executable(LowCitizenTest Tests/LowCitizenTest.cpp)
target_link_libraries(LowCitizenTest PRIVATE gtest gtest_main Citizen)

add_executable(MayorIteratorTest Tests/MayorIteratorTest.cpp)
target_link_libraries(MayorIteratorTest PRIVATE gtest gtest_main Citizen)

add_executable(MayorTest Tests/MayorTest.cpp)
target_link_libraries(MayorTest PRIVATE gtest gtest_main Citizen)

add_executable(MiddleCitizenTest Tests/MiddleCitizenTest.cpp)
target_link_libraries(MiddleCitizenTest PRIVATE gtest gtest_main Citizen)

add_executable(GovernmentTest Tests/GovernmentTest.cpp)
target_link_libraries(GovernmentTest PRIVATE gtest gtest_main government Citizen)

add_executable(TaxesTest Tests/TaxesTest.cpp)
target_link_libraries(TaxesTest PRIVATE gtest gtest_main government Citizen)

add_executable(TaxMementoTest Tests/TaxMementoTest.cpp)
target_link_libraries(TaxMementoTest PRIVATE gtest gtest_main government Citizen)

# Register tests with CMake's testing tool
add_test(NAME AllCitizenIteratorTest COMMAND AllCitizenIteratorTest)
add_test(NAME CreatorTest COMMAND CreatorTest)
add_test(NAME HighCitizenTest COMMAND HighCitizenTest)
add_test(NAME LowCitizenTest COMMAND LowCitizenTest)
add_test(NAME MayorIteratorTest COMMAND MayorIteratorTest)
add_test(NAME MayorTest COMMAND MayorTest)
add_test(NAME MiddleCitizenTest COMMAND MiddleCitizenTest)
add_test(NAME GovernmentTest COMMAND GovernmentTest)
add_test(NAME TaxesTest COMMAND TaxesTest)
add_test(NAME TaxMementoTest COMMAND TaxMementoTest)