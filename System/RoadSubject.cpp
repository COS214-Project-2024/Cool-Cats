#include "RoadSubject.h"

/// @brief Attaches an observer (transportation) to the road subject.
/// @param observer A pointer to the Transportation object to be added to the observer list.
void RoadSubject::attach(Transportation* observer){
    observerList.push_back(observer);
}

/// @brief Detaches an observer (transportation) from the road subject.
/// @param observer A pointer to the Transportation object to be removed from the observer list.
void RoadSubject::detach(Transportation* observer){
    observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
}

/// @brief Notifies all attached observers by calling their update function.
void RoadSubject::notify(){
    for (auto* observer : observerList) {
        if (observer) {
            observer->update();
        }
    }
}
