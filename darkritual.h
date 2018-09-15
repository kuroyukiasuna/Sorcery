#ifndef _DARKRITUAL_H
#define _DARKRITUAL_H

#include "rituals.h"
#include <string>

class DarkRitual : public Rituals {
public:
    DarkRitual();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};


#endif
