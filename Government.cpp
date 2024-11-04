#include "Government.h"
#include "CityResourceMediator.h"
#include <iostream>
#include <algorithm>

/// @brief Constructs a Government object with a given ResourceMediator.
/// @param mediator A pointer to a ResourceMediator object used for managing resources. 
Government::Government(ResourceMediator* mediator)
{   this->mediator = mediator;
    budget = 10000;
    tax = new Taxes(0.10);
}

/// @brief Destructor for the Government class.
///        Cleans up resources allocated to mediator, tax, and tax mementos.
Government::~Government()
{   delete mediator;
    delete tax;
    tax = nullptr;

   
    for (auto& TaxMemento : taxMementos)
    {
        if (TaxMemento)
        {                   // Check for nullptr
            delete TaxMemento; 
            TaxMemento = nullptr;// Safely delete each pointer
        }
    }
    taxMementos.clear();
}

/// @brief Sets a new tax rate and updates the budget accordingly.
/// @param newRate The new tax rate to be set.
void Government::setTaxRate(float newRate)
{
    tax->setTaxRate(newRate);
    std::cout << "Tax rate set to: " << tax->getTaxRate() << std::endl;
    budget += tax->getTaxRate() * 1000;
}

/// @brief Collects tax from all citizens based on their income and adds it to the budget.
/// @param iterator An iterator for accessing all citizens.
void Government::collection(AllCitizenIterator *iterator)
{

    iterator->first();

    while (!iterator->isDone())
    {

        Citizen *citizen = iterator->currentItem();

        if (citizen)
        {
            budget += citizen->getIncome()->getRange()[1] * tax->getTaxRate();
        }

        iterator->next();
    }
}

/// @brief Implements a specified government policy.
/// @param policy The name or description of the policy to be implemented.
void Government::implementPolicy(const std::string &policy)
{
    std::cout << "Implementing policy: " << policy << std::endl;
}

/// @brief Retrieves the current budget of the government.
/// @return The current budget as a float.
float Government::getBudget() const
{
    return budget;
}

/// @brief Allocates a specified amount from the budget to city services.
/// @param amount The amount to allocate.
/// @details If the amount exceeds the current budget, an error message is displayed.
void Government::allocateBudget(float amount)
{
    if (amount > budget)
    {
        std::cout << "Insufficient budget to allocate." << std::endl;
    } else {
        budget -= amount;
        std::cout << "Allocated " << amount << " to city services. Remaining budget: " << budget << std::endl;
    }
}

/// @brief Enforces a specified government policy.
/// @param policy The name or description of the policy to be enforced.
void Government::enforcePolicy(const std::string& policy) {
    policies.push_back(policy);
    std::cout << "Enforcing policy: " << policy << std::endl;
}

/// @brief Requests a specified amount of a resource from the mediator.
/// @param resourceType The type of resource being requested.
/// @param amount The amount of the resource to request.
void Government::requestResource(const std::string& resourceType, double amount) {
    std::cout << "Requesting " << amount << " of " << resourceType << std::endl;
    mediator->requestResource(this, resourceType, amount);
}

/// @brief Revokes a specified government policy.
/// @param policy The name or description of the policy to be revoked.
void Government::revokePolicy(const std::string& policy) {
    auto it = std::find(policies.begin(), policies.end(), policy);
    if (it != policies.end()) {
        policies.erase(it);
        std::cout << "Revoked policy: " << policy << std::endl;
    } else {
        std::cout << "Policy not found: " << policy << std::endl;
    }
}

/// @brief Supplies a specified amount of a resource to the mediator.
/// @param resourceType The type of resource being supplied.
/// @param amount The amount of the resource to supply.
void Government::supplyResource(const std::string& resourceType, double amount) {
    std::cout << "Supplying " << amount << " of " << resourceType << std::endl;
    mediator->supplyResource(this, resourceType, amount);
}

/// @brief Sets a new Taxes object for the government based on another Taxes instance.
/// @param one A pointer to the Taxes object to copy.
void Government::setTaxRate(Taxes *one)
{
    tax = new Taxes(one->getTaxRate());
}

/// @brief Gets the current Taxes object associated with the government.
/// @return A pointer to the Taxes object.
Taxes *Government::getTax()
{
    return tax;
}

/// @brief Stores a TaxMemento object for later retrieval.
/// @param One A pointer to the TaxMemento object to store.
void Government::storeMemento(TaxMemento *One)
{
    if (One)
    {
        taxMementos.push_back(One);
    }
}

/// @brief Retrieves the most recently stored TaxMemento.
/// @return A pointer to the most recent TaxMemento, or nullptr if none exist.
TaxMemento *Government::getMemento()
{
    if (taxMementos.empty())
    {
        return nullptr;
    }
    return taxMementos.back();
}
