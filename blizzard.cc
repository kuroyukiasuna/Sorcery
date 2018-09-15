#include "blizzard.h"
#include "playboard.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

Blizzard::Blizzard():
        Spell("Blizzard","Deal 2 damage to all minions", 3, false){}

void Blizzard::notify(PlayBoard *pb, int player,int target) {
        for (int i = 0; i < pb->getAP()->playerboard.size();i++){
            if(pb->getAP()->playerboard[i]->getDef() <= 2) {
                pb->damageMinion(pb->getAP()->getName(), i, 2);
                i--;
            }else{
                pb->damageMinion(pb->getAP()->getName(), i, 2);
            }
        }
        for (int i = 0; i < pb->getNAP()->playerboard.size();i++){
            if(pb->getNAP()->playerboard[i]->getDef() <= 2) {
                pb->damageMinion(pb->getNAP()->getName(), i, 2);
                i--;
            }else{
                pb->damageMinion(pb->getNAP()->getName(), i, 2);
            }
        }
    }


