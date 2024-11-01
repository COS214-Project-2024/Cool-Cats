#include "Taxes.h"
#include "TaxMemento.h"
#include "Government.h"
#include <iostream>

int main()
{
    Government *one = new Government();

    Taxes *two;
    Taxes *three;

    two = new Taxes(5);
    one->setTaxRate(two);
    std::cout << one->getTax()->getTaxRate() << " is old tax \n";
    one->storeMemento(two->createMemento());
    three = new Taxes(6);
    one->setTaxRate(three);
    std::cout << one->getTax()->getTaxRate() << " is new tax \n";
    TaxMemento *mem = one->getMemento();
    three->reinstateMemento(mem);
    one->setTaxRate(three);
    std::cout << one->getTax()->getTaxRate() << " is old tax \n";

    delete three;
    delete two;
    delete one;

    return 0;
}
