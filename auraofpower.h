#ifndef _AURAOFPOWER_H
#define _AURAOFPOWER_H

#include "rituals.h"
#include <string>


class AuraOfPower : public Rituals {
public:
    AuraOfPower();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;

};


#endif
