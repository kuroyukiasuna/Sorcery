#include "massummoner.h"
#include "airelemental.h"
#include "playboard.h"
#include <string>

using namespace std;

MasSummoner::MasSummoner():
        Minions("Master Summoner","Summon up to 3 1/1 air elementals", 3, 2, 3, 2, 1){}

void MasSummoner::notify(PlayBoard *pb, int player,int target) {
    int i = 0;
    this->changeAct(-1);
    pb->getAP()->changeMagic(-(this->getCoA()));
    while(pb->getAP()->playerboard.size() != 5 && i < 3) {
        unique_ptr<Cards> temp{make_unique<AirElemental>()};
        pb->addToBoard(pb->getAP()->getName(), temp);
        i++;
    }
}

SubscriptionType MasSummoner::subType() const{
    return SubscriptionType::Non;
}
