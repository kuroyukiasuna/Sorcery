#ifndef _APPRENTICESUMMONER_H
#define _APPRENTICESUMMONER_H

#include "minions.h"
#include <string>

class AppSummoner: public Minions{
public:
    AppSummoner();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};

#endif
