#include "fireelemental.h"
#include "playboard.h"
#include <string>

using namespace std;

FireElemental::FireElemental():
        Minions("Fire Elemental","Whenever an opponent's minion enters play, deal 1 damage to it.", 2, 2, 2, 0, 1){}

void FireElemental::notify(PlayBoard *pb, int player,int target) {
    if(player == 1){
        pb->damageMinion(pb->player1->getName(), target, 1);
    }else{
        pb->damageMinion(pb->player2->getName(), target, 1);
    }
}

SubscriptionType FireElemental::subType() const{
    return SubscriptionType::EnemyMinionsEnter;
}
