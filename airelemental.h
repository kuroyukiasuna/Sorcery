#ifndef _AIRELEMENTAL_H
#define _AIRELEMENTAL_H
#include "minions.h"
#include <string>

class AirElemental: public Minions{
public:
    AirElemental();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};
#endif
