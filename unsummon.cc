#include "unsummon.h"
#include "playboard.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

Unsummon::Unsummon():
        Spell("Unsummon","Return target minion to its owner's hand", 1, true){}

void Unsummon::notify(PlayBoard *pb, int player,int target) {
    unique_ptr<Cards> temp(nullptr);
    if(player == 2){
        pb->removeFromBoard(pb->player2->getName(), target).swap(temp);
        if(temp->getDef() < 1){
            while(temp->getDef() < 1){
                temp->changeDef(1);
            }
        }
        pb->player2->addTo("hand", temp);
    }else{
        pb->removeFromBoard(pb->player1->getName(), target).swap(temp);
        if(temp->getDef() < 1){
            while(temp->getDef() < 1){
                temp->changeDef(1);
            }
        }
        pb->player1->addTo("hand", temp);
    }
}

