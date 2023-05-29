#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Location.h"
#include "Queue.h"
#include <vector>

using namespace std;

class Entity {

  public:
    //Char rep what type of entity it is(ex f for franchise)
    Entity(char c, int i, const string& s, Location& l);
    ~Entity();

    //location setter
    void setLocation(Location& l);

    //removes and returns order at front of Queue
    Order* getNextOrder();

    //adds order to back of Queue
    bool addOrder(Order* order);

    //prints location and #of orders -does not print order info
    void print() const;

    //if entity::id == id
    bool equals(const string& id) const;

    //get number of orders in the queue
    int getNumOrders() const;

    Location* getLocation() const;

  protected:
    string id;
    string name;
    Location* location;
    Queue* orders;

};

#endif
