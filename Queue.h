#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "Order.h"


using namespace std;

class Queue{
  //private by default
  class Node{

    public:
        Order* data;
        Node* next;
  };

  public:
    //initialize head and tail to nullptr
    Queue();
    //delete all nodes in queue
    ~Queue();

    bool empty() const;
    int size() const;

    //return order from first(if exists)
    Order* peekFirst() const;
    //return order from first and delete from queue
    Order* popFirst();
    //add order to back of queue
    bool addLast(Order* order);

    void print() const;

  private:
    Node* head;
    Node* tail;
    int qSize;

};

#endif
