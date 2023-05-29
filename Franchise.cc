#include "Franchise.h"

int Franchise::nextId = 0;

const string Franchise::menu[MENU_ITEMS] = {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};


Franchise::Franchise(const string& name, Location l): Entity(code, ++nextId, name, l){

}

void Franchise::printMenu(){
  for(int i = 0; i < MENU_ITEMS; i++){
    cout<<menu[i]<<endl;
  }
}

string Franchise::getMenu(int index){
  string returnV;
  if(index > MENU_ITEMS || index < 1){
    returnV = "unknown menu item";
  }
  else{
    returnV = menu[index-1];
  }
  return returnV;
}

void Franchise::print() const{
  cout<<"*************************"<<endl;
  cout<<"Franchise: "<<endl;
  Entity::print();
  cout<<"*************************"<<endl;
}
