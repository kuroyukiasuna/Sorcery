#ifndef _RECHARGE_H
#define _RECHARGE_H
#include "spell.h"
#include <string>



class Recharge : public Spell {
public:
    Recharge();
    void notify(PlayBoard *pb, int player,int target) override;
};


#endif
