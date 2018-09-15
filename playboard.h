#ifndef _PLAYBOARD_H
#define _PLAYBOARD_H
#include "player.h"
#include "subscriptions.h"
#include "display.h"
#include <string>
#include <vector>
#include <memory>
class PlayBoard {




public:
    Player* player1;
    Player* player2;
    bool testing;
    std::unique_ptr<Display> td;


    PlayBoard(Player* player1, Player* player2);
    ~PlayBoard();
    void notifyObservers(SubscriptionType T, Player* player, int p, int target);
    Player* getAP();
    Player* getNAP();
    void addToBoard(const std::string name, std::unique_ptr<Cards> &card);
    std::unique_ptr<Cards> removeFromBoard(const std::string &name, int i);
    void playCard(int i);
    void playCard(int i,int p ,int t);
    void use(int i);
    void use(int i,int p ,int t);
    void changeTurn();
    void attack(int i);
    void attack(int i, int t);
    std::string isWon();
    void damageMinion(const std::string &name, int i, int amount);

    //test
    void drawBoard();
    void drawHand();
};
#endif
