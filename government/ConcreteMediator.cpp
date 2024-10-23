#include "ConcreteMediator.h"

ConcreteMediator::ConcreteMediator(){
std::cout << "GovernmentMediator created\n";
}
ConcreteMediator::~ConcreteMediator(){
    std::cout << "GovernmentMediator destroyed\n";
}

void ConcreteMediator::notify(GovernmentColleague* colleague){
 std::cout << "Colleagues notified\n";
}