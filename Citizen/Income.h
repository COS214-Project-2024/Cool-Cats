#ifndef INCOME_H
#define INCOME_H

#include <array>

class Income
{
    public:
        Income(double lowest, double highest, float taxRate, float utilityCharge);
        std::array<double, 2> getRange();
        float getTaxRate();
        void setTaxRate(float taxRate);
        float getUtilityCharges();
        void setUtilityCharges(float newUtilityCharge);
        ~Income();

    private:
        double lowest;
        double highest;
        float taxRate;
        float utilityCharge;
};
#endif