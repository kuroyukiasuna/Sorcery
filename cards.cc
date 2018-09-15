#include "cards.h"
#include <string>

using namespace std;

Cards::Cards(const string &type, const string &name, const string &desc, int cost):
        type{type}, name{name}, description{desc}, cost{cost}{}

string Cards::getName() const {
    return name;
}

string Cards::getType() const {
    return type;
}

string Cards::getDescription() const{
    return description;
}

int Cards::getCost() const{
    return cost;
}