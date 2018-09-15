#ifndef _RAISEDEAD_H
#define _RAISEDEAD_H
#include "spell.h"
#include <string>

class RaiseDead : public Spell{
public:
    RaiseDead();
    void notify(PlayBoard *pb, int player,int target) override;
};

#endif