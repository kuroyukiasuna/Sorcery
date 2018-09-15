#ifndef _BLIZZARD_H
#define _BLIZZARD_H
#include "spell.h"
#include <string>

class Blizzard : public Spell{
public:
    Blizzard();
    void notify(PlayBoard *pb, int player,int target) override;
};

#endif
