#include "potionseller.h"
#include "playboard.h"
#include <string>

using namespace std;

PotionSeller::PotionSeller():
        Minions("Potion Seller","At the end of your turn, all your minions gain +0/+1.", 2, 1, 3, 0, 1){}

void PotionSeller::notify(PlayBoard *pb, int player,int target) {
    if(player == 1){
        for(int i = 0; i < pb->player1->playerboard.size(); i++){
            pb->player1->playerboard[i]->changeDef(1);
        }
    }else{
        for(int i = 0; i < pb->player2->playerboard.size(); i++){
            pb->player2->playerboard[i]->changeDef(1);
        }
    }
}

SubscriptionType PotionSeller::subType() const{
    return SubscriptionType::TurnEnd;
}