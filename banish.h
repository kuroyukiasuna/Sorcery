#ifndef _BANISH_H
#define _BANISH_H
#include "spell.h"
#include <string>

class Banish : public Spell{
public:
    Banish();
    void notify(PlayBoard *pb, int player,int target) override;
};

#endif
