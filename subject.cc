#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
#include <iostream>

using namespace std;

void Subject::attach(Observer *o) {
  observers.emplace_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
  for(auto obsvr : observers){
    if(obsvr->subType() == t){ //correct subscription type
      obsvr->notify(*this);
     }
  }
}

Subject::~Subject(){}

