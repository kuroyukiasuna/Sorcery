#include "bonegolem.h"
#include "playboard.h"
#include <string>

using namespace std;

BoneGolem::BoneGolem():
        Minions("Bone Golem","Gain +1/+1 whenever a minion leaves play.", 2, 1, 3, 0, 1){}

void BoneGolem::notify(PlayBoard *pb, int player,int target) {
    this->changeAtk(1);
    this->changeDef(1);
}

SubscriptionType BoneGolem::subType() const{
    return SubscriptionType::MinionsLeave;
}