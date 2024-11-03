#include <iostream>
#include <memory>
#include "Government.h"
#include "GovernmentInvoker.h"
#include "TaxationCommand.h"
#include "PolicyImplementationCommand.h"
#include "Materials.h"
#include "Energy.h"
#include "Water.h"
#include "CityResourceMediator.h"
#include "Taxes.h"
#include "TaxMemento.h"
#include "BudgetAllocationCommand.h"

void displayMenu() {
    std::cout << "\nCity Builder Simulation Menu:\n";
    std::cout << "1. Set Tax Rate\n";
    std::cout << "2. Implement Policy\n";
    std::cout << "3. Allocate Government Budget\n";
    std::cout << "4. Coordinate Resources for a Project\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    CityResourceMediator resourceMediator;
    Government government(&resourceMediator);
    GovernmentInvoker invoker;
    Materials materials(&resourceMediator);
    Energy energy(&resourceMediator);
    Water water(&resourceMediator);
    Taxes taxes(0.10f); // Initial tax rate
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: {  // Set Tax Rate
                float taxRate;
                std::cout << "Enter new tax rate (e.g., 0.15 for 15%): ";
                std::cin >> taxRate;

                taxes.setTaxRate(taxRate); // Update tax rate
                taxes.collection();        // Collect taxes
                taxes.allocation();        // Allocate collected taxes
                taxes.impact();            // Analyze the impact on citizens
                break;
            }
case 2: {  // Implement Policy
                std::string policy;
                std::cout << "Enter policy name (e.g., Green Energy Initiative): ";
                std::cin.ignore();  
                std::getline(std::cin, policy);
                
                auto policyCommand = std::make_unique<PolicyImplementationCommand>(nullptr, policy, &government);
                invoker.setCommand(std::move(policyCommand));
                invoker.executeCommand();
                break;
            }
            case 3: {  // Allocate Government Budget
                double amount;
                std::cout << "Enter amount to allocate from budget: ";
                std::cin >> amount;
                
                auto budgetCommand = std::make_unique<BudgetAllocationCommand>(nullptr, amount, &government);
                invoker.setCommand(std::move(budgetCommand));
                invoker.executeCommand();
                break;
            }
            case 4: {  // Coordinate Resources for a Project
                std::string projectType;
                int materialsAmount, energyAmount, waterAmount;
                
                std::cout << "Enter project name (e.g., Residential Expansion): ";
                std::cin.ignore();
                std::getline(std::cin, projectType);
                std::cout << "Enter amount of materials required: ";
                std::cin >> materialsAmount;
                std::cout << "Enter amount of energy required: ";
                std::cin >> energyAmount;
                std::cout << "Enter amount of water required: ";
                std::cin >> waterAmount;
                
                resourceMediator.coordinateResources(projectType, materialsAmount, energyAmount, waterAmount);
                break;
            }            case 5:
                std::cout << "Exiting the simulation.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select an option from the menu.\n";
        }
    }
    return 0;
}

