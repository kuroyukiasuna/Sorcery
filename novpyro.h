#ifndef _NOVPYRO_H
#define _NOVPYRO_H

#include "minions.h"
#include <string>


class NovPyro : public Minions {
public:
    NovPyro();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};


#endif
