#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
//#include "subscriptions.h"
#include <iostream>
#include <vector>
#include <string>

class TextDisplay {
  std::vector<std::vector<char>> theDisplay;
  std::string player1name;
  std::string player2name;
 public:
  TextDisplay(const std::string &player1name, const std::string &player2name);
  void notify(const std::string &type, const std::string &belongTo, const std::string &name, const std::string desc,
              int num, int left, int right, int cost, int CoA);
  /*SubscriptionType subType() const override;*/
  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
