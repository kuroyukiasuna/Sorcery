#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <vector>
#include <memory>
#include "cards.h"
#include "minions.h"
#include "spell.h"
#include "airelemental.h"
#include "earthelemental.h"
#include "banish.h"
#include "unsummon.h"
#include "raisedead.h"
#include "blizzard.h"
#include "appsummoner.h"
#include "massummoner.h"
#include "novpyro.h"
#include "bonegolem.h"
#include "potionseller.h"
#include "fireelemental.h"
#include "darkritual.h"
#include "recharge.h"
#include "auraofpower.h"
#include "standstill.h"
#include "enrage.h"
#include "giantstrength.h"
#include "disenchant.h"
#include "magicfatigue.h"
#include "haste.h"
#include "silence.h" //all the cards

class PlayBoard;

class Player {
    std::vector<std::unique_ptr<Cards>> deck;
    std::vector<std::unique_ptr<Cards>> graveYard;
    std::vector<std::unique_ptr<Cards>> hand;
    std::string name;
    int HP;
    int magic;
    bool active;
    PlayBoard* board;

public:
    std::vector<std::unique_ptr<Cards>> playerboard;
    std::unique_ptr<Cards> playerritual;
    bool testing;

    Player(const std::string &name);
    ~Player();
    void setBoard(PlayBoard* pb);
    void makeDeck(const std::string &file); //create the deck
    void addToDeck(const std::string &card); //used for generating the deck, tons of if-else
    void shuffle(); //shuffle the deck
    void setActive();
    bool isActive();
    void changeHP(int amount);
    void changeMagic(int amount);
    std::string getName();
    int getHP();
    int getMagic();
    std::string getType(int i);
    std::string getHandName(int i);
    std::unique_ptr<Cards> playCard(int i, int p, int t);
    void draw();
    void addTo(const std::string &place, std::unique_ptr<Cards> &other);
    std::unique_ptr<Cards> removeFrom(const std::string &place);
    int getHandNum();
    void removeFromHand(int i);

    //test
    void drawGY();
    void drawHand();
    void drawBoard(int p);
    void inspectMinion(int i);
};
#endif