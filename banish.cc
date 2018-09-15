#include "banish.h"
#include "playboard.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

Banish::Banish():
        Spell("Banish","Destroy target minion or ritual", 2, true){}

void Banish::notify(PlayBoard *pb, int player,int target) {
    if(target == 5){
        if(player == 2){
            pb->player2->removeFrom("ritual");
        }else{
            pb->player1->removeFrom("ritual");
        }

    }else{
        unique_ptr<Cards> temp{nullptr};
        if(player == 2){
            pb->removeFromBoard(pb->player2->getName(), target).swap(temp);
            pb->player2->addTo("graveyard", temp);
        }else{
            pb->removeFromBoard(pb->player1->getName(), target).swap(temp);
            pb->player1->addTo("graveyard", temp);
        }
    }
}