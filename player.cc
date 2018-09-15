#include "player.h"
#include "playboard.h"
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

Player::Player(const string &name):
        name{name}, HP{20}, magic{3}, active{false}, board{nullptr}, playerritual{nullptr}, testing{false}{}

Player::~Player(){
    board = nullptr;
}

void Player::setBoard(PlayBoard *pb) {
    board = pb;
}


void Player::makeDeck(const string &file){
    ifstream f{file};
    string cardName;
    while(getline(f, cardName)){
        istringstream ss{cardName};
        string cardName2;
        ss>>cardName2;
        while(ss>>cardName){
            cardName2 += " ";
            cardName2 += cardName;
        }
        addToDeck(cardName2);
    }
    if(!testing)shuffle();
    for(int i = 0; i < 5; i++){
        draw();
    }
} //mission2

void Player::shuffle(){
    int randnum;
    for(int i = 0; i < deck.size();i++){
        randnum = rand() % deck.size();
        if(randnum != i){
            deck[i].swap(deck[randnum]);
        }
    }
}

void Player::draw() {
    if(hand.size() < 5 && deck.size() > 0) {
        unique_ptr<Cards> temp (nullptr);
        temp.swap(deck[0]);
        deck.erase(deck.begin(), deck.begin() + 1);
        addTo("hand", temp);
    }
}


unique_ptr<Cards> Player::removeFrom(const string &place) {
    unique_ptr<Cards> temp (nullptr);
    if(place == "deck" && deck.size() != 0){
        temp.swap(deck[deck.size() - 1]);
        deck.pop_back();
    }else if(place == "graveyard" && graveYard.size() != 0){//textdisplay
        temp.swap(graveYard[graveYard.size() - 1]);
        graveYard.pop_back();
    }else if(place == "hand" && hand.size() != 0){//observer
        temp.swap(hand[hand.size() - 1]);
        hand.pop_back();
    }else if(place == "ritual"){
        temp.swap(playerritual);
    }
    return temp;
}

void Player::removeFromHand(int i){
    if(i >= 0 && i < hand.size()){
        hand.erase(hand.begin() + i, hand.begin() + i + 1);
    }else{
        cout<<"Invalid position."<<endl;
    }
}

void Player::addTo(const string &place, unique_ptr<Cards> &other) {
    if(place == "deck"){
        deck.emplace_back(nullptr);
        deck[deck.size() - 1].swap(other);
    }else if(place == "graveyard"){//textdisplay
        graveYard.emplace_back(nullptr);
        graveYard[graveYard.size() - 1].swap(other);
    }else if(place == "hand"){
        if(hand.size() < 5) {
            hand.emplace_back(nullptr);
            hand[hand.size() - 1].swap(other);
        }
    }else if(place == "ritual"){
        playerritual.swap(other);
    }
}

unique_ptr<Cards> Player::playCard(int i, int p, int t) {
    unique_ptr<Cards> temp(nullptr);
    if(hand[i]->getCost() <= magic || testing){
        string type = hand[i]->getType();
        if (type == "Spell" && hand[i]->isActive() && t == -1) {
            //target
            cout << "This spell requires a target." << endl;
        }else if(type == "Enchantment" && t == -1){
            cout<<"Requires a target"<<endl;
        }else if(type == "Spell" && hand[i]->getName() == "Raise Dead" && graveYard.size() == 0){
            cout<<"Cannot be played since graveyard is empty."<<endl;
        }else if(type == "Spell" && hand[i]->getName() == "Recharge" && !playerritual){
            cout<<"Cannot be played since you dont have a ritual."<<endl;
        }else if(type == "Spell" && hand[i]->getName() == "Unsummon"){
            changeMagic(- hand[i]->getCost());
	    temp.swap(hand[i]);
            hand.erase(hand.begin() + i, hand.begin() + i + 1);
            temp->notify(board,p,t);  
            unique_ptr<Cards> tep(nullptr);
            temp.swap(tep);
        }else{
            if(hand[i]->getCost() <= magic) {
                changeMagic(-hand[i]->getCost());
                temp.swap(hand[i]);
                hand.erase(hand.begin() + i, hand.begin() + i + 1);
            }else{
                cout<<"Not enough Magic!"<<endl;
            }
        }
    }else{
        cout<<"Not enough Magic!"<<endl;
    }
    return temp;
}

void Player::setActive(){
    active = !active;
}
bool Player::isActive(){
    return active;
}
void Player::changeHP(int amount){
    HP += amount;
}
void Player::changeMagic(int amount){
    magic += amount;
    if(magic < 0){
        magic = 0;
    }
}
string Player::getName(){
    return name;
}

int Player::getHP(){
    return HP;
}
int Player::getMagic(){
    return magic;
}
string Player::getType(int i){
    return hand[i]->getType();
}

string Player::getHandName(int i){
    return hand[i]->getName();
}

int Player::getHandNum() {
    return hand.size();
}


void Player::addToDeck(const string &card) {
    if(card == "Air Elemental"){
        deck.emplace_back(make_unique<AirElemental>());
    }else if(card == "Earth Elemental"){
        deck.emplace_back(make_unique<EarthElemental>());
    }else if(card == "Bone Golem"){
        deck.emplace_back(make_unique<BoneGolem>());
    }else if(card == "Fire Elemental"){
        deck.emplace_back(make_unique<FireElemental>());
    }else if(card == "Potion Seller"){
        deck.emplace_back(make_unique<PotionSeller>());
    }else if(card == "Novice Pyromancer"){
        deck.emplace_back(make_unique<NovPyro>());
    }else if(card == "Apprentice Summoner"){
        deck.emplace_back(make_unique<AppSummoner>());
    }else if(card == "Master Summoner"){
        deck.emplace_back(make_unique<MasSummoner>());
    }else if(card == "Banish"){
        deck.emplace_back(make_unique<Banish>());
    }else if(card == "Unsummon"){
        deck.emplace_back(make_unique<Unsummon>());
    }else if(card == "Recharge"){
        deck.emplace_back(make_unique<Recharge>());
    }else if(card == "Disenchant"){
        deck.emplace_back(make_unique<Disenchant>());
    }else if(card == "Raise Dead"){
        deck.emplace_back(make_unique<RaiseDead>());
    }else if(card == "Blizzard"){
        deck.emplace_back(make_unique<Blizzard>());
    }else if(card == "Giant Strength"){
        deck.emplace_back(make_unique<GiantStrength>());
    }else if(card == "Enrage"){
        deck.emplace_back(make_unique<Enrage>());
    }else if(card == "Haste"){
        deck.emplace_back(make_unique<Haste>());
    }else if(card == "Magic Fatigue"){
        deck.emplace_back(make_unique<MagicFatigue>());
    }else if(card == "Silence"){
        deck.emplace_back(make_unique<Silence>());
    }else if(card == "Dark Ritual"){
        deck.emplace_back(make_unique<DarkRitual>());
    }else if(card == "Aura of Power"){
        deck.emplace_back(make_unique<AuraOfPower>());
    }else if(card == "Standstill"){
        deck.emplace_back(make_unique<Standstill>());
    }else{}
}

void Player::drawBoard(int p) {
    board->td->notify("Player", name, "", HP, magic, 0, 0, p, 0);
   for(int i = 0; i < 5 ; i++){
        if(i < playerboard.size()){
            board->td->notify(playerboard[i]->getType(),
                              playerboard[i]->getName(),
                              playerboard[i]->getDescription(),
                              playerboard[i]->getAtk(),
                              playerboard[i]->getDef(),
                              playerboard[i]->getCost(),
                              playerboard[i]->getCoA(), p,i+1);
        }else{
            board->td->notify("Minion", "Dead", "", 0, 0, 0, 0, p, i+1);
        }
    }

    if(playerritual){
        board->td->notify(playerritual->getType(),
                          playerritual->getName(),
                          playerritual->getDescription(),
                          playerritual->getAtk(),
                          playerritual->getDef(),
                          playerritual->getCost(),
                          playerritual->getCoA(), p,0);
    }else{
        board->td->notify("Ritual", "Dead", "", 0,0, 0,0, p, 0);
    }
    if(graveYard.size() != 0){
        int gys = graveYard.size() - 1;
        board->td->notify(graveYard[gys]->getType(),
                          graveYard[gys]->getName(),
                          graveYard[gys]->getDescription(),
                          graveYard[gys]->getAtk(),
                          graveYard[gys]->getDef(),
                          graveYard[gys]->getCost(),
                          graveYard[gys]->getCoA(), p,6);
    }else{
        board->td->notify("Minion", "Dead", "", 0, 0, 0, 0, p, 6);
    }

}

void Player::drawHand() {
    for(int i = 0; i < hand.size(); i++){
        if(hand[i]->getName() == "Giant Strength"){
            board->td->addto(hand[i]->getType(),
                            hand[i]->getName(),
                            hand[i]->getDescription(),
                            0, 0,"+2","+2",
                            hand[i]->getCost(),
                            hand[i]->getCoA());

        }else if(hand[i]->getName() == "Enrage"){
            board->td->addto(hand[i]->getType(),
                            hand[i]->getName(),
                            hand[i]->getDescription(),
                            0, 0,"*2","",
                            hand[i]->getCost(),
                            hand[i]->getCoA());

        }else{
            board->td->addto(hand[i]->getType(),
                            hand[i]->getName(),
                            hand[i]->getDescription(),
                            hand[i]->getAtk(),
                            hand[i]->getDef(),"","",
                            hand[i]->getCost(),
                            hand[i]->getCoA());
        }
    }
}

void Player::inspectMinion(int i) {
    if(i >= 0 && i < playerboard.size()) {
        board->td->draw(playerboard[i]->getType(),
                        playerboard[i]->getName(),
                        playerboard[i]->getDescription(),
                        playerboard[i]->getAtk(),
                        playerboard[i]->getDef(), "", "",
                        playerboard[i]->getCost(),
                        playerboard[i]->getCoA());

        for (int j = 0; j < playerboard[i]->decoration.size(); j++) {
            if (playerboard[i]->decoration[j]->getName() == "Giant Strength") {
                board->td->addto(playerboard[i]->decoration[j]->getType(),
                                 playerboard[i]->decoration[j]->getName(),
                                 playerboard[i]->decoration[j]->getDescription(),
                                 0, 0, "+2", "+2",
                                 playerboard[i]->decoration[j]->getCost(),
                                 playerboard[i]->decoration[j]->getCoA());

            } else if (playerboard[i]->decoration[j]->getName() == "Enrage") {
                board->td->addto(playerboard[i]->decoration[j]->getType(),
                                 playerboard[i]->decoration[j]->getName(),
                                 playerboard[i]->decoration[j]->getDescription(),
                                 0, 0, "*2", "",
                                 playerboard[i]->decoration[j]->getCost(),
                                 playerboard[i]->decoration[j]->getCoA());

            } else {
                board->td->addto(playerboard[i]->decoration[j]->getType(),
                                 playerboard[i]->decoration[j]->getName(),
                                 playerboard[i]->decoration[j]->getDescription(),
                                 playerboard[i]->decoration[j]->getAtk(),
                                 playerboard[i]->decoration[j]->getDef(), "", "",
                                 playerboard[i]->decoration[j]->getCost(),
                                 playerboard[i]->decoration[j]->getCoA());
            }
        }
        board->td->drawV2();
        board->td->clear();
    }else{
        cout<<"Invalid position"<<endl;
    }
}

