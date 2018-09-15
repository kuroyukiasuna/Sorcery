#include "auraofpower.h"
#include "playboard.h"
#include <string>

using namespace std;

AuraOfPower::AuraOfPower():
        Rituals("Aura of Power","Whenever a minion enters play under your control, it gains +1/+1", 1, 4, 1, 1){}

void AuraOfPower::notify(PlayBoard *pb, int player, int target) {
    if (this->getDef() >= this->getCoA()) {
        if (player == 1) {
            if (target >= 0 && target <= pb->player1->playerboard.size()) {
                this->changeDef(-this->getCoA());
                pb->player1->playerboard[target]->changeAtk(1);
                pb->player1->playerboard[target]->changeDef(1);
            }
        } else {
            if (target >= 0 && target <= pb->player2->playerboard.size()) {
                this->changeDef(-this->getCoA());
                pb->player2->playerboard[target]->changeAtk(1);
                pb->player2->playerboard[target]->changeDef(1);
            }
        }
    }
}


SubscriptionType AuraOfPower::subType() const{
    return SubscriptionType::AllyMinionsEnter;
}