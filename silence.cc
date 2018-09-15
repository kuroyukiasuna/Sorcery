#include "silence.h"
Silence::Silence():
        Enchantments("Silence","Enriched Minion cannot use abilities", 1){}

int Silence::getAtk() const{ return 0; }

int Silence::getDef() const{ return 0; }

int Silence::getCoA() const{ return -1; }

int Silence::getAct() const{ return 0; }