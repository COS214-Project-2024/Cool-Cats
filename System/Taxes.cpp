#include"Taxes.h"
#include"TaxMemento.h"
#include<iostream>

// Sample static budget variable for illustration
static float cityBudget = 1000000.0f; // Initial city budget for demonstration


/// @brief this is the constructor of the Taxes function
/// @param one is a float that then initialize
Taxes::Taxes(float one ){ 
    taxRate = one;
    //utilityCharge = two;
}

Taxes::~Taxes(){
    
}

/// @brief Creates a memento to save the current state of the Taxes object.
/// @return A pointer to a TaxMemento object that holds the current state.
TaxMemento* Taxes::createMemento(){
return  new TaxMemento(this);


}

/// @brief Simulates the collection of taxes by increasing the city's budget
///        based on the current tax rate.
void Taxes::collection() {
    // Simulate tax collection by increasing the city's budget based on the tax rate
    float collectedAmount = cityBudget * taxRate; // Collect tax based on current budget
    cityBudget += collectedAmount;
    std::cout << "Collected $" << collectedAmount << " in taxes. New city budget: $" << cityBudget << std::endl;
}

// @brief Allocates the collected tax revenue to various city projects, such as
///        infrastructure, healthcare, education, and other expenses.
void Taxes::allocation() {
    // Simulate allocation of collected tax revenue to various city projects
    float allocatedToInfrastructure = cityBudget * 0.25; // 25% to infrastructure
    float allocatedToHealthcare = cityBudget * 0.20;     // 20% to healthcare
    float allocatedToEducation = cityBudget * 0.15;      // 15% to education
    float allocatedToOther = cityBudget * 0.10;          // 10% to other expenses

    // Deduct the allocated amounts from the budget
    cityBudget -= (allocatedToInfrastructure + allocatedToHealthcare + allocatedToEducation + allocatedToOther);

    std::cout << "Allocated $" << allocatedToInfrastructure << " to infrastructure.\n";
    std::cout << "Allocated $" << allocatedToHealthcare << " to healthcare.\n";
    std::cout << "Allocated $" << allocatedToEducation << " to education.\n";
    std::cout << "Allocated $" << allocatedToOther << " to other expenses.\n";
    std::cout << "Remaining city budget after allocation: $" << cityBudget << std::endl;
}

/// @brief Analyzes the impact of the current tax rate on citizen satisfaction.
///        Provides feedback based on the tax rate's effect on satisfaction.
void Taxes::impact() {
    // Analyze the impact of the current tax rate on citizen satisfaction
    float impactScore = 100.0f - (taxRate * 100.0f); // Example: higher tax rate decreases satisfaction
    if (impactScore < 50.0f) {
        std::cout << "Warning: High tax rate is negatively impacting citizen satisfaction!\n";
    } else if (impactScore < 75.0f) {
        std::cout << "Moderate tax rate. Some citizens are affected, but satisfaction is acceptable.\n";
    } else {
        std::cout << "Low tax rate. Citizens are satisfied with the current tax policy.\n";
    }
    std::cout << "Citizen satisfaction impact score: " << impactScore << "/100\n";
}

/// @brief Sets the tax rate to a specified value.
/// @param n The new tax rate to set.
void Taxes::setTaxRate(float n){
    taxRate = n;
}

/// @brief Retrieves the current tax rate.
/// @return The current tax rate as a float.
float Taxes::getTaxRate(){
    return taxRate;
}

// /// @brief Restores the tax rate from a specified TaxMemento object.
// /// @param n A pointer to the TaxMemento object containing the saved state.
// void Taxes::setTaxRate(float newRate) {
//     taxRate = newRate;
// }

// // @brief Creates a memento object that captures the current state of the Taxes instance.
// /// @return A pointer to a new TaxMemento object representing the current state.
// TaxMemento* Taxes::createMemento() {
//     return new TaxMemento(this);
// }

/// @brief Restores the tax rate from a specified TaxMemento object.
/// @param n A pointer to the TaxMemento object containing the saved state.
void Taxes::reinstateMemento(TaxMemento* n){
    taxRate = n->getState()->getTaxRate();
}