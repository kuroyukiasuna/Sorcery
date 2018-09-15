#include "standstill.h"
#include "playboard.h"
#include <string>

using namespace std;

Standstill::Standstill():
        Rituals("Standstill","Whenever a minion enters play, destory it", 3, 4, 2, 1){}

void Standstill::notify(PlayBoard *pb, int player,int target){
    if(this->getDef() >= this->getCoA()) {
        unique_ptr<Cards> temp{nullptr};
        if(player == 2){
            pb->removeFromBoard(pb->player2->getName(), target).swap(temp);
            if(temp) {
                pb->player2->addTo("graveyard", temp);
                this->changeDef(-this->getCoA());
            }
        }else{
            pb->removeFromBoard(pb->player1->getName(), target).swap(temp);
            if(temp) {
                pb->player1->addTo("graveyard", temp);
                this->changeDef(-this->getCoA());
            }
        }
    }
}

SubscriptionType Standstill::subType() const{
    return SubscriptionType::MinionsEnter;
}
