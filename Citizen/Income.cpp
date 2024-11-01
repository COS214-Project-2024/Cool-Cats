#include <iostream>
#include <array>

#include "Income.h"

/// @brief Creates a new Income object, stored by the citizens
/// @param lowest the lowest threshold for the type of citizen 
/// @param hightest the highest threshold for the type of citizen
/// @param taxRate the taxRate for the citizen, expressed as a percentage
Income::Income(double lowest, double highest, float taxRate, float utilityCharge)
{
    if(lowest < 0)
    {
        this->lowest = 0;

    }
    else
    {
        this->lowest = lowest;
    }

    if(highest < 0)
    {
        this->highest = 0;
    }
    else
    {
        this->highest = highest;
    }

    if(taxRate < 0 || taxRate > 100)
    {
        this->taxRate = 0;
    }
    else
    {
        this->taxRate = taxRate;
    }
    
}

/// @brief Returns the range of income threshold for the type of citizen in an array
/// @return The lowest and highest income depending on the type of citizen
std::array<double, 2> Income::getRange()
{
    return {lowest, highest};
}

/// @brief Returns the tax rate depending on the citizen type
/// @return the tax rate as a percentage
float Income::getTaxRate()
{
    return taxRate;
}

/// @brief Changes the tax rate to the new tax rate parsed in, tax rate can only be between 0 and 100
/// @param taxRate the new tax rate, a number between 0 and 100 
void Income::setTaxRate(float taxRate)
{
    if(taxRate < 0 || taxRate > 100)
    {
        return;
    }
    this->taxRate = taxRate;
}

Income::~Income()
{
    
}