#ifndef DISPLAY_H
#define DISPLAY_H
#include "ascii_graphics.h"
#include <iostream>

class Display {
    std::vector<card_template_t> v;
    std::vector<card_template_t> v2;
public:
    Display(const std::string &player1name, const std::string &player2name);
    void notify(const std::string &type, const std::string &name, const std::string &desc,
                int left, int right, int cost, int CoA, int player, int handNum);
    void draw (const std::string &type, const std::string &name, const std::string &desc,
                int left, int right, const std::string &left2,const std::string &right2,int cost, int CoA);
    void addto (const std::string &type, const std::string &name, const std::string &desc,
                int left, int right, const std::string &left2,const std::string &right2,int cost, int CoA);
    void clear();
    void drawV2();
    friend std::ostream & operator << (std::ostream &out, const Display &d);
};

#endif
