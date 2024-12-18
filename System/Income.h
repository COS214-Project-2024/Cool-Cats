#ifndef INCOME_H
#define INCOME_H

#include <array>

class Income
{
    public:
        Income(double lowest, double highest, float taxRate);
        std::array<double, 2> getRange();
        float getTaxRate();
        void setTaxRate(float taxRate);
        ~Income();

    private:
        double lowest;
        double highest;
        float taxRate;
};
#endif