#include "Order.h"
#include "Franchise.h"

Order::Order(const string& s, int i, const Location& loc)
:name(s), menuItem(i), deliveryLocation(loc){
}
Location* Order::getLocation(){
  return &deliveryLocation;
}
void Order::print() const{
  cout<<"menu item number "<<menuItem<<endl;
  cout<<Franchise::getMenu(menuItem)<<endl;
}
