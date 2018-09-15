#include "cardcollection.h"
#include <string>
#include <vector>

using namespace std;

CardCollection::CardCollection(): size{0} {}

void CardCollection::putBack(unique_ptr<Cards> &other) {
    collection.emplace_back(nullptr);
    other.swap(collection[size]);
    size++;
}

unique_ptr<Cards> CardCollection::getFrom() {
    unique_ptr<Cards> temp (nullptr);
    size--;
    temp.swap(collection[size]);
    collection.pop_back();
    return temp;
}

unique_ptr<Cards> CardCollection::access(int i) {
    unique_ptr<Cards> temp (nullptr);
    size--;
    temp.swap(collection[i]);
    collection.erase(collection.begin()+i, collection.begin()+i+1);
    return temp;
}

int CardCollection::getSize() {
    return size;
}

string CardCollection::getType(int i){
    return collection[i]->getType();
}