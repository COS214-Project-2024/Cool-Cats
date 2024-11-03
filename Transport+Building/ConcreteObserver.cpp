#include "ConcreteObserver.h"

/// @brief Constructs a ConcreteObserver object with a specified road and transport.
/// @param subject A pointer to the Road object that this observer monitors.
/// @param transport A pointer to the Transport object that this observer controls.
ConcreteObserver::ConcreteObserver(Road* subject, Transport* transport) {
    this->subject = subject;
    this->transport = transport;
    this->status = true;
}

/// @brief Destructor for the ConcreteObserver object. Frees the associated road and transport objects.
ConcreteObserver::~ConcreteObserver() {
    delete this->subject;
    delete this->transport;
}

/// @brief Updates the observer's status based on the state of the monitored road.
void ConcreteObserver::update(){
    status = this->subject->checkState();
}

/// @brief Initiates travel with the associated transport if the road is passable.
/// Prints an error message if travel is not possible.
void ConcreteObserver::travel(){
    if(this->status == true){
        this->transport->travel();
        std::cout << "Going down " << this->subject->getName() << std::endl;
    }
    else{
        std::cout << "We cannot travel down this road" << std::endl;
    }
}
