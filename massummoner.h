#ifndef _MASSUMMONER_H
#define _MASSUMMONER_H

#include "minions.h"
#include <string>


class MasSummoner : public Minions{
public:
    MasSummoner();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;

};


#endif
