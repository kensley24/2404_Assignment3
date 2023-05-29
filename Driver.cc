#include "Driver.h"
#include <string>

int Driver::nextId = 0;

Driver::Driver(const string& name, Location l)
:Entity(code, ++nextId, name, l){
  
}

bool Driver::isFree() const{
  if(orders->size() == 0){
    return true;
  }
  return false;
}

void Driver::print() const{
  cout<<"*************************"<<endl;
  cout<<"Driver: "<<endl;
  Entity::print();
  cout<<"*************************"<<endl;
}
