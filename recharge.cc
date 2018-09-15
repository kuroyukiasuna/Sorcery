#include "recharge.h"
#include "playboard.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

Recharge::Recharge():
        Spell("Recharge","Your ritual gains 3 charges", 1, false){}

void Recharge::notify(PlayBoard *pb, int player,int target) {
    pb->getAP()->playerritual->changeDef(3);
}
