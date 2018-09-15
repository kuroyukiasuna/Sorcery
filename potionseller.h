#ifndef _POTIONSELLER_H
#define _POTIONSELLER_H
#include "minions.h"
#include <string>

class PotionSeller : public Minions {
public:
    PotionSeller();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;

};


#endif
