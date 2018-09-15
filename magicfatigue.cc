#include "magicfatigue.h"
MagicFatigue::MagicFatigue():
        Enchantments("Magic Fatigue","Enriched minion's activited ability costs 2 more", 0){}

int MagicFatigue::getAtk() const{ return 0; }

int MagicFatigue::getDef() const{ return 0; }

int MagicFatigue::getCoA() const{ return 1; }

int MagicFatigue::getAct() const{ return 0; }
