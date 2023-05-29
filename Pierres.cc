#include "pierres.h"

Pierres::Pierres(): driversList(), franchiseList(){

}

Pierres::~Pierres(){
  //cout<<"Deleting***************"<<endl;
  //cout<<"Drivers***"<<endl;
  for(auto driver = driversList.begin(); driver != driversList.end(); ++driver){
    //cout<<*driver->print()<<endl;
    delete *driver;
  }

  driversList.clear();
  //cout<<"franchises*****"<<endl;
  for(auto franchise = franchiseList.begin(); franchise != franchiseList.end(); ++franchise){
    //cout<<*franchise->print()<<endl;
    delete *franchise;
  }

  franchiseList.clear();


}

bool Pierres::addDriver(const string& name, const Location& l){
  driversList.push_back(new Driver(name, l));
  return true;
}

bool Pierres::addFranchise(const string& name, const Location& l){
  franchiseList.push_back(new Franchise(name, l));
  return true;
}

Franchise* Pierres::findClosestFranchise(const Location& l){
  if(franchiseList.size() == 0){
    return nullptr;
  }
  //cout<<"in find closest franchise"<<endl;
  Franchise* closest = franchiseList[0];

  for(int i = 1; i < franchiseList.size(); i++){
    if(closest->getLocation()->getDistance(l) > franchiseList[i]->getLocation()->getDistance(l)){
      closest = franchiseList[i];
    }
    //cout<<closest->getLocation()->getDistance(l)<<endl;
  }

  return closest;
}

Driver* Pierres::findClosestDriver(const Location& l){

  if(driversList.size() == 0){
    return nullptr;
  }
  //cout<<"in find closest driver"<<endl;
  Driver* closest = driversList[0];

  for(int i = 1; i < driversList.size(); i++){
    if(closest->getLocation()->getDistance(l) > driversList[i]->getLocation()->getDistance(l)){
      closest = driversList[i];
    }
    //cout<<closest->getLocation()->getDistance(l)<<endl;
  }

  return closest;

}

bool Pierres::takeOrder(const string& customerName, int menuItem, const Location& l){
  cout<<"TAKING ORDER FOR "<<customerName<<" at location ";
  l.print();
  cout<<endl;

  Order* newOrder = new Order(customerName, menuItem, l);
  Franchise* f = findClosestFranchise(l);
  if(f == nullptr){
    cout<<"there is no franchises available currently"<<endl;
    return false;
  }

  if(f->addOrder(newOrder)){
    f->print();
    cout<<"has your order"<<endl;
    return true;
  }
  cout<<"error: could not add order to franchise "<<endl;
  return false;
}


bool Pierres::driverPickup(const string& franchiseId, int numOrders){

  if(franchiseList.size() == 0 || driversList.size() == 0){
    cout<<"Error: one or both lists of franchises and drivers are empty, cannot perform delivery"<<endl;
    return false;
  }

  Franchise* currentFranchise = nullptr;
  for(int i = 0; i < franchiseList.size(); i++){
    if(franchiseList[i]->equals(franchiseId)){
      currentFranchise = franchiseList[i];
      break;
    }
  }

  if(currentFranchise == nullptr){
    cout<<"Error: could not find franchise with id "<<franchiseId<<endl;
    return false;
  }
  if(numOrders < 0){
    cout<<"invalid number of orders"<<endl;
    return false;
  }
  if(currentFranchise->getNumOrders() == 0){
    cout<<"Error: franchise with id "<<franchiseId<<" has no orders"<<endl;
    return false;
  }

  Location* currentLocation = currentFranchise->getLocation();

  Driver* closestDriver = findClosestDriver(*currentLocation);
  Location* currentDriverLocation = closestDriver->getLocation();
  delete currentDriverLocation;
  closestDriver->setLocation(*currentLocation);

  if(numOrders > currentFranchise->getNumOrders()){
    numOrders = currentFranchise->getNumOrders();
  }

  Order* orderToBeTransfered;

  for(int i = 0; i < numOrders; i++){
    orderToBeTransfered = currentFranchise->getNextOrder();
    if(orderToBeTransfered != nullptr){
      closestDriver->addOrder(orderToBeTransfered);
    }
  }

  closestDriver->print();
  cout<<"Has "<<numOrders<<" orders to deliver"<<endl;

  if(closestDriver->getNumOrders() >= numOrders){
    return true;
  }
  else{
    cout<<"something went wrong"<<endl;
    return false;
  }

}

bool Pierres::driverDeliver(const string& driverId, int numOrders){
  Driver* driver = nullptr;
  for(int i = 0; i < driversList.size(); i++){
    if(driversList[i]->equals(driverId)){
      driver = driversList[i];
    }
  }
  if(driver == nullptr){
    cout<<"There is no driver with id "<<driverId<<endl;
    return false;
  }

  if(numOrders < 0){
    cout<<"invalid number of orders"<<endl;
    return false;
  }

  if(driver->getNumOrders() == 0){
    cout<<"Driver with id "<<driverId<<" has no orders to deliver"<<endl;
    return false;
  }


  if(numOrders > driver->getNumOrders()){
    numOrders = driver->getNumOrders();
  }
  Order* currentOrder;
  Location* currentLocation;
  Location* oldLocation;
  for(int i = 0; i < numOrders; i++){
    currentOrder = driver->getNextOrder();
    cout<<"Delivering..."<<endl;
    cout<<"********************"<<endl;
    currentOrder->print();
    cout<<"to ";
    currentLocation = currentOrder->getLocation();
    currentLocation->print();
    cout<<endl;
    oldLocation = driver->getLocation();
    delete oldLocation;
    driver->setLocation(*currentLocation);
    delete currentOrder;
    cout<<"********************"<<endl;

  }

  return true;

}

void Pierres::printFranchises() const{
  if(franchiseList.size() == 0){
    cout<<"there is no franchises available"<<endl;
    return;
  }

  for(int i = 0; i < franchiseList.size(); i++){
    franchiseList[i]->print();
  }
  return;

}

void Pierres::printDrivers() const{
  if(driversList.size() == 0){
    cout<<"there is no drivers available"<<endl;
    return;
  }

  for(int i = 0; i < driversList.size(); i++){
    driversList[i]->print();
  }
  return;
}
