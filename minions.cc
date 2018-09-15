#include "minions.h"
#include <string>

using namespace std;

Minions::Minions(const string &name, const string &desc, int cost, int atk, int def, int CoA, int act):
        Cards("Minion", name, desc, cost),atk{atk}, def{def}, costOfAbility{CoA}, action{act}{}

int Minions::getAtk() const{
    if(decoration.size() > 0){
        int temp = atk;
        for(int i = 0; i < decoration.size(); i++){
            if(decoration[i]->getAtk() == 1){
                temp += 2;
            }else if(decoration[i]->getAtk() == 2){
                temp *= 2;
            }
        }
        return temp;
    }else {
        return atk;
    }
}

int Minions::getDef() const{
    if(decoration.size() > 0){
        int temp = def;
        for(int i = 0; i < decoration.size(); i++){
            if(decoration[i]->getDef() == 1){
                temp += 2;
            }
        }
        return temp;
    }else {
        return def;
    }
}

int Minions::getCoA() const{
    if(decoration.size() > 0 && costOfAbility != 0){
        int temp = costOfAbility;
        for(int i = 0; i < decoration.size(); i++){
            if(decoration[i]->getCoA() == 1){
                temp += 2;
            }
        }
        return temp;
    }else {
        return costOfAbility;
    }
}


int Minions::getAct() const {
    return action;
}

bool Minions::isActive() const{
    if(action <= 0)return false;
    return true;
}

void Minions::changeAtk(int amount) {
    atk += amount;
}

void Minions::changeDef(int amount){
    def += amount;
}

void Minions::changeCoA(int amount) {
    costOfAbility += amount;
}

void Minions::changeAct(int amount) {
    action += amount;
}

bool Minions::isDead(){
    if(getDef() <= 0)return true;
    return false;
}