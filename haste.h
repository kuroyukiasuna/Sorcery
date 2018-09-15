#ifndef _HASTE_H
#define _HASTE_H

#include "enchantments.h"


class Haste : public Enchantments {
public:
    Haste();
    int getAtk() const override;
    int getDef() const override;
    int getCoA() const override;
    int getAct() const override;
};


#endif
