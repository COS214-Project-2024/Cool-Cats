#include "ConcreteObserver.h"

ConcreteObserver::ConcreteObserver(Road* subject, Transport* transport) {
    this->subject = subject;
    this->transport = transport;
}

ConcreteObserver::~ConcreteObserver() {
    delete this->subject;
    delete this->transport;

}

void ConcreteObserver::update(){
    status = this->subject->checkState();
}

void ConcreteObserver::travel(){
    update();
    if(this->status == true){
        this->transport->travel();
    }
    else{
        std::cout << "We cannot travel down this road" << std::endl;
    }
}


