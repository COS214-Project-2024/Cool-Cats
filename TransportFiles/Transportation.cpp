#include "Transportation.h"

Transportation::Transportation(Transport* transport) {
    this->transport = transport;
}

Transportation::~Transportation() {
    delete this->transport;
}

void Transportation::travel(){
    transport->travel();
}
