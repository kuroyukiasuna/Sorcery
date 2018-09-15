#ifndef _MAGICFATIGUE_H
#define _MAGICFATIGUE_H
#include "enchantments.h"

class MagicFatigue : public Enchantments {
public:
    MagicFatigue();
    int getAtk() const override;
    int getDef() const override;
    int getCoA() const override;
    int getAct() const override;
};


#endif
