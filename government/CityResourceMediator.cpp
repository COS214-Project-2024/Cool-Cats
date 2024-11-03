#include "CityResourceMediator.h"
#include "Government.h"
#include <iostream>

CityResourceMediator::CityResourceMediator()
    : energyAvailable(0), waterAvailable(0), materialsAvailable(0), budget(0) {}

void CityResourceMediator::coordinateWaterUsage(double amount) {
    if (waterAvailable >= amount) {
        waterAvailable -= amount;
        std::cout << "Coordinated water usage: " << amount << ". Water available: " << waterAvailable << std::endl;
    } else {
        std::cout << "Not enough water available to coordinate usage of " << amount << std::endl;
    }
}

void CityResourceMediator::coordinateEnergyDistribution(double amount) {
    if (energyAvailable >= amount) {
        energyAvailable -= amount;
        std::cout << "Coordinated energy distribution: " << amount << ". Energy available: " << energyAvailable << std::endl;
    } else {
        std::cout << "Not enough energy available to distribute " << amount << std::endl;
    }
}

void CityResourceMediator::coordinateMaterialUsage(double amount) {
    if (materialsAvailable >= amount) {
        materialsAvailable -= amount;
        std::cout << "Coordinated material usage: " << amount << ". Materials available: " << materialsAvailable << std::endl;
    } else {
        std::cout << "Not enough materials available to use " << amount << std::endl;
    }
}

void CityResourceMediator::manageBudget(double amount) {
    if (budget >= amount) {
        budget -= amount;
        std::cout << "Managed budget: " << amount << ". Budget remaining: " << budget << std::endl;
    } else {
        std::cout << "Not enough budget available to manage " << amount << std::endl;
    }
}

void CityResourceMediator::requestResource(Government* requester, const std::string& resourceType, double amount) {
    if (resourceType == "Energy") {
        coordinateEnergyDistribution(amount);
    } else if (resourceType == "Water") {
        coordinateWaterUsage(amount);
    } else if (resourceType == "Materials") {
        coordinateMaterialUsage(amount);
    } else if (resourceType == "Budget") {
        manageBudget(amount);
    }
}

void CityResourceMediator::supplyResource(Government* supplier, const std::string& resourceType, double amount) {
    if (resourceType == "Energy") {
        energyAvailable += amount;
        std::cout << "Supplied energy: " << amount << ". Energy available: " << energyAvailable << std::endl;
    } else if (resourceType == "Water") {
        waterAvailable += amount;
        std::cout << "Supplied water: " << amount << ". Water available: " << waterAvailable << std::endl;
    } else if (resourceType == "Materials") {
        materialsAvailable += amount;
        std::cout << "Supplied materials: " << amount << ". Materials available: " << materialsAvailable << std::endl;
    } else if (resourceType == "Budget") {
        budget += amount;
        std::cout << "Supplied budget: " << amount << ". Budget available: " << budget << std::endl;
    }
}

void CityResourceMediator::coordinateResources(const std::string& projectType, int materialsAmount, int energyAmount, int waterAmount) {
    std::cout << "Coordinating resources for project: " << projectType << std::endl;
    coordinateMaterialUsage(materialsAmount);
    coordinateEnergyDistribution(energyAmount);
    coordinateWaterUsage(waterAmount);
}