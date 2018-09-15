#include "rituals.h"
#include <string>

using namespace std;

Rituals::Rituals(const string &name, const string &desc, int cost, int def, int CoA, int act):
        Cards("Ritual", name, desc, cost),def{def}, costOfAbility{CoA}, action{act}{}

//rest

void Rituals::changeAtk(int amount) {return;}
int Rituals::getAtk() const{return -1;}

int Rituals::getDef() const {
    return def;
}

int Rituals::getCoA() const{
    return costOfAbility;
}

int Rituals::getAct() const {return -1;}

bool Rituals::isActive() const{
    if(action <= 0)return false;
    return true;
}

void Rituals::changeDef(int amount){
    def += amount;
}

void Rituals::changeCoA(int amount){
    costOfAbility += amount;
}

void Rituals::changeAct(int amount){
    action += amount;
}

bool Rituals::isDead() {return false;}