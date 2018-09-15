#ifndef _DISENCHANT_H
#define _DISENCHANT_H
#include "spell.h"
#include <string>

class Disenchant : public Spell {
public:
    Disenchant();
    void notify(PlayBoard *pb, int player,int target) override;
};
#endif
