#ifndef _SILENCE_H
#define _SILENCE_H
#include "enchantments.h"

class Silence : public Enchantments {
public:
    Silence();
    int getAtk() const override;
    int getDef() const override;
    int getCoA() const override;
    int getAct() const override;
};


#endif
