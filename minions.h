#ifndef _MINIONS_H
#define _MINIONS_H
#include "cards.h"
#include <string>

class Minions : public Cards{
    int atk;
    int def;
    int costOfAbility;
    int action;

public:
    Minions(const std::string &name, const std::string &desc, int cost, int atk, int def, int CoA, int act);
    int getAtk() const override;
    int getDef() const override;
    int getCoA() const override;
    int getAct() const override;
    bool isActive() const override;
    void changeAtk(int amount) override;
    void changeDef(int amount) override;
    void changeCoA(int amount) override;
    void changeAct(int amount) override;
    bool isDead() override;
    virtual void notify(PlayBoard *pb, int player,int target) override = 0; //also the notify method
    virtual SubscriptionType subType() const override = 0;
};
#endif
