#ifndef _UNSUMMON_H
#define _UNSUMMON_H
#include "spell.h"
#include <string>

class Unsummon : public Spell{
public:
    Unsummon();
    void notify(PlayBoard *pb, int player,int target) override;
};
#endif