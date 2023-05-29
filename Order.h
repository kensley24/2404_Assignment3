#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class Order{
  public:
    Order(const string& s, int i, const Location& loc);
    Location* getLocation();
    void print() const;

  private:
    string name;
    int menuItem;
    Location deliveryLocation;

};

#endif
