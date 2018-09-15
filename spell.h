#ifndef _SPELL_H
#define _SPELL_H
#include "cards.h"
#include <string>
class Spell: public Cards{
    bool requiresTarget;
public:
    Spell(const std::string &name,const std::string &desc, int cost, bool rt);
    virtual void notify(PlayBoard *pb, int player,int target) override = 0;

    //rest
    int getAtk() const override;
    int getDef() const override;
    int getCoA() const override;
    int getAct() const override;
    bool isActive() const override; //multiple usage
    void changeAtk(int amount) override;
    void changeDef(int amount) override;
    void changeCoA(int amount) override;
    void changeAct(int amount) override;
    bool isDead() override;
    SubscriptionType subType() const override;
};
#endif
