#include "playboard.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

PlayBoard::PlayBoard(Player *player1, Player *player2):
        player1{player1}, player2{player2}, testing{false},
        td{make_unique<Display>(player1->getName(), player2->getName())}{}

PlayBoard::~PlayBoard() {
    player1 = nullptr;
    player2 = nullptr;
}

void PlayBoard::notifyObservers(SubscriptionType T, Player* player,int p, int target){
    for(int i = 0; i < player->playerboard.size();i++){
        if(T == SubscriptionType::EnemyMinionsLeave || T == SubscriptionType::AllyMinionsLeave) {
            if (player->playerboard[i]->subType() == T || player->playerboard[i]->subType() == SubscriptionType::MinionsLeave) {
                player->playerboard[i]->notify(this, p, target);
            }
        }else if(T == SubscriptionType::EnemyMinionsEnter || T == SubscriptionType::AllyMinionsEnter) {
            if (player->playerboard[i]->subType() == T || player->playerboard[i]->subType() == SubscriptionType::MinionsEnter) {
                cout<<"run"<<endl;
                player->playerboard[i]->notify(this, p, target);
            }
        }else{
            if (player->playerboard[i]->subType() == T) {
                player->playerboard[i]->notify(this, p, target);
            }
        }
    }
    if(player->playerritual) {
        if(T == SubscriptionType::EnemyMinionsLeave || T == SubscriptionType::AllyMinionsLeave) {
            if (player->playerritual->subType() == T || player->playerritual->subType() == SubscriptionType::MinionsLeave) {
                player->playerritual->notify(this, p, target);
            }
        }else if(T == SubscriptionType::EnemyMinionsEnter || T == SubscriptionType::AllyMinionsEnter) {
            if (player->playerritual->subType() == T || player->playerritual->subType() == SubscriptionType::MinionsEnter) {
                player->playerritual->notify(this, p, target);
            }
        }else{
            if (player->playerritual->subType() == T) {
                player->playerritual->notify(this, p, target);
            }
        }

    }
    //notify display
}

Player* PlayBoard::getAP(){
    if(player1->isActive())return player1;
    return player2;
}

Player* PlayBoard::getNAP(){
    if(player1->isActive())return player2;
    return player1;
}

void PlayBoard::playCard(int i){
    unique_ptr<Cards> temp(nullptr);
        if(i < getAP()->getHandNum() && i >= 0) {
            if (getAP()->getType(i) == "Minion" && getAP()->playerboard.size() == 5) {
                cout << getAP()->getName() << " has maximum number of minions on board." << endl;
            } else {
                getAP()->playCard(i, -1, -1).swap(temp);
            }
        }else{
            cout<<"Invalid Hand Card Number!"<<endl;
        }

    if(temp){
        if(temp->getType() == "Minion") {
            addToBoard(getAP()->getName(), temp);
        }else if(temp->getType() == "Ritual"){
            if(getAP()->getName() == player1->getName()){
                player1->addTo("ritual", temp);
            }else{
                temp->changeAct(-1);
                player2->addTo("ritual", temp);
            }
        }
    }
}


void PlayBoard::playCard(int i,int p ,int t){
    int player;
    if(p == 1){
        player = 1;
        if(!(t < player1->playerboard.size() && t >= 0)){
            if(!(getAP()->getHandName(i) == "Banish" && t == 5)) {
                cout << "Invalid Target!" << endl;
                return;
            }
        }else if(getAP()->getHandName(i) == "Disenchant" && player1->playerboard[t]->decoration.size() == 0){
            cout<< "Cannot be played."<<endl;
            return;
        }
    }else if(p == 2){
        player = 2;
        if(!(t < player2->playerboard.size() && t >= 0)){
            if(!(getAP()->getHandName(i) == "Banish" && t == 5)) {
                cout << "Invalid Target!" << endl;
                return;
            }
        }else if(getAP()->getHandName(i) == "Disenchant" && player2->playerboard[t]->decoration.size() == 0){
            cout<< "Cannot be played."<<endl;
            return;
        }
    }else{
        cout<<"Wrong player!"<<endl;
        return;
    }
    unique_ptr<Cards> temp(nullptr);
        if(i < getAP()->getHandNum() && i >= 0) {
            if (getAP()->getType(i) == "Spell") {
                getAP()->playCard(i, player, t);
            } else if(getAP()->getType(i) == "Enchantment"){
                getAP()->playCard(i, player, t).swap(temp);
            }else{
                cout<<"Invalid Card Type"<<endl;
            }
        }else{
            cout<<"Invalid Hand Card Number!"<<endl;
        }
    if(temp){
        if(player == 1){
            if(temp->getName() == "Haste"){
                player1->playerboard[t]->changeAct(1);
            }
            player1->playerboard[t]->decoration.emplace_back(nullptr);
            int s = player1->playerboard[t]->decoration.size() - 1;
            player1->playerboard[t]->decoration[s].swap(temp);
        }else{
            if(temp->getName() == "Haste"){
                player2->playerboard[t]->changeAct(1);
            }
            player2->playerboard[t]->decoration.emplace_back(nullptr);
            int s = player2->playerboard[t]->decoration.size() - 1;
            player2->playerboard[t]->decoration[s].swap(temp);
        }

    }
}

void PlayBoard::attack(int i){
        if(i >= 0 && i < getAP()->playerboard.size()) {
            if (getAP()->playerboard[i]->isActive()) {
                int amount = getAP()->playerboard[i]->getAtk();
                getNAP()->changeHP(-amount);
                //notify
                getAP()->playerboard[i]->changeAct(-1);
            } else {
                cout << "Not enough Actions!" << endl;
            }
        }else{
            cout<<"No minion at that position!"<<endl;
        }
}

void PlayBoard::attack(int i, int t){
        if(i >= 0 && i < getAP()->playerboard.size()) {
            if(t >= 0 && t < getNAP()->playerboard.size()) {
                if (getAP()->playerboard[i]->isActive()) {
                    int amount = getAP()->playerboard[i]->getAtk();
                    int amount2 = getNAP()->playerboard[t]->getAtk();
                    getAP()->playerboard[i]->changeAct(-1);
                    damageMinion(getNAP()->getName(), t, amount);
                    damageMinion(getAP()->getName(), i, amount2);
                    //notify
                } else {
                    cout << "Not enough Actions!" << endl;
                }
            }else{
                cout<<"No minion at enemy position!"<<endl;
            }
        }else{
            cout<<"No minion at that position!"<<endl;
        }
}

void PlayBoard::use(int i){
    if(i >= 0 && i < getAP()->playerboard.size()) {
        bool isSilence = false;
        for(int j = 0; j < getAP()->playerboard[i]->decoration.size(); j++){
            if(getAP()->playerboard[i]->decoration[j]->getCoA() == -1){
                isSilence = true;
                break;
            }
        }
        if (getAP()->getMagic() >= getAP()->playerboard[i]->getCoA() || testing) {
                if (getAP()->playerboard[i]->isActive()) {
                    if (getAP()->playerboard[i]->getName() == "Master Summoner" ||
                        getAP()->playerboard[i]->getName() == "Apprentice Summoner") {
                        if(!isSilence) {
                            if (getAP()->playerboard.size() < 5) {
                                getAP()->playerboard[i]->notify(this, -1, -1);
                            } else {
                                cout << "Cannot be played, maximum minions on board!" << endl;
                            }
                        }else{
                            cout<<"Minion is silenced!"<<endl;
                        }
                    } else {
                        cout << "Cannot use ability!" << endl;
                    }
                } else {
                    cout << "Not enough actions!" << endl;
                }

        }else {
            cout << "Not enough magic!" << endl;
        }
    }else{
        cout<<"Invlide position!"<<endl;
    }
}

void PlayBoard::use(int i,int p ,int t){
    if(i >= 0 && i < getAP()->playerboard.size()) {
        bool isSilence = false;
        for(int j = 0; j < getAP()->playerboard[i]->decoration.size(); j++){
            if(getAP()->playerboard[i]->decoration[j]->getCoA() == -1){
                isSilence = true;
                break;
            }
        }
        if (getAP()->getMagic() >= getAP()->playerboard[i]->getCoA() || testing) {
                if (getAP()->playerboard[i]->isActive()) {
                    if (getAP()->playerboard[i]->getName() == "Novice Pyromancer") {
                        if(!isSilence) {
                            int player;
                            if (p == 1) {
                                player = 1;
                                if (!(t < player1->playerboard.size() && t >= 0)) {
                                    cout << "Invalid Target!" << endl;
                                    return;
                                }
                            } else if (p == 2) {
                                player = 2;
                                if (!(t < player2->playerboard.size() && t >= 0)) {
                                    cout << "Invalid Target!" << endl;
                                    return;
                                }
                            } else {
                                cout << "Wrong player name!" << endl;
                                return;
                            }
                            getAP()->playerboard[i]->notify(this, player, t);
                        }else{
                            cout<<"Minion is Silenced!"<<endl;
                        }
                    } else {
                        cout << "Cannot use ability!" << endl;
                    }
                } else {
                    cout << "Not enough actions!" << endl;
                }

        }else {
            cout << "Not enough magic!" << endl;
        }
    }else{
        cout<<"Invlide position!"<<endl;
    }
}


void PlayBoard::changeTurn(){
      if(player1->isActive()){
          notifyObservers(SubscriptionType::TurnEnd, player1, 1, 0);
          notifyObservers(SubscriptionType::TurnStart,player2, 2, 0);
      }else{
          notifyObservers(SubscriptionType::TurnEnd,player2, 2, 0);
          notifyObservers(SubscriptionType::TurnStart, player1, 1, 0);
      }
      player1->setActive();
      player2->setActive();
      getAP()->changeMagic(1);
      getAP()->draw();
      for(int i = 0; i < getAP()->playerboard.size(); i++){
          if(getAP()->playerboard[i]->decoration.size() == 0) {
              if (!getAP()->playerboard[i]->isActive()) {
                  getAP()->playerboard[i]->changeAct(1);
              }
          }else{
              int limit = 0;
              for(int j = 0; j < getAP()->playerboard[i]->decoration.size(); j++){
                  limit += getAP()->playerboard[i]->decoration[j]->getAct();
              }
              limit++;
              while(getAP()->playerboard[i]->getAct() < limit){
                  getAP()->playerboard[i]->changeAct(1);
              }
          }
      }
    notifyObservers(SubscriptionType::All, player1, 0, 0);
    drawBoard();
}

string PlayBoard::isWon() {
    if(player1->getHP() <= 0){
        return player2->getName();
    }else if(player2->getHP() <= 0){
        return player1->getName();
    }else{
        return "None";
    }
}


void PlayBoard::damageMinion(const std::string &name, int i, int amount) {
    if(name == player1->getName()){
        if(i >= 0 && i < player1->playerboard.size()) {
            player1->playerboard[i]->changeDef(-amount);
            if (player1->playerboard[i]->isDead()) {
                unique_ptr<Cards> temp(nullptr);
                removeFromBoard(player1->getName(), i).swap(temp);
                player1->addTo("graveyard", temp);
                //detach
                //notify all
            }
        }
    }else{
        if(i >= 0 && i < player2->playerboard.size()) {
            player2->playerboard[i]->changeDef(-amount);
            if (player2->playerboard[i]->isDead()) {
                unique_ptr<Cards> temp(nullptr);
                removeFromBoard(player2->getName(), i).swap(temp);
                player2->addTo("graveyard", temp);
                //detach
                //notify all
            }
        }
    }
}

void PlayBoard::addToBoard(const std::string name, unique_ptr<Cards> &card){
    if(card->getType() == "Minion"){
        if(player1->getName() == name){
            if(player1->playerboard.size() < 5) {
                player1->playerboard.emplace_back(nullptr);
                player1->playerboard[player1->playerboard.size() - 1].swap(card);
                if(player1->isActive()){
                    notifyObservers(SubscriptionType::AllyMinionsEnter, player1,1 ,player1->playerboard.size()-1);
                    notifyObservers(SubscriptionType::EnemyMinionsEnter, player2,1 ,player1->playerboard.size()-1);
                }else{
                    notifyObservers(SubscriptionType::EnemyMinionsEnter, player2,1 ,player1->playerboard.size()-1);
                    notifyObservers(SubscriptionType::AllyMinionsEnter, player1,1 ,player1->playerboard.size()-1);
                }
            }
        }else{
            if(player2->playerboard.size() < 5) {
                player2->playerboard.emplace_back(nullptr);
                player2->playerboard[player2->playerboard.size() - 1].swap(card);
                if(player2->isActive()){
                    notifyObservers(SubscriptionType::AllyMinionsEnter, player2,2 ,player2->playerboard.size()-1);
                    notifyObservers(SubscriptionType::EnemyMinionsEnter, player1,2 ,player2->playerboard.size()-1);
                }else{
                    notifyObservers(SubscriptionType::EnemyMinionsEnter, player1,2 ,player2->playerboard.size()-1);
                    notifyObservers(SubscriptionType::AllyMinionsEnter, player2,2 ,player2->playerboard.size()-1);
                }
            }
        }
    }else if(card->getType() == "Ritual"){
        if(player1->getName() == name){
            player1->playerritual.swap(card);
            //notify display
        }else{
            player2->playerritual.swap(card);
            //notify display
        }
    }
}
unique_ptr<Cards> PlayBoard::removeFromBoard(const std::string &name, int i){
    unique_ptr<Cards> temp(nullptr);
    if(player1->getName() == name){
        if(i >= 0 && i < player1->playerboard.size()) {
            if (player1->isActive()) {
                notifyObservers(SubscriptionType::AllyMinionsLeave, player1, 1, player1->playerboard.size() - 1);
                notifyObservers(SubscriptionType::EnemyMinionsLeave, player2, 1, player1->playerboard.size() - 1);
            } else {
                notifyObservers(SubscriptionType::EnemyMinionsLeave, player2, 1, player1->playerboard.size() - 1);
                notifyObservers(SubscriptionType::AllyMinionsLeave, player1, 1, player1->playerboard.size() - 1);
            }
            temp.swap(player1->playerboard[i]);
            player1->playerboard.erase(player1->playerboard.begin() + i, player1->playerboard.begin() + i + 1);
        }

    }else{
        if(i >= 0 && i < player2->playerboard.size()) {
            if (player2->isActive()) {
                notifyObservers(SubscriptionType::AllyMinionsLeave, player2, 2, player2->playerboard.size() - 1);
                notifyObservers(SubscriptionType::EnemyMinionsLeave, player1, 2, player2->playerboard.size() - 1);
            } else {
                notifyObservers(SubscriptionType::EnemyMinionsLeave, player1, 2, player2->playerboard.size() - 1);
                notifyObservers(SubscriptionType::AllyMinionsLeave, player2, 2, player2->playerboard.size() - 1);
            }
            temp.swap(player2->playerboard[i]);
            player2->playerboard.erase(player2->playerboard.begin() + i, player2->playerboard.begin() + i + 1);
        }
    }
    if(temp){
        temp->decoration.clear();
    }
    return temp;
}

void PlayBoard::drawBoard() {
    player1->drawBoard(1);
    player2->drawBoard(2);
    cout<<*td<<endl;
    cout<<getAP()->getName()<<"'s"<<" turn"<<endl;
}

void PlayBoard::drawHand() {
    cout<<getAP()->getName()<<"'s hand"<<endl;
    getAP()->drawHand();
    td->drawV2();
    td->clear();
}