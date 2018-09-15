#include "raisedead.h"
#include "playboard.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

RaiseDead::RaiseDead():
        Spell("Raise Dead","Resurrect the top minion in your graveyard and set its defence to 1", 1, false){}

void RaiseDead::notify(PlayBoard *pb, int player,int target) {
    unique_ptr<Cards> temp(nullptr);
        pb->getAP()->removeFrom("graveyard").swap(temp);
        if(temp->getDef() > 1){
            while(temp->getDef() != 1){
                temp->changeDef(-1);
            }
        }else {
            while (temp->getDef() != 1){
                temp->changeDef(1);
            }
        }
        pb->addToBoard(pb->getAP()->getName(), temp);
}
