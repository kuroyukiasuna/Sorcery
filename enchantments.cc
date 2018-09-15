#include "enchantments.h"
#include <string>

using namespace std;

Enchantments::Enchantments(const string &name, const string &desc, int cost):
        Cards("Enchantment", name, desc, cost){}


bool Enchantments::isActive() const{
    return false;
}

void Enchantments::changeAtk(int amount) {
    return;
}

void Enchantments::changeDef(int amount){
    return;
}

void Enchantments::changeCoA(int amount) {
    return;
}

void Enchantments::changeAct(int amount) {
    return;
}

bool Enchantments::isDead(){
    return false;
}

void Enchantments::notify(PlayBoard *pb, int player,int target){return;}

SubscriptionType Enchantments::subType() const{return SubscriptionType::Non;}

