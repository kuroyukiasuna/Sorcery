#ifndef _CARDCOLLECTION_H
#define _CARDCOLLECTION_H
#include <vector>
#include <string>
#include <memory>
#include "cards.h"
class CardCollection {
    std::vector<std::unique_ptr<Cards>> collection;
    int size;

public:
    CardCollection();
    void putBack(std::unique_ptr<Cards> &other);
    std::unique_ptr<Cards> getFrom();
    std::unique_ptr<Cards> access(int i);
    int getSize();
    std::string getType(int i);
};
#endif
