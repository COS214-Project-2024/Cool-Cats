#include "RoadSubject.h"

void RoadSubject::attach(Transportation* observer){
    observerList.push_back(observer);
}

void RoadSubject::detach(Transportation* observer){
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer),observerList.end());
}

void RoadSubject::notify(){
    for (auto* observer : observerList) {
            if (observer) {
                observer->update();
            }
        }
}
