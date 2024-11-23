#ifndef LIST_DOB_H
#define LIST_DOB_H

struct Node2D {
  int data; // data to store in each node
  struct Node2D* next; // next node to point
  struct Node2D* prev; // previous node to point
};

struct ListDob {
  struct Node2D* begin; // begining of the List
  unsigned int numNodes; // number of nodes so far
};

void initListSim(struct ListDob*);
void push(struct ListDob*, int);
// void pop(struct ListDob*);
// void remove(struct ListDob*, unsigned int);
void clear(struct ListDob*);
unsigned int getNumNodes(struct ListDob*);
bool empty(struct Node2D*);
bool find(struct ListDob*, int);
void showItems(struct ListDob*);

#endif // LIST_DOB_H
