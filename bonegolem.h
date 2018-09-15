#ifndef _BONEGOLEM_H
#define _BONEGOLEM_H
#include "minions.h"
#include <string>


class BoneGolem : public Minions{
public:
    BoneGolem();
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override;
};


#endif
