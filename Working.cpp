#include "Working.h"

Working::Working() {}

Working::~Working() {}

bool Working::request(){
    std::cout << "This road is usable to travel on" << std::endl;
    return true;
}
