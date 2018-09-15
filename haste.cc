#include "haste.h"

Haste::Haste():
        Enchantments("Haste","Enchanted minion gains +1 action each turn", 1){}

int Haste::getAtk() const{ return 0; }

int Haste::getDef() const{ return 0; }

int Haste::getCoA() const{ return 0; }

int Haste::getAct() const{ return 1; }
