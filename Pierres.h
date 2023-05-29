#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include "Driver.h"
#include "Franchise.h"
#include <vector>

using namespace std;

class Pierres{
  public:

    Pierres();
    //have to delete the 2 vectors of pointers
    ~Pierres();
    //add a new driver to driversList vector
    bool addDriver(const string& name, const Location& l);
    //add new franchise to franchiseList vector
    bool addFranchise(const string& name, const Location& l);
    void printFranchises() const;
    void printDrivers() const;
    //make new order and add it to franchise closest to l Location
    bool takeOrder(const string& customerName, int menuItem, const Location& l);
    //find franchise with franchiseId and closest driver to franchiseId
    //transfer numOrders from franchiseId to driver
    bool driverPickup(const string& franchiseId, int numOrders);
    //find driver with driverId and deliver numOrders
    bool driverDeliver(const string& driverId, int numOrders);

  private:

    Driver* findClosestDriver(const Location& l);
    Franchise* findClosestFranchise(const Location& l);

    vector<Driver*> driversList;
    vector<Franchise*> franchiseList;

};

#endif
