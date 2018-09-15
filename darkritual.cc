#include "darkritual.h"
#include "playboard.h"
#include <string>

using namespace std;

DarkRitual::DarkRitual():
        Rituals("Dark Ritual","At the start of your turn, gain 1 magic", 0, 5, 1, 1){}

void DarkRitual::notify(PlayBoard *pb, int player,int target){
    if(this->getDef() >= this->getCoA()) {
        this->changeDef(-this->getCoA());
        if (this->isActive()) {
            pb->player1->changeMagic(1);
        } else {
            pb->player2->changeMagic(1);
        }
    }
}
SubscriptionType DarkRitual::subType() const{
    return SubscriptionType::TurnStart;
}