#include "display.h"
#include <iostream>
using namespace std;

Display::Display(const string &player1name, const string &player2name) {
    v.emplace_back(CARD_TEMPLATE_BORDER);
    v.emplace_back(CARD_TEMPLATE_EMPTY);
    v.emplace_back(PLAYER_1_TEMPLATE);
    v[2] = display_player_card(1, player1name, 20, 3);
    v.emplace_back(CARD_TEMPLATE_EMPTY);
    for (int i = 0; i < 12 ; ++i) {
        v.emplace_back(CARD_TEMPLATE_BORDER);
    }
    v.emplace_back(CARD_TEMPLATE_EMPTY);
    v.emplace_back(PLAYER_2_TEMPLATE);
    v[17] = display_player_card(2, player2name, 20, 3);
    v.emplace_back(CARD_TEMPLATE_EMPTY);
    v.emplace_back(CARD_TEMPLATE_BORDER);
}

void Display::notify(const string &type, const string &name, const string &desc,
                int left, int right, int cost, int CoA, int player, int handNum) {
    if (type == "Player") {
        if (player == 1) { v[2] = display_player_card(1, name, left, right); }
        else { v[17] = display_player_card(2, name, left, right); }
    }
    else if (type == "Minion") {
       if (name == "Dead") {
           if(player == 1){
               if(handNum == 6){ v[4] = CARD_TEMPLATE_BORDER;}
               else{v[handNum + 4] = CARD_TEMPLATE_BORDER;}
           }else{
               if(handNum == 6){ v[19] = CARD_TEMPLATE_BORDER;}
               else{ v[handNum + 9] = CARD_TEMPLATE_BORDER;}
           }
       }
       else {
        if (desc == "") {
	  if (player == 1) {
            if (handNum == 6) { v[4] = display_minion_no_ability(name, cost, left, right); }
            else { v[handNum+4] = display_minion_no_ability(name, cost, left, right); }
          }
          else {
            if (handNum == 6) { v[19] = display_minion_no_ability(name, cost, left, right); }
            else { v[handNum+9] = display_minion_no_ability(name, cost, left, right); }
          }
       }
       else if (CoA == 0) {
           if (player == 1) {
             if (handNum == 6) { v[4] = display_minion_triggered_ability(name, cost, left, right, desc); }
             else { v[handNum+4] = display_minion_triggered_ability(name, cost, left, right, desc); }
           }
           else {
             if (handNum == 6) { v[19] = display_minion_triggered_ability(name, cost, left, right, desc); }
             else { v[handNum+9] = display_minion_triggered_ability(name, cost, left, right, desc); }
           }
       }
       else {
           if (player == 1) {
             if (handNum == 6) { v[4] = display_minion_activated_ability(name, cost, left, right, CoA, desc); }
             else { v[handNum+4] = display_minion_activated_ability(name, cost, left, right, CoA, desc); }
           }
           else {
             if (handNum == 6) { v[19] = display_minion_activated_ability(name, cost, left, right, CoA, desc); }
             else { v[handNum+9] = display_minion_activated_ability(name, cost, left, right, CoA, desc); }
           }
       }}
    }
    else {
      if (name == "Dead") {
          if(player == 1){
              v[0] = CARD_TEMPLATE_BORDER;
          }else{
              v[15] = CARD_TEMPLATE_BORDER;
          }
      }
      else {
        if (player == 1) { v[0] = display_ritual(name, cost, CoA, desc, right); }
        else { v[15] = display_ritual(name, cost, CoA, desc, right); }
      }}
}

ostream &operator<<(ostream &out, const Display &d) {
    out << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i < 165; ++i) { out << EXTERNAL_BORDER_CHAR_LEFT_RIGHT; }
    out << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;

    for (int i = 0; i < 11; ++i)  {
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for (int j = 0; j < 5; j++) {
            out << d.v[j][i];
        }
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        out << endl;
    }

    for ( int i = 0; i < 11; ++i) {
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for (int j = 5; j < 10; ++j) {
            out << d.v[j][i];
        }
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        out << endl;
    }
    
    for (unsigned int i = 0; i < CENTRE_GRAPHIC.size();  ++i) {
        out << CENTRE_GRAPHIC[i] << endl;
    }

    for (int i = 0; i < 11; ++i)  {
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for (int j = 10; j < 15; j++) {
            out << d.v[j][i];
        }
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        out << endl;
    }

    for (int i = 0; i < 11; ++i)  {
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for (int j = 15; j < 20; j++) {
            out << d.v[j][i];
        }
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        out << endl;
    }

    out << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (int i = 0; i < 165; ++i) { out << EXTERNAL_BORDER_CHAR_LEFT_RIGHT; }
    out << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT;
    return out;
}

void Display::draw(const string &type, const string &name, const string &desc,
                   int left, int right,const string &left2, const string &right2, int cost, int CoA) {
    vector<string> vs;
    if (type == "Minion") {
        if (desc == "") { vs = display_minion_no_ability(name, cost, left, right); }
        else if (CoA == 0) { vs = display_minion_triggered_ability(name, cost, left, right, desc); }
        else { vs = display_minion_activated_ability(name, cost, left, right, CoA, desc); }
    }
    else if (type == "Ritual") { vs = display_ritual(name, cost, CoA, desc, right); }
    else if (type == "Spell") { vs = display_spell(name, cost, desc); }
    else {
        if ( desc == "") { vs = display_enchantment_attack_defence(name,cost,desc, left2, right2);}
        else { vs = display_enchantment(name, cost, desc); }
    }
    for (unsigned int i = 0; i < vs.size();  ++i) {
        cout << vs[i] << endl;
    }
}

void Display::addto (const std::string &type, const std::string &name, const std::string &desc,
            int left, int right, const std::string &left2,const std::string &right2,int cost, int CoA){
    vector<string> vs;
    if (type == "Minion") {
        if (desc == "") { vs = display_minion_no_ability(name, cost, left, right); }
        else if (CoA == 0) { vs = display_minion_triggered_ability(name, cost, left, right, desc); }
        else { vs = display_minion_activated_ability(name, cost, left, right, CoA, desc); }
    }
    else if (type == "Ritual") { vs = display_ritual(name, cost, CoA, desc, right); }
    else if (type == "Spell") { vs = display_spell(name, cost, desc); }
    else {
        if ( desc == "") { vs = display_enchantment_attack_defence(name,cost,desc, left2, right2);}
        else { vs = display_enchantment(name, cost, desc); }
    }
    v2.emplace_back(vs);
}

void Display::clear(){
    v2.clear();
}
void Display::drawV2() {
    if(v2.size() != 0) {
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < v2.size(); j++) {
                cout << v2[j][i];
            }
            cout << endl;
        }
    }
}





            



          