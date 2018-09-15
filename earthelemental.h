#ifndef _EARTHELEMENTAL_H
#define _EARTHELEMENTAL_H
#include "minions.h"
#include <string>

class EarthElemental: public Minions{
public:
    EarthElemental();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};

#endif
