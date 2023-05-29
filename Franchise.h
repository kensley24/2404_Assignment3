#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "defs.h"

using namespace std;

class Franchise: public Entity{
  public:
     Franchise(const string& name = "name", Location l = Location());
     
     //class functions
     static void printMenu();
     static string getMenu(int index);

     //member functions
     void print() const;

  private:
    //class variables
    static const char code = 'F';
    static int nextId;
    static const string menu[MENU_ITEMS];


};

#endif
