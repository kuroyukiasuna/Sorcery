#include "disenchant.h"
#include "playboard.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

Disenchant::Disenchant():
        Spell("Disenchant","Destroy the top enchantment of target minion", 1, true){}

void Disenchant::notify(PlayBoard *pb, int player,int target) {
    unique_ptr<Cards> temp(nullptr);
    if(player == 2){
        pb->player2->playerboard[target]->decoration.pop_back();
        if(pb->player2->playerboard[target]->getDef() <= 0){
            pb->removeFromBoard(pb->player2->getName(), target).swap(temp);
            pb->player2->addTo("graveyard", temp);
        }
    }else{
        pb->player1->playerboard[target]->decoration.pop_back();
        if(pb->player1->playerboard[target]->getDef() <= 0){
            pb->removeFromBoard(pb->player1->getName(), target).swap(temp);
            pb->player1->addTo("graveyard", temp);
        }
    }
}
