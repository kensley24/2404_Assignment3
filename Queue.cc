#include "Queue.h"

Queue::Queue()
: head(nullptr), tail(nullptr), qSize(0){
  //cout<<"in queue constructor"<<endl;
}

Queue::~Queue(){
  Node* currNode = head;
  Node* nextNode = NULL;

  while(currNode!=NULL){
      nextNode = currNode->next;
      delete currNode->data;
      delete currNode;
      currNode = nextNode;
  }

}

bool Queue::empty() const{
  if(qSize == 0){
    return true;
  }
  return false;
}

int Queue::size() const{
  return qSize;
}

Order* Queue::peekFirst() const{
  if(qSize <= 0){
    return nullptr;
  }

  return head->data;
}

Order* Queue::popFirst(){
  if(qSize <= 0){
    return nullptr;
  }
  Node* firstn = head;
  Order* firstd = head->data;
  qSize--;
  if(qSize == 0){
    head = nullptr;
    tail = nullptr;
  }
  else{
    head = head->next;
  }
  delete firstn;
  return firstd;
}

bool Queue::addLast(Order* order){
  Node* n = new Node();
  n->data = order;
  n->next = nullptr;

  if(qSize == 0){
    head = n;
    tail = n;
    qSize ++;
    return true;
  }

  tail->next = n;
  tail = n;
  qSize++;
  return true;
}

void Queue::print() const{
  cout<<"size: "<<qSize<<endl;
  Node* t = head;
  for(int i = 0; i < qSize; i++){
    t->data->print();
    t = t->next;
  }
}
