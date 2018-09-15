#include "airelemental.h"
#include <string>

using namespace std;

AirElemental::AirElemental():
        Minions("Air Elemental","", 0, 1, 1, 0, 1){}

void AirElemental::notify(PlayBoard *pb, int player,int target) {
    return;
}

SubscriptionType AirElemental::subType() const{
    return SubscriptionType::Non;
}