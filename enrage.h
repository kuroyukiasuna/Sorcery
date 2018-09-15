#ifndef _ENRAGE_H
#define _ENRAGE_H
#include "enchantments.h"


class Enrage : public Enchantments {
public:
    Enrage();
    int getAtk() const override;
    int getDef() const override;
    int getCoA() const override;
    int getAct() const override;
};
#endif
