#ifndef _RITUALS_H
#define _RITUALS_H
#include "cards.h"
#include <string>


class Rituals : public Cards{
    int def;
    int costOfAbility;
    int action;

public:
    Rituals(const std::string &name, const std::string &desc, int cost, int def, int CoA, int act);
    int getDef() const override;
    int getCoA() const override;
    bool isActive() const override;
    void changeDef(int amount) override;
    void changeCoA(int amount) override;
    void changeAct(int amount) override;
    virtual void notify(PlayBoard *pb, int player,int target) override = 0; //also the notify method
    virtual SubscriptionType subType() const override = 0;

    //useless
    int getAtk() const override;
    int getAct() const override;
    void changeAtk(int amount) override;
    bool isDead() override;
};


#endif
