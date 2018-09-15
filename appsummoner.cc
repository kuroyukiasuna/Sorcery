#include "appsummoner.h"
#include "airelemental.h"
#include "playboard.h"
#include <string>

using namespace std;

AppSummoner::AppSummoner():
        Minions("Apprentice Summoner","Summon a 1/1 air elemental", 1, 1, 1, 1, 1){}

void AppSummoner::notify(PlayBoard *pb, int player,int target) {
    this->changeAct(-1);
    pb->getAP()->changeMagic(-(this->getCoA()));
    unique_ptr<Cards> temp {make_unique<AirElemental>()};
    pb->addToBoard(pb->getAP()->getName(), temp);
}

SubscriptionType AppSummoner::subType() const{
    return SubscriptionType::Non;
}
