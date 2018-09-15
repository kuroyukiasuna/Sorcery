#ifndef _STANDSTILL_H
#define _STANDSTILL_H

#include "rituals.h"
#include <string>


class Standstill : public Rituals {
public:
    Standstill();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};


#endif
