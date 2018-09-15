#include "novpyro.h"
#include "playboard.h"
#include <string>

using namespace std;

NovPyro::NovPyro():
        Minions("Novice Pyromancer","Deal 1 damage to target minion", 1, 0, 1, 1, 1){}

void NovPyro::notify(PlayBoard *pb, int player,int target) {
    this->changeAct(-1);
    pb->getAP()->changeMagic(-(this->getCoA()));
    if(player == 2){
        pb->damageMinion(pb->player2->getName(), target, 1);
    }else{
        pb->damageMinion(pb->player1->getName(), target, 1);
    }
}

SubscriptionType NovPyro::subType() const{
    return SubscriptionType::Non;
}