#include "ConcreteObserver.h"

ConcreteObserver::ConcreteObserver(Road* subject, Transport* transport) {
    this->subject = subject;
    this->transport = transport;
    this->status = true;
}

ConcreteObserver::~ConcreteObserver() {
    delete this->subject;
    delete this->transport;

}

void ConcreteObserver::update(){
    status = this->subject->checkState();
}

void ConcreteObserver::travel(){
    if(this->status == true){
        this->transport->travel();
    }
    else{
        std::cout << "We cannot travel down this road" << std::endl;
    }
}


