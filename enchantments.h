#ifndef _ENCHANTMENTS_H
#define _ENCHANTMENTS_H
#include "cards.h"
#include <string>

class Enchantments : public Cards{
public:
    Enchantments(const std::string &name, const std::string &desc, int cost);
    virtual int getAtk() const override = 0;
    virtual int getDef() const override = 0;
    virtual int getCoA() const override = 0;
    virtual int getAct() const override = 0;
    bool isActive() const override;
    void changeAtk(int amount) override;
    void changeDef(int amount) override;
    void changeCoA(int amount) override;
    void changeAct(int amount) override;
    bool isDead() override;
    void notify(PlayBoard *pb, int player,int target) override;
    SubscriptionType subType() const override ;
};

#endif
