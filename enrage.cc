#include "enrage.h"
Enrage::Enrage():
        Enchantments("Enrage","", 2){}

int Enrage::getAtk() const{ return 2; }

int Enrage::getDef() const{ return 0; }

int Enrage::getCoA() const{ return 0; }

int Enrage::getAct() const{ return 0; }
