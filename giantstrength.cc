#include "giantstrength.h"

GiantStrength::GiantStrength():
        Enchantments("Giant Strength","", 1){}

int GiantStrength::getAtk() const{ return 1; }

int GiantStrength::getDef() const{ return 1; }

int GiantStrength::getCoA() const{ return 0; }

int GiantStrength::getAct() const{ return 0; }
