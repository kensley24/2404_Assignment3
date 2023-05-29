#include "Entity.h"


Entity::Entity(char c, int i, const string& s, Location& l){
  id = c + to_string(i);
  name = s;
  setLocation(l);
  orders = new Queue();
}

Entity::~Entity(){
  delete location;
  delete orders;
}

void Entity::setLocation(Location& l){
  location = new Location(l.getX(), l.getY());
}


Order* Entity::getNextOrder(){
  if(orders->empty()){
    return nullptr;
  }
  return orders->popFirst();
}

bool Entity::addOrder(Order* order){
  return (orders->addLast(order));
}

void Entity::print() const{
  location->print();
  cout<<orders->size()<<endl;
  cout<<"id: "<<id<<endl;
  cout<<"name: "<<name<<endl;

}

bool Entity::equals(const string& id) const{
  if(this->id == id){
    return true;
  }
  return false;
}

int Entity::getNumOrders() const{
  return orders->size();
}

Location* Entity::getLocation() const{
  return location;
}
