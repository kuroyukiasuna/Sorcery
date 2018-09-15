#ifndef _GIANTSTRENGTH_H
#define _GIANTSTRENGTH_H
#include "enchantments.h"


class GiantStrength : public Enchantments {
public:
    GiantStrength();
    int getAtk() const override;
    int getDef() const override;
    int getCoA() const override;
    int getAct() const override;
};
#endif
