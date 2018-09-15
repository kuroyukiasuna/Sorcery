#include <iostream>
#include "cards.h"
#include "playboard.h"
#include "player.h"
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) {
    string deck1 = "default.deck";
    string deck2 = "default.deck";
    string filename;
    bool init = false;
    bool testing = false;
    string player1n = "";
    string player2n = "";
    for(int i = 0; i < argc; i++){
        string temp = argv[i];
        if(temp == "-testing"){
            testing = true;
        }else if(temp == "-init"){
            init = true;
            i++;
            filename = argv[i];
        }else if(temp == "-deck1"){
            i++;
            deck1 = argv[i];
        }else if(temp == "-deck2"){
            i++;
            deck2 = argv[i];
        }
    }

    ifstream f{filename};
    string tempname;
    if(getline(f, tempname)){
        istringstream sass{tempname};
        sass >> player1n;
        getline(f, tempname);
        istringstream sbss{tempname};
        sbss >> player2n;
    }else{
        cout<<"Enter player1's name:"<<endl;
        cin>>player1n;
        cout<<"Enter player2's name:"<<endl;
        cin>>player2n;
    }

    string s;
    Player player1{player1n};
    Player player2{player2n};
    srand (time(NULL)); // set random seed;
    player1.testing = testing;
    player2.testing = testing;
    player1.makeDeck(deck1);
    player2.makeDeck(deck2);
    player1.setActive();
    PlayBoard pb{&player1, &player2};
    pb.testing = testing;
    player1.setBoard(&pb);
    player2.setBoard(&pb);
    pb.drawBoard();
    if(!init) {
        getline(cin, s);
    }
    while(true){
        string sss;
        if(init) {
            if(getline(f, sss)){
            }else if(getline(cin, sss)){
            }
        }else{
            getline(cin, sss);
        }
        istringstream ss(sss);
        ss>>s;

        if(s == "board"){
            pb.drawBoard();
        }else if(s == "hand"){
            pb.drawHand();
        }else if(s == "quit"){
            break;
        }else if(s == "inspect"){
            int i;
            ss >> i;
            pb.getAP()->inspectMinion(i - 1);
        }else if(s == "play"){
            int c;
            ss >> c;
            if(c >= 1 && c <= 5) {
                int p;
                if (ss >> p) {
                    int t;
                    string q;
                    ss>>q;
                    if ( q == "r") {
                        pb.playCard(c - 1, p, 5);
                    }else{
                        istringstream newss(q);
                        if(newss >> t) {
                            pb.playCard(c - 1, p, t - 1);
                        }
                    }
                } else {
                    pb.playCard(c - 1);
                }
            }else{
                cout<<"Invlide card number."<<endl;
            }
        }else if(s == "use"){
            int c;
            ss >> c;
            int p;
            if(ss >> p){
                int t;
                ss >> t;
                pb.use(c - 1, p, t - 1);
            }else {
                pb.use(c - 1);
            }

        }else if(s == "attack"){
            int c;
            ss >> c;
            int t;
            if(ss >> t){
             pb.attack(c - 1, t - 1);
            }else {
                pb.attack(c - 1);
                if (pb.isWon() != "None") {
                    cout << pb.isWon() << " " << "Wins!" << endl;
                    break;
                }
            }
        }else if(s == "end"){
            pb.changeTurn();
        }else if(s == "draw"){
            if(pb.testing){
                pb.getAP()->draw();
            }else{
                cout<<"only avaliable in testing mode."<<endl;
            }
        }else if(s == "discard"){
            if(pb.testing){
                int c;
                ss>>c;
                pb.getAP()->removeFromHand(c - 1);
            }else{
                cout<<"only avaliable in testing mode."<<endl;
            }
        }else if(s == "help"){
            cout<< "Commands:"<<endl;
            cout<< "help -- Display this message."<<endl;
            cout<<  "end -- End the current player’s turn."<<endl;
            cout<<  "quit -- End the game."<<endl;
            cout<<  "attack minion other-minion -- Orders minion to attack other-minion."<<endl;
            cout<<  "attack minion -- Orders minion to attack the opponent." <<endl;
            cout<<  "play card [target-player target-card] -- Play card,";
            cout<<  "optionally targeting target-card owned by target-player."<<endl;
            cout<<  "use minion [target-player target-card] -- Use minion’s special ability,";
            cout<<  " optionally targeting target-card owned by target-player. " << endl;
            cout<<  "inspect minion -- View a minion’s card and all enchantments on that minion." << endl;
            cout<<  "hand -- Describe all cards in your hand." <<endl;
            cout<<  "board -- Describe all cards on the board." << endl;
        }else{
            cout<<"invalid command! type help to see commands panel"<<endl;
        }
    }
}
