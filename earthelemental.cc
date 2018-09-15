#include "earthelemental.h"
#include <string>

using namespace std;

EarthElemental::EarthElemental():
        Minions("Earth Elemental","", 3, 4, 4, 0, 1){}

void EarthElemental::notify(PlayBoard *pb, int player,int target){
    return;
}

SubscriptionType EarthElemental::subType() const{
    return SubscriptionType::Non;
}

