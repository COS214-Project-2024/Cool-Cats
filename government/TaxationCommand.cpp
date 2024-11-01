#include "TaxationCommand.h"

TaxationCommand::TaxationCommand(Government& govt, float rate) : government(govt), taxRate(rate) {}

void TaxationCommand::execute() {
    government.setTaxRate(taxRate);
}
