#ifndef _FIREELEMENTAL_H
#define _FIREELEMENTAL_H
#include "minions.h"
#include <string>


class FireElemental : public Minions {
public:
    FireElemental();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};


#endif