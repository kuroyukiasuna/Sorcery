#ifndef _CARDS_H
#define _CARDS_H
#include <string>
#include <memory>
#include <vector>
#include "subscriptions.h"

class PlayBoard;

class Cards {
    std::string type;
    std::string name;
    std::string description;
    int cost;

public:
    std::vector<std::unique_ptr<Cards>> decoration;
    Cards(const std::string &type, const std::string &name,const std::string &desc, int cost);
    std::string getType() const;
    std::string getName() const;
    std::string getDescription() const;
    int getCost() const;
    virtual int getAtk() const = 0;
    virtual int getDef() const = 0;
    virtual int getCoA() const = 0;
    virtual int getAct() const = 0;
    virtual bool isActive() const = 0;
    virtual void changeAtk(int amount) = 0;
    virtual void changeDef(int amount) = 0;
    virtual void changeCoA(int amount) = 0;
    virtual void changeAct(int amount) = 0;
    virtual bool isDead() = 0;
    virtual void notify(PlayBoard* pb, int player ,int target) = 0; //the notifymethod
    virtual SubscriptionType subType() const = 0;
};

#endif