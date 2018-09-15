#include "spell.h"
#include <string>

using namespace std;

Spell::Spell(const string &name, const string &desc, int cost, bool rt):
        Cards("Spell", name, desc, cost), requiresTarget{rt}{}


//rest
int Spell::getAtk() const{return -1;}
int Spell::getDef() const {return -1;}
int Spell::getCoA() const {return -1;}
int Spell::getAct() const {return -1;}
bool Spell::isActive() const {return requiresTarget;}
void Spell::changeAtk(int amount) {return;}
void Spell::changeDef(int amount) {return;}
void Spell::changeCoA(int amount) {return;}
void Spell::changeAct(int amount) {return;}
bool Spell::isDead() {return false;}
SubscriptionType Spell::subType() const{
return SubscriptionType::Non;
}